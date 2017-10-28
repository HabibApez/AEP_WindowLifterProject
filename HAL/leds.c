/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: led.c $
 * $Revision: version 1 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-24 $
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
/*                     |                    |                                 */
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



/* Inline functions */
/*============================================================================*/

void Turn_On_UpLED(void){
  IO_Output_Set(PTE, 1<<PTE4);
}

void Turn_On_DownLED(void){
  IO_Output_Set(PTD, 1<<PTD1);
}

void Turn_On_AntipinchLED(void){
  IO_Output_Set(PTC, 1<<PTC17);
}

void Turn_Off_UpLED(void){
  IO_Output_Clear(PTE, 1<<PTE4);
}

void Turn_Off_DownLED(void){
  IO_Output_Clear(PTD, 1<<PTD1);
}

void Turn_Off_AntipinchLED(void){
  IO_Output_Clear(PTC, 1<<PTC17);
}

/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void Init_Leds(void){
  Peripheral_Clock_Enable(PCC_PORTC_INDEX);
  Peripheral_Clock_Enable(PCC_PORTD_INDEX);
  Peripheral_Clock_Enable(PCC_PORTE_INDEX);

  IO_Output_Pin(PTE, 1<<PTE4);          /* Up LED*/
  Configure_Pin_Mode(PORTE, PTE4, 0x00000100);  /* MUX = GPIO, input filter enabled */

  IO_Output_Pin(PTD, 1<<PTD1);          /* Down LED*/
  Configure_Pin_Mode(PORTD, PTD1, 0x00000100);  /* MUX = GPIO, input filter enabled */

  IO_Output_Pin(PTC, 1<<PTC17);          /* Antipinch LED*/
  Configure_Pin_Mode(PORTC, PTC17, 0x00000100);  /* MUX = GPIO, input filter enabled */

}



 /* Notice: the file ends with a blank new line to avoid compiler warnings */