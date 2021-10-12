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
 *    File name   : state_machine.c
 *    Description : This file runs the state machine in infinite loop.
 *    It also takes care of external slider and button event to change the state to crosswalk
 *
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 * 	  Reference: Alexander Dean State Machine Implementation Section, Crafted Ideas with Gaurang Rane
 * 	  Help from Mukta to get the transition working correctly
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
#include "TSI.h"
#include "led.h"
#include "pwm.h"
#include "state_machine.h"
#include "Timer.h"
#include "log.h"
#include "button_int.h"


extern char state;				//Stores the current state as character
int touch_val;					//Used to store the returned values from Touch Event Slider
int reset_timer_flag;			//Used for state transition and Resetting timer
int on_off_cycle;				//Used to calculate on and off time in Crosswalk state
int count_loop;					//Used to calculate on and off time in Crosswalk state
int touch_event;				//Changes the touch event flag if touch event is detected
int button_event;				//Changes the flag if button is pressed

//Used to store the Initial and Final PWM values for every transition
int g_initial_red;
int g_final_red;
int g_initial_green;
int g_final_green;
int g_initial_blue;
int g_final_blue;


//Stop State Function
void stop_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();					//Resets the timer
	}

	reset_timer_flag = 1;

  	float time = get_timer();			//Gets the time value

  	if (time <= stop_timeout)			//Checks the Stop state timeout
  	{
  		set_RGB_LED(stop_red, stop_green, stop_blue);

  		if ((int)time%5 == 0)			//This loops runs every 50ms - Checks the Touch and Button event
  		{
  			touch_val = Touch_Scan_LH();
  			button_event = check_switch_pressed();
  			if (touch_val == 1 || button_event == 1)					//Touch Event detection check
  				touch_event = 1;										//Sets the flag to 1
  		}
  	}

  		time = get_timer();

  		if (touch_event == 1)			//If event is detected change the initial and final color values and change the state
  		{
  			state = 'C';						//State changes to Crosswalk
  			reset_timer_flag = 0;
  			g_initial_red = stop_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = stop_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = stop_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from STOP to CROSSWALK -->System Time = %d msec\n\r", now()*10);
  			transition();
  		}

  		else if (time > stop_timeout)		//If Stop timeout is elapsed, changes the state to Go state
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = stop_red;
  			g_final_red = go_red;
  			g_initial_green = stop_green;
  			g_final_green = go_green;
  			g_initial_blue = stop_blue;
  			g_final_blue = go_blue;
  			LOG("Transition from STOP to GO state  --> System Time = %d msec\n\r", now()*10);
  			transition();
  		}

  		else if (time <= stop_timeout)	//If Stop timeout is not elapsed, continue to be in Stop state
  			state = 'S';
  	}


//GO State Function
void go_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();						//Resets the timer
	}

	reset_timer_flag = 1;

  	float time = get_timer();				//Gets the time value

  	if (time <= go_timeout)					//Checks the Go state timeout
  	{
  		set_RGB_LED(go_red, go_green, go_blue);

  		if ((int)time%5 == 0)				//This loops runs every 50ms - Checks the Touch and Button event
  		{
  			touch_val = Touch_Scan_LH();
  			button_event = check_switch_pressed();
  			if (touch_val == 1 || button_event == 1)			//Touch Event detection check
  				touch_event = 1;
  		}

  	}

  		time = get_timer();

  		if (touch_event == 1)			//If event is detected change the initial and final color values and change the state
  		{
  			state = 'C';				//State changes to Crosswalk
  			reset_timer_flag = 0;
  			g_initial_red = go_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = go_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = go_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from GO to CROSSWALK --> System Time = %d msec \n\r", now()*10);
  			transition();
  		}

  		else if (time > go_timeout)		//If Go timeout is elapsed, changes the state to Warning state
		{
  			state = 'W';
  			reset_timer_flag = 0;
  			g_initial_red = go_red;
  			g_final_red = warning_red;
  			g_initial_green = go_green;
  			g_final_green = warning_green;
  			g_initial_blue = go_blue;
  			g_final_blue = warning_blue;
  			LOG("Transition from GO to WARNING state --> System Time = %d msec \n\r", now()*10);
  			transition();
		}

  		else if (time <= go_timeout)	//If Go timeout is not elapsed, continue to be in Go state
  			state = 'G';

  	}


