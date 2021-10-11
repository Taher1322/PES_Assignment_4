/*************************
 *
 *
 *
 *    File name   : Timer.h
 *    Description : This file contains all the functions declaration which are used in Timer.c to Implement Systick
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Alexander Dean
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef TIMER_H_
#define TIMER_H_

//Including the Header files required for operation


//Definitions
typedef uint32_t ticktime_t; // time since boot, in sixteenths of a second
//Loading the RELOAD value as 30000 which means every 10ms interrupt will be generated.
//Logic working 48Mhz/16 = 3Mhz --> 1second --> So for 10ms It will be 30000 using simple cross multiplication method
#define CLOCK (30000)

/*************************************************************************************************************
 *
 * Name :		  	void init_systick()
 *
 *
 *
 * Description :	This function initializes the Timer which generates Interrupt every 10ms
 * It defines all the reload clock, interrupt priority, clock and starts the timer
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void init_systick();

/*************************************************************************************************************
 *
 * Name :		  	ticktime_t now()
 *
 *
 *
 * Description :	This function returns the time in seconds since the hardware powered on (startup)
 *
 *
 * Inputs: NONE
 *
 * Return: Returns the time in seconds since boot
 *************************************************************************************************************/

ticktime_t now();

/*************************************************************************************************************
 *
 * Name :		  	void reset_timer()
 *
 *
 *
 * Description :	This function resets the timer to zero without affecting the now() values
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void reset_timer();


/*************************************************************************************************************
 *
 * Name :		  	ticktime_t get_timer()
 *
 *
 *
 * Description :	This function returns the time since the last call to reset_timer()
 *
 *
 * Inputs: NONE
 *
 * Return: Ticks since last call to reset_timer()
 *************************************************************************************************************/
ticktime_t get_timer();

/*************************************************************************************************************
 *
 * Name :		  	void SysTick_Handler()
 *
 *
 *
 * Description :	This function is ISR for 10ms timer defined. It increments the ticks every 10ms
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void SysTick_Handler();

/*************************************************************************************************************
 *
 * Name :		  	void delay(int count)
 *
 *
 *
 * Description :	This function generates delay using Systick Timer
 *
 *
 * Inputs: Count
 *
 * Return: NONE
 *************************************************************************************************************/
void delay(int count);
#endif /* TIMER_H_ */
