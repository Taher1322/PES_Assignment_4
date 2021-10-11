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
void Init_Red_LED_PWM(uint16_t period);
void Init_Green_LED_PWM(uint16_t period);
void Init_Blue_LED_PWM(uint16_t period);

#endif /* PWM_H_ */
