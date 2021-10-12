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
 *    File name   : Timer.c
 *    Description : This file defines the functions to reset timer, start timer, get current time since start using Systick Timer
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Howdy lectures and Alexander Dean Systick Timer section
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef TIMER_C_
#define TIMER_C_

//Including the Header files required for operation
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "core_cm0plus.h"
#include "Timer.h"

//Defining variables to read the time and reset the timer value
volatile ticktime_t timer_start;
volatile ticktime_t reset_tim_value;


void init_systick() 										// initialize the timing system
{
	SysTick->LOAD  = CLOCK;              					// set reload register
	NVIC_SetPriority (SysTick_IRQn, 3); 					// set Priority for Systick Interrupt
	SysTick->VAL   = 0;                                     // Load the SysTick Counter Value
	SysTick->CTRL  = SysTick_CTRL_TICKINT_Msk   |
                   SysTick_CTRL_ENABLE_Msk;                 // Enable SysTick IRQ and SysTick Timer
}


//Returns the time since boot
ticktime_t now()
{
	return timer_start;
}

//Resets the timer to 0 without affecting the now() values
void reset_timer()
{
	reset_tim_value = now();
	init_systick();
}

//Returns Ticks since the last call to reset_timer()
ticktime_t get_timer()
{
	return (timer_start - reset_tim_value);
}

//Timer interrupt that is called every 10ms
void SysTick_Handler()
{
	timer_start++;
}

//Delay functions - Not used anywhere in code
void delay(int count){
	reset_timer();

	int current_time;
	current_time = get_timer();

	while (current_time!=count)
		current_time = get_timer();
}

#endif /* TIMER_C_ */