//WARNING State Function
void warning_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();								//Resets the timer
	}

	reset_timer_flag = 1;

  	float time = get_timer();						//Gets the time value

  	if (time <= warning_timeout)					//Checks the Warning state timeout
  	{
  		set_RGB_LED(warning_red, warning_green, warning_blue);

  		if ((int)time%5 == 0)						//This loops runs every 50ms - Checks the Touch and Button event
  		{
  			touch_val = Touch_Scan_LH();
  			button_event = check_switch_pressed();
  			if (touch_val == 1 || button_event == 1)		//Touch Event detection check
  				touch_event = 1;
  		}

  	}

  		time = get_timer();

  		if (touch_event == 1)			//If event is detected change the initial and final color values and change the state
  		{
  			state = 'C';				//State changes to Crosswalk
  			reset_timer_flag = 0;
  			g_initial_red = warning_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = warning_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = warning_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from WARNING to CROSSWALK --> System Time = %d msec\n\r", now()*10);
  			transition();
  		}

  		else if (time > warning_timeout)		//If Warning timeout is elapsed, changes the state to Stop state
  		{
  			state = 'S';
  			reset_timer_flag = 0;
  			g_initial_red = warning_red;
  			g_final_red = stop_red;
  			g_initial_green = warning_green;
  			g_final_green = stop_green;
  			g_initial_blue = warning_blue;
  			g_final_blue = stop_blue;
  			LOG("Transition from WARNING to STOP state --> System Time = %d msec \n\r", now()*10);
  			transition();
  		}

  		else if (time <= warning_timeout)		//If Warning timeout is not elapsed, continue to be in Warning state
  			state ='W';
  	}


//Crosswalk State Function
void crosswalk_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();						//Resets the timer
		on_off_cycle = 0;
		count_loop = 0;
	}

	reset_timer_flag = 1;

  	float time = get_timer();				//Gets the time value

  	if (time <= crosswalk_timeout)			//Checks the Crosswalk state timeout
  	{
  		on_off_cycle = time - (count_loop * 100);		//Code reference to run in 750ms and 250ms taken from Gaurang Rane

  		if (on_off_cycle <= delay_750ms)				//Generates 750ms ON cycle
  			set_RGB_LED(crosswalk_red, crosswalk_green, crosswalk_blue);

  		if((on_off_cycle <= delay_1000ms) && (on_off_cycle >delay_750ms))			//Generated remaining 250ms OFF cycle
  			set_RGB_LED(led_off, led_off, led_off);

  		if (on_off_cycle >= delay_1000ms)
  			count_loop++;
  	}


  		if (time > crosswalk_timeout)		//If Crosswalk timeout is elapsed, changes the state to Go state
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = crosswalk_red;
  			g_final_red = go_red;
  			g_initial_green = crosswalk_green;
  			g_final_green = go_green;
  			g_initial_blue = crosswalk_blue;
  			g_final_blue = go_blue;
  			LOG("Transition from CROSSWALK to GO state  --> System Time = %d msec\n\r", now()*10);
  			transition();
  		}

  		else if (time <= crosswalk_timeout)		//If Crosswalk timeout is not elapsed, continue to be in Crosswalk state
  			state = 'C';
  	}


//Transition State Function
void transition()
{
	float final_red,final_green, final_blue;

	if(reset_timer_flag ==0)
	{
		reset_timer();							//Resets the timer
	}

	reset_timer_flag = 1;

  	float time = get_timer();					//Gets the time value
  	float prev_time= get_timer();				//Gets the time value


	while(time<= transition_timeout) 			//Checks the Transition state timeout
	{
		if(time - prev_time > smooth_trans)		//Transition every 63ms
		{
			prev_time = time;

			//Calculate the final color based on initial and final RGB values for PWM
			final_red = (g_initial_red - g_final_red)*(time/100)+(g_initial_red);
			final_green = (g_initial_green - g_final_green)* (time/100)+ (g_initial_green);
			final_blue = (g_initial_blue - g_final_blue)*(time/100) + (g_initial_blue);

			//Set the transition color as calculated
			set_RGB_LED(final_red, final_green, final_blue);
		}

		time = get_timer();						//Gets the time value
	}

	if (time > transition_timeout)				//If Transition timeout is elapsed, changes the state
	{
		reset_timer_flag = 0;
	}


}
