/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: lpti.c $
 * $Revision: version 2$
 * $Author: Habib Apez & Estefania L�pez $
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
S_LPIT *rps_LPIT0 = LPIT_Address;


/* Private functions prototypes */
/*============================================================================*/
void lpit_EnableLPITO(void);
void lpit_ChargeLPITOCh0(T_ULONG lul_value);
void lpit_EnableLPIT0Ch0(void);
void lpit_DisableLPIT0Ch0(void);
T_UBYTE lpit_ChecklFlagLPIT0Ch0(void);
void lpit_ClearFlagLPIT0Ch0(void);

/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void lpit_EnableLPITO(void){
  rps_PCC->raul_PCCn[PCC_LPIT_INDEX] = 0x06000000; /* Clock Src = 6 (SPLL2_DIV2_CLK)*/
  rps_PCC->raul_PCCn[PCC_LPIT_INDEX] |= 0x40000000; /* Enable clk to LPIT0 regs */
	
  rps_LPIT0->rul_MCR = 0x00000001; 	/* DBG_EN-0: Timer chans stop in Debug mode */
                                /* DOZE_EN=0: Timer chans are stopped in DOZE mode */
                                /* SW_RST=0: SW reset does not reset timer chans, regs */
                                /* M_CEN=1: enable module clk (allows writing other LPIT0 regs)*/
}

void lpit_ChargeLPITOCh0(T_ULONG lul_value){
  rps_LPIT0->S_TMR[0].rul_TVAL = lul_value; /* Chan 0 Timeout period: 40M clocks */
}

void lpit_EnableLPIT0Ch0(void){
  rps_LPIT0->S_TMR[0].rul_TCTRL = 0x00000001; /* T_EN=1: Timer channel is enabled */
}						

void lpit_DisableLPIT0Ch0(void){
  rps_LPIT0->S_TMR[0].rul_TCTRL = 0x00000000; /* T_EN=0: Timer channel is enabled */
}			

T_UBYTE lpit_ChecklFlagLPIT0Ch0(void){
  return (rps_LPIT0->rul_MSR & 0x01);
}

void lpit_ClearFlagLPIT0Ch0(void){
  rps_LPIT0->rul_MSR |= 0x01;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */