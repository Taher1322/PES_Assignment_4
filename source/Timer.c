/*************************
 *
 *
 *
 *    File name   : Timer.c
 *    Description : This file Initialized the Slider and is called to read the value of the sliders
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Alexander Dean
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


ticktime_t now()
{
	return timer_start;
}

void reset_timer()
{
	reset_tim_value = now();
	init_systick();
}

ticktime_t get_timer()
{
	return (timer_start - reset_tim_value);
}

void SysTick_Handler()
{
	timer_start++;
}

void delay(int count){
	reset_timer();

	int current_time;
	current_time = get_timer();

	while (current_time!=count)
		current_time = get_timer();
}

#endif /* TIMER_C_ */
