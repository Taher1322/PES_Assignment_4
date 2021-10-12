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
 *    File name   : button_int.h
 *    Description : This file contains all the functions declaration which are used in button_int.c to generate Interrupt
 *    when external switch is pressed
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *
 *    Date  : 10/11/2021
 *
 *
 */

#ifndef BUTTON_INT_H_
#define BUTTON_INT_H_

/*************************************************************************************************************
 *
 * Name :		  	void Init_Switch()
 *
 *
 *
 * Description :	This function initializes GPIO (switch) as an INPUT
 * It defines all clock, interrupt priority, and GPIO as input
 *
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

void Init_Switch();

/*************************************************************************************************************
 *
 * Name :		  	int check_switch_pressed()
 *
 *
 *
 * Description : This functions returns the current switch state
 *
 *
 * Inputs: NONE
 *
 * Return: SWITCH PRESS STATE (1- pressed, 0- not pressed)
 *************************************************************************************************************/
int check_switch_pressed();


#endif /* BUTTON_INT_H_ */
