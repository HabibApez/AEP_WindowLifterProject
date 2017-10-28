/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: timer.c $
 * $Revision: version 2$
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
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
void timer_InitTimer(void);
void timer_Wait50ms(void);
void timer_Wait400ms(void);
void timer_Wait450ms(void);
void timer_Wait5s(void);

/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/


void timer_InitTimer(void){
  lpit_EnableLPITO();
}

void timer_Wait50ms(void){
  lpit_ChargeLPITOCh0(2000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

void timer_Wait400ms(void){
  lpit_ChargeLPITOCh0(16000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

void timer_Wait450ms(void){
  timer_Wait400ms();
  timer_Wait50ms();
}

void timer_Wait5s(void){
  lpit_ChargeLPITOCh0(200000000);
  lpit_EnableLPIT0Ch0();
  while(0 == lpit_ChecklFlagLPIT0Ch0());
  lpit_ClearFlagLPIT0Ch0();
  lpit_DisableLPIT0Ch0();
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */