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
