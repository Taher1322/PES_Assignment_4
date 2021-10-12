# PES_Assignment_4
Code for Assignment 4 for PES, ECEN-5813, Fall 2021 - Due Date >> 10/12/2021 @ 10:30 AM MDT

# Author: TAHER UJJAINWALA </br>

Contact me if you are facing issue in execution of the code @ tauj5361@colorado.edu

# BUFFAHITI TRAFFIC LIGHT </br> 

# Project Comments
 This projects implements the following routine :

At program startup, Buffahiti Traffic Light  will run the LED by blinking in the following pattern:
Initially it is in Stop state
When the traffic light is in the STOP state, Buffahiti residents use the color #611E3C
When the traffic light is in the GO state, Buffahiti residents use the color #229622
When the traffic light is in the WARNING state, Buffahiti residents use the color #FFB200
When someone presses the Button or Touch slider to cross the street (CROSSWALK state), the traffic light is blinking with the color #001030.
In the CROSSWALK state, the light blinks 250 msec off, 750 msec on. No other mode has the light blinking.


# Developement Details </br>
Software used Developed using MCUExpresso IDE 7.2.0 on Windows 10. </br>
DEBUG Mode - Prints DEBUG Messages to UART terminal at Baud Rate of 115200 and 8N1. </br>
RUN/Release Mode - RUN Mode, no debug messages are printed on UART Terminal </br>
To see the console messages change to UART in quick settings and see the Debug messages as per the logic with Time</br>
To see the console messages in UART mode change to UART in quick settings and open a new Terminal with 115200 Baud Rate and 8N1 settings </br>

Note:  Due to LOG messages in DEBUG mode - There is some time delay which makes 5000 ms to 5010ms which is not more precise in PRODUCTION mode </br>

# Extra Credit Answers - Switch defined as Interrupt for Transition to Crosswalk </br>

External GPIO interrupt for switch connection </br>

1. PD3 is configured as external gpio input interrupt.
2. It is also configured with internal pull up resistor. 
3. Rough schematic is added to repository. 


# State Machine Representation is added in this repository </br>

PEER REVIEW 

Performed with - Gaurang K Rane

Date & Time 10-11-2021  from 9:00 - 10:00 PM

# Peer Feedbacks and Improvements </br>

In the release mode - </br>
1. Timings for each state are proper. </br>
2. Transitions especially to and from crosswalk state need to be smoother. </br>

In the debug mode - </br>
1. Debug comments need to be implemented. </br>
2. Comments for each states and better defines in .h are recommended </br>


# Feedback incorporation done in my Code after Peer Review </br>

1. Smooth transition done.
2. Debug comments added with Systick Time
3. Readability and Elegance of the code improved 
4. Followed professional coding standards for each files




