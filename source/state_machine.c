/*
 * state_machine.c
 *
 *  Created on: Oct 9, 2021
 *      Author: ujjai
 */

#include "state_machine.h"
#include "Timer.h"


extern char state;
int touch_val;
int reset_timer_flag;
int on_off_cycle;
int count_loop;
int touch_event;

uint8_t stop_color[3] = {97, 30, 60};
uint8_t go_color[3] = {34, 150, 34};
uint8_t warning_color[3] = {255, 178, 0};
uint8_t crosswalk_color[3] = {0, 16, 48};
uint8_t crosswalk_off[3] = {0, 0, 0};

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

  	if (time <= 500)
  	{
  		set_RGB_LED(stop_color[0], stop_color[1], stop_color[2]);

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
  			g_initial_red = stop_color[0];
  			g_final_red = crosswalk_color[0];
  			g_initial_green = stop_color[1];
  			g_final_green = crosswalk_color[1];
  			g_initial_blue = stop_color[2];
  			g_final_blue = crosswalk_color[2];
  			touch_event = 0;
  			PRINTF("Slider Touched - Transition from STOP to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > 500)
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = stop_color[0];
  			g_final_red = go_color[0];
  			g_initial_green = stop_color[1];
  			g_final_green = go_color[1];
  			g_initial_blue = stop_color[2];
  			g_final_blue = go_color[2];
  			PRINTF("Transition from STOP to GO state\n\r");
  			transition();
  		}

  		else if (time <= 500)
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

  	if (time <= 500)
  	{
  		set_RGB_LED(go_color[0], go_color[1], go_color[2]);

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
  			g_initial_red = go_color[0];
  			g_final_red = crosswalk_color[0];
  			g_initial_green = go_color[1];
  			g_final_green = crosswalk_color[1];
  			g_initial_blue = go_color[2];
  			g_final_blue = crosswalk_color[2];
  			touch_event = 0;
  			PRINTF("Slider Touched - Transition from GO to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > 500)
		{
  			state = 'W';
  			reset_timer_flag = 0;
  			g_initial_red = go_color[0];
  			g_final_red = warning_color[0];
  			g_initial_green = go_color[1];
  			g_final_green = warning_color[1];
  			g_initial_blue = go_color[2];
  			g_final_blue = warning_color[2];
  			PRINTF("Transition from GO to WARNING state\n\r");
  			transition();
		}

  		else if (time <= 500)
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

  	if (time <= 300)
  	{
  		set_RGB_LED(warning_color[0], warning_color[1], warning_color[2]);

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
  			g_initial_red = warning_color[0];
  			g_final_red = crosswalk_color[0];
  			g_initial_green = warning_color[1];
  			g_final_green = crosswalk_color[1];
  			g_initial_blue = warning_color[2];
  			g_final_blue = crosswalk_color[2];
  			touch_event = 0;
  			PRINTF("Slider Touched - Transition from WARNING to CROSSWALK \n\r");
  			transition();
  		}

  		else if (time > 300)
  		{
  			state = 'S';
  			reset_timer_flag = 0;
  			g_initial_red = warning_color[0];
  			g_final_red = stop_color[0];
  			g_initial_green = warning_color[1];
  			g_final_green = stop_color[1];
  			g_initial_blue = warning_color[2];
  			g_final_blue = stop_color[2];
  			PRINTF("Transition from WARNING to STOP state\n\r");
  			transition();
  		}

  		else if (time <=300)
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

  	if (time <= 1000)
  	{
  		on_off_cycle = time - (count_loop * 100);

  		if (on_off_cycle <= 25)
  			set_RGB_LED(crosswalk_off[0], crosswalk_off[1], crosswalk_off[2]);

  		if((on_off_cycle <=100) && (on_off_cycle >25))
  			set_RGB_LED(crosswalk_color[0], crosswalk_color[1], crosswalk_color[2]);

  		if (on_off_cycle >= 100)
  			count_loop++;
  	}



  		//time = get_timer();
  		if (time > 1000)
  		{
  			state = 'G';
  			reset_timer_flag = 0;
  			g_initial_red = crosswalk_color[0];
  			g_final_red = go_color[0];
  			g_initial_green = crosswalk_color[1];
  			g_final_green = go_color[1];
  			g_initial_blue = crosswalk_color[2];
  			g_final_blue = go_color[2];
  			//reset_timer();
  			PRINTF("Transition from CROSSWALK to GO state\n\r");
  			transition();
  		}

  		else if (time <= 1000)
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


	while(time<= 100) //TRANSITION OVER 1 SECOND DELAY POLL EVERY 10MS
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

	if (time > 100)
	{
		reset_timer_flag = 0;
		//PRINTF("TRANSITION 1s \n\r");
	}


}
