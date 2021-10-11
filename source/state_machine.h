/*
 * state_machine.h
 *
 *  Created on: Oct 9, 2021
 *      Author: ujjai
 */

#ifndef STATE_MACHINE_H_
#define STATE_MACHINE_H_

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


//************************************************DEFINES*********************************************

#define STOP_state 0
#define GO_state 1
#define WARNING_state 2
#define CROSSWALK_state 3

void stop_state();
void go_state();
void warning_state();
void crosswalk_state();
void transition();

#endif /* STATE_MACHINE_H_ */
