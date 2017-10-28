/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: io.c $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23 $
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/*                     |                    |                                 */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: io.c.c  $
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
S_GPIO *PTA = PTA_Address;
S_GPIO *PTB = PTB_Address;
S_GPIO *PTC = PTC_Address;
S_GPIO *PTD = PTD_Address;
S_GPIO *PTE = PTE_Address;


/* Private functions prototypes */
/*============================================================================*/
void IO_Input_Pin(S_GPIO *Port, T_ULONG Pin);
void IO_Output_Pin(S_GPIO *Port, T_ULONG Pin);
void IO_Toggle_Pin(S_GPIO *Port, T_ULONG Pin);
void IO_Output_Set(S_GPIO *Port, T_ULONG Pin);
void IO_Output_Clear(S_GPIO *Port, T_ULONG Pin);
T_UBYTE IO_Get_Pin_Data(S_GPIO *Port, T_UBYTE Pin);
void IO_Pin_Mode(S_GPIO *Port, T_UBYTE Pin, T_ULONG Mode);


/* Inline functions */
/*============================================================================*/
void IO_Input_Pin(S_GPIO *Port, T_ULONG Pin){
  Port->PDDR &= ~(Pin);
}

void IO_Output_Pin(S_GPIO *Port, T_ULONG Pin){
  Port->PDDR |= Pin;
}

void IO_Toggle_Pin(S_GPIO *Port, T_ULONG Pin){
  Port->PTOR |= Pin;
}

void IO_Output_Set(S_GPIO *Port, T_ULONG Pin){
  Port->PSOR |= Pin;
}

void IO_Output_Clear(S_GPIO *Port, T_ULONG Pin){
  Port->PCOR |= Pin;
}

T_UBYTE IO_Get_Pin_Data(S_GPIO *Port, T_UBYTE Pin){
  if((Port->PDIR) & (1<<Pin))
    return 1;
  else 
    return 0;
}


/* Private functions */
/*============================================================================*/



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */
