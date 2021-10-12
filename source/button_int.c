/*****************************************************************************
* Copyright (C) 2021 by Taher Ujjainwala
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Taher Ujjainwala and the University of Colorado are not liable for
* any misuse of this material.
*
**************************************************************************/

/*************************
 *
 *
 *
 *    File name   : button_int.c
 *    Description : This file contains functions which Initializes the GPIO as Interrupt, Defines IRQ Handles.
 *    It also checks the button state and returns the flag value
 *
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Howdy Class lectures and Dean GPIO Input Section
 *
 *    Date  : 10/11/2021
 *
 *
 */

#include "MKL25Z4.h"
#include "button_int.h"

//Defines
#define SWITCH_PIN (3)    //Port D - Pin 3 (PD3)

//Defining the variable to read the press event
volatile int button_pressed = 0;

void Init_Switch()
{

	// Enable clock to port D
	SIM->SCGC5 |= SIM_SCGC5_PORTD_MASK;

	//Defining the MUX port as GPIO
	PORTD->PCR[SWITCH_PIN] &= ~PORT_PCR_MUX_MASK;
	PORTD->PCR[SWITCH_PIN] |= PORT_PCR_MUX(1);

	//Defining the Port Direction Register as INPUT
	GPIOD->PDDR &= ~(1 << SWITCH_PIN);

	//Defining the INPUT pin in PULL-UP mode
	PORTD->PCR[SWITCH_PIN] |= PORT_PCR_PE(1) | PORT_PCR_PS(1);

	//Interrupt on falling edge->Means Switch is connected with Pull-UP resistor
	PORTD->PCR[SWITCH_PIN]|=PORT_PCR_IRQC(10UL);

	//Setting interrupt priority
	NVIC_SetPriority(PORTD_IRQn,4);

	//Enabling the interrupt
	NVIC_EnableIRQ(PORTD_IRQn);

}


void PORTD_IRQHandler()
{
	button_pressed = 1;
	PORTD->ISFR&=(1<<SWITCH_PIN);						//clearing interrupt flag
}


/*Returns current switch state*/
int check_switch_pressed()
{
	int switch_state = button_pressed;
	NVIC_DisableIRQ(PORTD_IRQn);				//Disabling the interrupt in ISR
	button_pressed = 0;

	NVIC_EnableIRQ(PORTD_IRQn);					//Enabling the interrupt
	return switch_state;						//Returning the state for further process
}
