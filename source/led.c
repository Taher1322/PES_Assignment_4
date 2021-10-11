/*************************
 *
 *
 *
 *    File name   : led.c
 *    Description : This file Initialized the Slider and is called to read the value of the sliders
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef LED_C_
#define LED_C_

//Including the Header files required for operation
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "led.h"

//Function to change the Brightness of LED using PWM values
void set_RGB_LED(int red, int green, int blue)
{
	TPM2->CONTROLS[0].CnV = red;
	TPM2->CONTROLS[1].CnV = green;
	TPM0->CONTROLS[1].CnV = blue;
}

#endif /* LED_C_ */
