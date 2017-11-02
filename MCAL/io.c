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
/* Habib Apez          |          3         |   Minior changes                */
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
//typedef unsigned char T_UBYTE;


/* Variables */
/*============================================================================*/
/** Pointers to S_GPIO */
S_GPIO *rps_PTA = PTA_Address;
S_GPIO *rps_PTB = PTB_Address;
S_GPIO *rps_PTC = PTC_Address;
S_GPIO *rps_PTD = PTD_Address;
S_GPIO *rps_PTE = PTE_Address;


/* Private functions prototypes */
/*============================================================================*/
void io_InputPin(S_GPIO *lps_Port, T_ULONG lul_Pin);
void io_OutputPin(S_GPIO *lps_Port, T_ULONG lul_Pin);
void io_TogglePin(S_GPIO *lps_Port, T_ULONG lul_Pin);
void io_SetOutput(S_GPIO *lps_Port, T_ULONG lul_Pin);
void io_ClearOutput(S_GPIO *lps_Port, T_ULONG lul_Pin);
T_UBYTE io_GetPinData(S_GPIO *lps_Port, T_UBYTE lul_Pin);


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/
void io_InputPin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PDDR &= ~(lul_Pin);
}

void io_OutputPin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PDDR |= lul_Pin;
}

void io_TogglePin(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PTOR |= lul_Pin;
}

void io_SetOutput(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PSOR |= lul_Pin;
}

void io_ClearOutput(S_GPIO *lps_Port, T_ULONG lul_Pin){
  lps_Port->rul_PCOR |= lul_Pin;
}

T_UBYTE io_GetPinData(S_GPIO *lps_Port, T_UBYTE lul_Pin){
  if((lps_Port->rul_PDIR) & (1<<lul_Pin))
    return 1;
  else 
    return 0;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */
