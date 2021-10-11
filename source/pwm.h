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
#ifndef PWM_H_
#define PWM_H_

#define RED_LED_POS (18)
#define GREEN_LED_POS (19)
#define BLUE_LED_POS (1)
#define PWM_PERIOD (48000)
#define BRIGTHNESS (255)


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
