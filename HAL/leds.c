/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: led.c $
 * $Revision: version 2 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
*/
/*============================================================================*/
/* COPYRIGHT (C) CONTINENTAL AUTOMOTIVE 2014                                  */
/* AUTOMOTIVE GROUP, Interior Division, Body and Security                     */
/* ALL RIGHTS RESERVED                                                        */
/*                                                                            */
/* The reproduction, transmission, or use of this document or its content is  */
/* not permitted without express written authority. Offenders will be liable  */
/* for damages.                                                               */
/* All rights, including rights created by patent grant or registration of a  */
/* utility model or design, are reserved.                                     */
/*                                                                            */
/*============================================================================*/
/*============================================================================*/
/*                    REUSE HISTORY - taken over from                         */
/*============================================================================*/
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: led.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "leds.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void leds_InitLeds(void);
void leds_TurnOnUpLED(void);
void leds_TurnOffUpLED(void);
void leds_TurnOnAntipinchLED(void);
void leds_TurnOffAntipinchLED(void);
void leds_TurnOnDownLED(void);
void leds_TurnOffDownLED(void);

/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void leds_InitLeds(void){
  pcc_EnablePeripheralClock(PCC_PORTC_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTD_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);

  io_OutputPin(rps_PTE, 1<<PTE4);          /* Up LED*/
  port_ConfigurePinMode(rps_PORTE, PTE4, 0x00000100);  /* MUX = GPIO, input filter enabled */

  io_OutputPin(rps_PTD, 1<<PTD1);          /* Down LED*/
  port_ConfigurePinMode(rps_PORTD, PTD1, 0x00000100);  /* MUX = GPIO, input filter enabled */

  io_OutputPin(rps_PTC, 1<<PTC17);          /* Antipinch LED*/
  port_ConfigurePinMode(rps_PORTC, PTC17, 0x00000100);  /* MUX = GPIO, input filter enabled */

}

void leds_TurnOnUpLED(void){
  io_SetOutput(rps_PTE, 1<<PTE4);
}

void leds_TurnOnDownLED(void){
  io_SetOutput(rps_PTD, 1<<PTD1);
}

void leds_TurnOnAntipinchLED(void){
  io_SetOutput(rps_PTC, 1<<PTC17);
}

void leds_TurnOffUpLED(void){
  io_ClearOutput(rps_PTE, 1<<PTE4);
}

void leds_TurnOffDownLED(void){
  io_ClearOutput(rps_PTD, 1<<PTD1);
}

void leds_TurnOffAntipinchLED(void){
  io_ClearOutput(rps_PTC, 1<<PTC17);
}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */