/*************************
 *
 *
 *
 *    File name   : TSI.c
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
//Including the Header files required for operation
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "led.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
//variation of the capacitance from 50 to 2500

#define TOUCH_OFFSET (550)  // offset value to be subtracted
#define TOUCH_DATA (TSI0->DATA & 0xFFFF)//macro for extracting the count from data register
#define TOUCH_THRESHOLD (80)
volatile int slider_flag;

//************************************************Global Variables*********************************************
/*
 * @brief   Application entry point.
 */


void Touch_Init()
{
	SIM->SCGC5 |= SIM_SCGC5_TSI_MASK; // enabling the clock


	TSI0->GENCS = TSI_GENCS_MODE(0u) | //operating in non-noise mode
								TSI_GENCS_REFCHRG(0u) | //reference oscillator charge and discharge value 500nA
								TSI_GENCS_DVOLT(0u) | //oscillator voltage rails set to default
								TSI_GENCS_EXTCHRG(0u) | //electrode oscillator charge and discharge value 500nA
								TSI_GENCS_PS(0u) |  // frequency clock divided by one
								TSI_GENCS_NSCN(31u) | //scanning the electrode 32 times
								TSI_GENCS_TSIEN_MASK | //enabling the TSI module
								TSI_GENCS_EOSF_MASK; // writing one to clear the end of scan flag
}



int Touch_Scan_LH(void)
{
	unsigned int scan = 0;				 //Variable to read the slider values
	TSI0->DATA = 	TSI_DATA_TSICH(10u); //selecting channel 10
	TSI0->DATA |= TSI_DATA_SWTS_MASK; //software trigger to start the scan
	while (!(TSI0->GENCS & TSI_GENCS_EOSF_MASK )) // waiting for the scan to complete 32 times
	;
	scan = TOUCH_DATA;					 //Reading the touch data
	TSI0->GENCS |= TSI_GENCS_EOSF_MASK ; //writing one to clear the end of scan flag

	if ((scan - TOUCH_OFFSET) > TOUCH_THRESHOLD)		 //Checking if the touch slider is touched and there are no false values
	{
		slider_flag = 1;				//Setting the touch event flag as 1
	}
	else
	{
		slider_flag = 0;				//If not touched setting the touch event flag as 0
	}

	return slider_flag;					//Returning the touch event flag value
	//return scan- TOUCH_OFFSET;			 //Returning the touch slider data with offset
}
