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
 *    File name   : led.h
 *    Description : This file Initialized the Slider and is called to read the value of the sliders
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef LED_H_
#define LED_H_

/*************************************************************************************************************
 *
 * Name :		  	void set_RGB_LED(int red, int green, int blue)
 *
 *
 *
 * Description :	This function controls the RGB led using PWM
 *
 *
 * Inputs: PWM duty value (0-255)
 *
 * Return: NONE
 *************************************************************************************************************/
void set_RGB_LED(int red, int green, int blue);

#endif /* LED_H_ */
