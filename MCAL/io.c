/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: io.c $
 * $Revision: version 2$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \io.c
    io module for SK32144 uC.
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
 * $Log: io.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
# include "io.h"


/* Constants and types  */
/*============================================================================*/
typedef unsigned char T_UBYTE;


/* Variables */
/*============================================================================*/
/** Pointers to S_GPIO */
S_GPIO *rp_PTA = PTA_Address;
S_GPIO *rp_PTB = PTB_Address;
S_GPIO *rp_PTC = PTC_Address;
S_GPIO *rp_PTD = PTD_Address;
S_GPIO *rp_PTE = PTE_Address;


/* Private functions prototypes */
/*============================================================================*/
void IoInputPin(S_GPIO *lp_Port, T_ULONG l_Pin);
void IoutputPin(S_GPIO *lp_Port, T_ULONG l_Pin);
void IoTogglePin(S_GPIO *lp_Port, T_ULONG l_Pin);
void IoOutputSet(S_GPIO *lp_Port, T_ULONG l_Pin);
void IoOutputClear(S_GPIO *lp_Port, T_ULONG l_Pin);
T_UBYTE IoGetPinData(S_GPIO *lp_Port, T_UBYTE l_Pin);
void IoPinMode(S_GPIO *lp_Port, T_UBYTE l_Pin, T_ULONG l_Mode);


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/
void IoInputPin(S_GPIO *lp_Port, T_ULONG l_Pin){
  lp_Port->ul_PDDR &= ~(l_Pin);
}

void IoOutputPin(S_GPIO *lp_Port, T_ULONG l_Pin){
  lp_Port->ul_PDDR |= l_Pin;
}

void IoTogglePin(S_GPIO *lp_Port, T_ULONG l_Pin){
  lp_Port->ul_PTOR |= l_Pin;
}

void IoOutputSet(S_GPIO *lp_Port, T_ULONG l_Pin){
  lp_Port->ul_PSOR |= l_Pin;
}

void IoOutputClear(S_GPIO *lp_Port, T_ULONG l_Pin){
  lp_Port->ul_PCOR |= l_Pin;
}

T_UBYTE IoGetPinData(S_GPIO *lp_Port, T_UBYTE l_Pin){
  if((lp_Port->ul_PDIR) & (1<<l_Pin))
    return 1;
  else 
    return 0;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
