/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.c $
 * $Revision: version 2 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28  $
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: button.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "button.h"

/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/


/* Private functions prototypes */
/*============================================================================*/
void button_InitButtons(void);
T_UBYTE button_CheckButtonUp(void);
T_UBYTE button_CheckButtonDown(void);
T_UBYTE button_CheckButtonAntipinch(void);
T_UBYTE button_DebounceButtonUp(void);
T_UBYTE button_DebounceButtonDown(void);
T_UBYTE button_DebounceButtonAntipinch(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

/* Exported functions */
/*============================================================================*/

void button_InitButtons(void){
  pcc_EnablePeripheralClock(PCC_PORTA_INDEX);
  pcc_EnablePeripheralClock(PCC_PORTE_INDEX);

  io_InputPin(rps_PTA, 1<<PTA13);          /* Antipinch Button*/
  port_ConfigurePinMode(rps_PORTA, PTA13, 0x00000110);  /* MUX = GPIO, input filter enabled */

  io_InputPin(rps_PTE, 1<<PTE5);          /* Up Button*/
  port_ConfigurePinMode(rps_PORTE, PTE5, 0x00000110);  /* MUX = GPIO, input filter enabled */

  io_InputPin(rps_PTA, 1<<PTA12);          /* Down Button*/
  port_ConfigurePinMode(rps_PORTA, PTA12, 0x00000110);  /* MUX = GPIO, input filter enabled */

}

T_UBYTE button_CheckButtonUp(void){
  return io_GetPinData(rps_PTE, PTE5);
}

T_UBYTE button_CheckButtonDown(void){
  return io_GetPinData(rps_PTA, PTA12);
}

T_UBYTE button_CheckButtonAntipinch(void){
  return io_GetPinData(rps_PTA, PTA13);
}

T_UBYTE button_DebounceButtonUp(void){  
  if(button_CheckButtonUp()){
    timer_Wait50ms();
    if(button_CheckButtonUp())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

T_UBYTE button_DebounceButtonDown(void){
   if(button_CheckButtonDown()){
    timer_Wait50ms();
    if(button_CheckButtonDown())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}


T_UBYTE button_DebounceButtonAntipinch(void){
   if(button_CheckButtonAntipinch()){
    timer_Wait50ms();
    if(button_CheckButtonAntipinch())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */