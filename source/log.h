/*************************
 *
 *
 *
 *    File name   : log.h
 *    Description : This generates messages when in DEBUG mode and not in RELEASE
 *
 *
 *    Author: TAHER S UJJAINWALA
 * 	  Tools : MCUXpressor IDE
 *
 *    Date  : 10/10/2021
 *
 *
 */
#ifndef LOG_H_
#define LOG_H_

#include <stdio.h>
/*************************************************************************************************************
 *
 * Name :		  	DEBUG MESSAGES
 *
 *
 *
 * Description :	This generates messages when in DEBUG mode and not in RELEASE
 * Inputs: NONE
 *
 * Return: NONE
 *************************************************************************************************************/

#ifdef DEBUG
#define LOG PRINTF
#else
#define LOG(...)
#endif

#endif /* LOG_H_ */
