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
 *    File name   : TSI.h
 *    Description : This file defines the functions which are used in TSI.c to initialize and read the slider value
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Alexander Dean TSI section
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef TSI_H_
#define TSI_H_

#define TOUCH_OFFSET (550)  // offset value to be subtracted
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register
#define TOUCH_THRESHOLD (80)			//Threshold values on touch event

/*************************************************************************************************************
 *
 * Name :		  	void Touch_Init()
 *
 *
 *
 * Description :	This function initializes the slider
 * It defines all the internal register bit as required - oscillator, scanning, electrode voltage
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void Touch_Init();

/*************************************************************************************************************
 *
 * Name :		  	void Touch_Scan_LH()
 *
 *
 *
 * Description :	This function reads the slider values on user touch
 * Channel 10 is programmed and masked to get the touch input data
 *
 * Inputs: NONE
 *
 * Return: Touch Flag if Slider is touched (1 - Touched & 0 - Not Touched)
 *************************************************************************************************************/
int Touch_Scan_LH(void);

#endif /* TSI_H_ */
