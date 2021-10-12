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
#define stop_timeout		(500)/*stop state total time*/
#else
#define stop_timeout		(2000)/*stop state total time*/
#endif


#ifdef DEBUG
#define go_timeout		(500)/*go state total time*/
#else
#define go_timeout		(2000)/*go state total time*/
#endif

#ifdef DEBUG
#define warning_timeout		(300)/*warning state total time*/
#else
#define warning_timeout		(500)/*warning state total time*/
#endif


#define transition_timeout		(100)/*transition state total time*/
#define crosswalk_timeout		(1000)/*crosstalk state total time*/



void stop_state();
void go_state();
void warning_state();
void crosswalk_state();
void transition();

#endif /* STATE_MACHINE_H_ */
