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
#include "TSI.h"
#include "led.h"
#include "pwm.h"
#include "state_machine.h"
#include "Timer.h"
#include "log.h"


extern char state;
int touch_val;
int reset_timer_flag;
int on_off_cycle;
int count_loop;
int touch_event;


int g_initial_red;
int g_final_red;
int g_initial_green;
int g_final_green;
int g_initial_blue;
int g_final_blue;



void stop_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();
	}

	reset_timer_flag = 1;

  	float time = get_timer();

  	if (time <= stop_timeout)
  	{
  		set_RGB_LED(stop_red, stop_green, stop_blue);

  		if ((int)time%5 == 0)
  		{
  			touch_val = Touch_Scan_LH();
  			if (touch_val == 1)
  				touch_event = 1;
  		}
  	}

  		time = get_timer();

  		if (touch_event == 1)
  		{
  			state = 'C';
  			reset_timer_flag = 0;
  			g_initial_red = stop_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = stop_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = stop_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from STOP to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > stop_timeout)
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = stop_red;
  			g_final_red = go_red;
  			g_initial_green = stop_green;
  			g_final_green = go_green;
  			g_initial_blue = stop_blue;
  			g_final_blue = go_blue;
  			LOG("Transition from STOP to GO state\n\r");
  			transition();
  		}

  		else if (time <= stop_timeout)
  			state = 'S';
  	}

	//PRINTF("Entered STOP STATE\n\r");


void go_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();
	}

	reset_timer_flag = 1;

  	float time = get_timer();

  	if (time <= go_timeout)
  	{
  		set_RGB_LED(go_red, go_green, go_blue);

  		if ((int)time%5 == 0)
  		{
  			touch_val = Touch_Scan_LH();
  			if (touch_val == 1)
  				touch_event = 1;
  		}

  	}

  		time = get_timer();

  		if (touch_event == 1)
  		{
  			state = 'C';
  			reset_timer_flag = 0;
  			g_initial_red = go_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = go_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = go_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from GO to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > go_timeout)
		{
  			state = 'W';
  			reset_timer_flag = 0;
  			g_initial_red = go_red;
  			g_final_red = warning_red;
  			g_initial_green = go_green;
  			g_final_green = warning_green;
  			g_initial_blue = go_blue;
  			g_final_blue = warning_blue;
  			LOG("Transition from GO to WARNING state\n\r");
  			transition();
		}

  		else if (time <= go_timeout)
  			state = 'G';

  	}

	//PRINTF("Entered GO STATE\n\r");




void warning_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();
	}

	reset_timer_flag = 1;

  	float time = get_timer();

  	if (time <= warning_timeout)
  	{
  		set_RGB_LED(warning_red, warning_green, warning_blue);

  		if ((int)time%5 == 0)
  		{
  			touch_val = Touch_Scan_LH();
  			if (touch_val == 1)
  				touch_event = 1;
  		}

  	}

  		time = get_timer();

  		if (touch_event == 1)
  		{
  			state = 'C';
  			reset_timer_flag = 0;
  			g_initial_red = warning_red;
  			g_final_red = crosswalk_red;
  			g_initial_green = warning_green;
  			g_final_green = crosswalk_green;
  			g_initial_blue = warning_blue;
  			g_final_blue = crosswalk_blue;
  			touch_event = 0;
  			LOG("Slider Touched - Transition from WARNING to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > warning_timeout)
  		{
  			state = 'S';
  			reset_timer_flag = 0;
  			g_initial_red = warning_red;
  			g_final_red = stop_red;
  			g_initial_green = warning_green;
  			g_final_green = stop_green;
  			g_initial_blue = warning_blue;
  			g_final_blue = stop_blue;
  			LOG("Transition from WARNING to STOP state\n\r");
  			transition();
  		}

  		else if (time <= warning_timeout)
  			state ='W';
  	}

	//PRINTF("Entered WARNING STATE\n\r");




void crosswalk_state()
{

	if(reset_timer_flag ==0)
	{
		reset_timer();
		on_off_cycle = 0;
		count_loop = 0;
		//PRINTF("Inside the RESET LOOP in CROSSWALK\n\r");
	}

	//reset_timer();
	reset_timer_flag = 1;

  	float time = get_timer();

  	if (time <= crosswalk_timeout)
  	{
  		on_off_cycle = time - (count_loop * 100);

  		if (on_off_cycle <= delay_250ms)
  			set_RGB_LED(led_off, led_off, led_off);

  		if((on_off_cycle <= delay_750ms) && (on_off_cycle >delay_250ms))
  			set_RGB_LED(crosswalk_red, crosswalk_green, crosswalk_blue);

  		if (on_off_cycle >= delay_750ms)
  			count_loop++;
  	}



  		//time = get_timer();
  		if (time > crosswalk_timeout)
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = crosswalk_red;
  			g_final_red = go_red;
  			g_initial_green = crosswalk_green;
  			g_final_green = go_green;
  			g_initial_blue = crosswalk_blue;
  			g_final_blue = go_blue;
  			//reset_timer();
  			LOG("Transition from CROSSWALK to GO state\n\r");
  			transition();
  		}

  		else if (time <= crosswalk_timeout)
  			state = 'C';
  	}

	//PRINTF("Entered CROSSWALK STATE\n\r");



void transition()
{
	int final_red,final_green, final_blue;

	if(reset_timer_flag ==0)
	{
		reset_timer();
	}

	reset_timer_flag = 1;

  	float time = get_timer();
  	float prev_time= get_timer();


	while(time<= transition_timeout) //TRANSITION OVER 1 SECOND DELAY POLL EVERY 10MS
	{
		if(time - prev_time > 6.3)
		{
			prev_time = time;
			final_red = (g_initial_red - g_final_red)*(int)time/100+g_initial_red;
			final_green = (g_initial_green - g_final_green)*(int)time/100+g_initial_green;
			final_blue = (g_initial_blue - g_final_blue)*(int)time/100+g_initial_blue;
			//SET CURRENT COLOUR BY SETTING PROPER DUTY CYCLES
			set_RGB_LED(final_red, final_green, final_blue);
		}
		//PRINTF("Transition state\n\r");
		time = get_timer();
	}

	if (time > transition_timeout)
	{
		reset_timer_flag = 0;
		//PRINTF("TRANSITION 1s \n\r");
	}


}
