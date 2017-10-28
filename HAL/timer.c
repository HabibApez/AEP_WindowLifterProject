/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: timer.c $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23 $
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
 * $Log: filename.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "timer.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/
void Init_Timer(void){
  LPITO_Enable();
}

void Wait_50ms(void){
  LPITO_Ch0_Charge(2000000);
  LPIT0_Ch0_Enable();
  while(0 == LPIT0_Ch0_Status_Flag());
  LPIT0_Ch0_Clear_Flag();
  LPIT0_Ch0_Disable();
}

void Wait_400ms(void){
  LPITO_Ch0_Charge(16000000);
  LPIT0_Ch0_Enable();
  while(0 == LPIT0_Ch0_Status_Flag());
  LPIT0_Ch0_Clear_Flag();
  LPIT0_Ch0_Disable();
}

void Wait_450ms(void){
  Wait_400ms();
  Wait_50ms();
}

void Wait_5s(void){
  LPITO_Ch0_Charge(200000000);
  LPIT0_Ch0_Enable();
  while(0 == LPIT0_Ch0_Status_Flag());
  LPIT0_Ch0_Clear_Flag();
  LPIT0_Ch0_Disable();
}


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */