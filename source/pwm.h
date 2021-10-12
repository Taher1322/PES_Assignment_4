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
 *    File name   : pwm.h
 *    Description : This file contains all the functions declaration which are used in pwm.c to PWM functions for RGB LED
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Alexander Dean PWM section
 *
 *    Date  : 10/10/2021
 *
 *
 */
#ifndef PWM_H_
#define PWM_H_

#define RED_LED_POS (18)					//Defining the RED led on Port B - Pin 18
#define GREEN_LED_POS (19)					//Defining the GREEN led on Port B - Pin  19
#define BLUE_LED_POS (1)					//Defining the BLUE led on Port D - Pin 1
#define PWM_PERIOD (48000)					//Defining the PWM period
#define BRIGTHNESS (255)					//PWM value for Max Brightness


/*************************************************************************************************************
 *
 * Name :		  	Init_Red_PWM(uint16_t period)
 *
 *
 *
 * Description :	This function initializes Clock, MUX Port, Timer, Reload values, Clock Prescaler, and Initial Duty Cycle
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void Init_Red_LED_PWM(uint16_t period);

/*************************************************************************************************************
 *
 * Name :		  	Init_Green_PWM(uint16_t period)
 *
 *
 *
 * Description :	This function initializes Clock, MUX Port, Timer, Reload values, Clock Prescaler, and Initial Duty Cycle
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void Init_Green_LED_PWM(uint16_t period);

/*************************************************************************************************************
 *
 * Name :		  	Init_Blue_PWM(uint16_t period)
 *
 *
 *
 * Description :	This function initializes Clock, MUX Port, Timer, Reload values, Clock Prescaler, and Initial Duty Cycle
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void Init_Blue_LED_PWM(uint16_t period);

#endif /* PWM_H_ */
