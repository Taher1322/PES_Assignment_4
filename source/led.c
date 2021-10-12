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
 *    File name   : led.c
 *    Description : This file changes the Brightness of RGB led using PWM values (0-255)
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *	  Reference: Dean PWM section
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
