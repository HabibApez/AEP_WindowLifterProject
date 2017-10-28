/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: lpti.c $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-25 $
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
 * $Log: lpit.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "lpit.h"


/* Constants and types  */
/*============================================================================*/



/* Variables */
/*============================================================================*/
/** Pointers to S_LPIT */
S_LPIT *LPIT0 = LPIT_Address;


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/
void LPITO_Enable(void){
  PCC->PCCn[PCC_LPIT_INDEX] = 0x06000000; /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  PCC->PCCn[PCC_LPIT_INDEX] |= 0x40000000; /* Enable clk to LPIT0 regs */
	
  LPIT0->MCR = 0x00000001; 	/* DBG_EN-0: Timer chans stop in Debug mode */
                                /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                                /* SW_RST=0: SW reset does not reset timer chans, regs */
                                /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
}

void LPITO_Ch0_Charge(T_ULONG value){
  LPIT0->TMR[0].TVAL = value; /* Chan 0 Timeout period: 40M clocks */
}

void LPIT0_Ch0_Enable(void){
  LPIT0->TMR[0].TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
}						

void LPIT0_Ch0_Disable(void){
  LPIT0->TMR[0].TCTRL = 0x00000000; /* T_EN=0: Timer channel is enabled */
}			

T_UBYTE LPIT0_Ch0_Status_Flag(void){
  return (LPIT0->MSR & 0x01);
}

void LPIT0_Ch0_Clear_Flag(void){
  LPIT0->MSR |= 0x01;
}


/* Private functions */
/*============================================================================*/




/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */