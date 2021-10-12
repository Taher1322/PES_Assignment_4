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
 *    File name   : state_machine.h
 *    Description : This file Initialized the Slider and is called to read the value of the sliders
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *
 *    Date  : 10/10/2021
 *
 *
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_


//************************************************DEFINES*********************************************

#define stop_red 		(97)
#define stop_green 		(30)
#define stop_blue 		(60)
#define go_red 			(34)
#define go_green		(150)
#define go_blue 		(34)
#define warning_red 	(255)
#define warning_green	(178)
#define warning_blue 	(0)
#define crosswalk_red	(0)
#define crosswalk_green	(16)
#define crosswalk_blue	(48)
#define led_off			(0)

#define delay_750ms     (100)
#define delay_250ms 	(25)

#ifdef DEBUG
#define stop_timeout			(500)    //Stop state timeout in DEBUG mode -->5 seconds
#else
#define stop_timeout			(2000)	//Stop state timeout in PRODUCTION mode -->20 seconds
#endif


#ifdef DEBUG
#define go_timeout				(500)	//Go state timeout in DEBUG mode -->5 seconds
#else
#define go_timeout				(2000) 	//Go state timeout in PRODUCTION mode -->20 seconds
#endif

#ifdef DEBUG
#define warning_timeout			(300)	//Warning state timeout in DEBUG mode -->3 seconds
#else
#define warning_timeout			(500)	//Warning state timeout in PRODUCTION mode -->5 seconds
#endif


#define transition_timeout		(100)	//Transition state timeout in DEBUG mode -->1 seconds
#define crosswalk_timeout		(1000)	//Crosswalk state timeout in PRODUCTION mode -->10 seconds


/*************************************************************************************************************
 *
 * Name :		  	void stop_state()
 *
 *
 *
 * Description :	This function switches the RGB led as per Stop State
 * It also checks the Touch event and Button event using Systick to change the state
 * It runs for 5 seconds in DEBUG mode and 20 seconds in PRODUCTION mode
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void stop_state();


/*************************************************************************************************************
 *
 * Name :		  	void go_state()
 *
 *
 *
 * Description :	This function switches the RGB led as per Go State
 * It also checks the Touch event and Button event using Systick to change the state
 * It runs for 5 seconds in DEBUG mode and 20 seconds in PRODUCTION mode
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void go_state();

/*************************************************************************************************************
 *
 * Name :		  	void warning_state()
 *
 *
 *
 * Description :	This function switches the RGB led as per Warning State
 * It also checks the Touch event and Button event using Systick to change the state
 * It runs for 3 seconds in DEBUG mode and 5 seconds in PRODUCTION mode
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void warning_state();

/*************************************************************************************************************
 *
 * Name :		  	void crosswalk_state()
 *
 *
 *
 * Description :	This function switches the RGB led as per Crosswalk State
 * It is called when there is Slider Touch event or Button event
 * It runs for 10 seconds in DEBUG and PRODUCTION mode
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void crosswalk_state();

/*************************************************************************************************************
 *
 * Name :		  	void transition()
 *
 *
 *
 * Description :	This function switches the RGB led as per initial and final values based on every state
 * It changes the color smoothly in every 63ms until 1000ms to complete the color transition of RGB led
 * It runs for 1 seconds in DEBUG and PRODUCTION mode
 *
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/
void transition();

#endif /* STATE_MACHINE_H_ */
