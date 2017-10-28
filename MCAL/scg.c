/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: scg.c $
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
/*  DATABASE           |        PROJECT     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: scg.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "scg.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/

/** Pointers to S_SCG */
S_SCG *ras_SCG = SCG_Address;

/* Private functions prototypes */
/*============================================================================*/
void scg_ConfigSOSC8mhz(void);
void scg_ConfigSPLL160mhz(void);
void scg_ConfigRunMode(void);

/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void scg_ConfigSOSC8mhz(void){
	wdt_DisableWdt();
        ras_SCG->rul_SOSCDIV=0x00000101; 	/* SOSCDIV1 & SOSCDIV2 =1: divide by 1 */
	ras_SCG->rul_SOSCCFG=0x00000024; 	/* Range=2: Medium freq (SOSC between 1MHz-8MHz)*/
                                        /* HGO=0: Config xtal osc for low power */
					/* EREFS=1: Input is external XTAL */
	while(ras_SCG->rul_SOSCCSR & 0x800000);/* Ensure SOSCCSR unlocked */
	ras_SCG->rul_SOSCCSR=0x00000001; 	/* LK=0: SOSCCSR can be written */
					/* SOSCCMRE=0: OSC CLK monitor IRQ if enabled */
					/* SOSCCM=0: OSC CLK monitor disabled */
					/* SOSCERCLKEN=0: Sys OSC 3V ERCLK output clk disabled */
					/* SOSCLPEN=0: Sys OSC disabled in VLP modes */
					/* SOSCSTEN=0: Sys OSC disabled in Stop modes */
					/* SOSCEN=1: Enable oscillator */
	while(!(ras_SCG->rul_SOSCCSR & 0x1000000)); /* Wait for sys OSC clk valid */
}


void scg_ConfigSPLL160mhz(void){
	while(ras_SCG->SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	ras_SCG->rul_SPLLCSR = 0x00000000; 	/* SPLLEN=0: SPLL is disabled (default) */
	ras_SCG->rul_SPLLDIV = 0x00000302; 	/* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
	ras_SCG->rul_SPLLCFG = 0x00180000; 	/* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
					/* MULT=24: Multiply sys pll by 4+24=40 */
					/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz */
	while(ras_SCG->rul_SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	ras_SCG->rul_SPLLCSR = 0x00000001; 	/* LK=0: SPLLCSR can be written */
					/* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
					/* SPLLCM=0: SPLL CLK monitor disabled */
					/* SPLLSTEN=0: SPLL disabled in Stop modes */
					/* SPLLEN=1: Enable SPLL */
	while(!(ras_SCG->rul_SPLLCSR & 0x1000000)); /* Wait for SPLL valid */
}

void scg_ConfigRunMode(void){
	while(ras_SCG->rul_SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	ras_SCG->rul_SPLLCSR = 0x00000000; 	/* SPLLEN=0: SPLL is disabled (default) */
	ras_SCG->rul_SPLLDIV = 0x00000302; 	/* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
	ras_SCG->rul_SPLLCFG = 0x00180000; 	/* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
					/* MULT=24: Multiply sys pll by 4+24=40 */
					/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz */
	while(ras_SCG->rul_SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	ras_SCG->rul_SPLLCSR = 0x00000001; 	/* LK=0: SPLLCSR can be written */
					/* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
					/* SPLLCM=0: SPLL CLK monitor disabled */
					/* SPLLSTEN=0: SPLL disabled in Stop modes */
					/* SPLLEN=1: Enable SPLL */
	while(!(ras_SCG->rul_SPLLCSR & 0x1000000)); /* Wait for SPLL valid */
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */