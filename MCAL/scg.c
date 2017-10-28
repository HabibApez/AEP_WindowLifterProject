/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: scg.c $
 * $Revision: version 1 $
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
S_SCG *SCG = SCG_Address;


/* Private functions prototypes */
/*============================================================================*/



/* Inline functions */
/*============================================================================*/



/* Private functions */
/*============================================================================*/

void CONFIG_SOSC_8MHZ(void){
	Wdt_Disable();
        SCG->SOSCDIV=0x00000101; 	/* SOSCDIV1 & SOSCDIV2 =1: divide by 1 */
	SCG->SOSCCFG=0x00000024; 	/* Range=2: Medium freq (SOSC between 1MHz-8MHz)*/
                                        /* HGO=0: Config xtal osc for low power */
					/* EREFS=1: Input is external XTAL */
	while(SCG->SOSCCSR & 0x800000);/* Ensure SOSCCSR unlocked */
	SCG->SOSCCSR=0x00000001; 	/* LK=0: SOSCCSR can be written */
					/* SOSCCMRE=0: OSC CLK monitor IRQ if enabled */
					/* SOSCCM=0: OSC CLK monitor disabled */
					/* SOSCERCLKEN=0: Sys OSC 3V ERCLK output clk disabled */
					/* SOSCLPEN=0: Sys OSC disabled in VLP modes */
					/* SOSCSTEN=0: Sys OSC disabled in Stop modes */
					/* SOSCEN=1: Enable oscillator */
	while(!(SCG->SOSCCSR & 0x1000000)); /* Wait for sys OSC clk valid */
}


void CONFIG_SPLL_160MHZ(void){
	while(SCG->SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000000; 	/* SPLLEN=0: SPLL is disabled (default) */
	SCG->SPLLDIV = 0x00000302; 	/* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
	SCG->SPLLCFG = 0x00180000; 	/* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
					/* MULT=24: Multiply sys pll by 4+24=40 */
					/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz */
	while(SCG->SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000001; 	/* LK=0: SPLLCSR can be written */
					/* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
					/* SPLLCM=0: SPLL CLK monitor disabled */
					/* SPLLSTEN=0: SPLL disabled in Stop modes */
					/* SPLLEN=1: Enable SPLL */
	while(!(SCG->SPLLCSR & 0x1000000)); /* Wait for SPLL valid */
}

void CONFIG_RUN_mode(void){
	while(SCG->SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000000; 	/* SPLLEN=0: SPLL is disabled (default) */
	SCG->SPLLDIV = 0x00000302; 	/* SPLLDIV1 divide by 2; SPLLDIV2 divide by 4 */
	SCG->SPLLCFG = 0x00180000; 	/* PREDIV=0: Divide SOSC_CLK by 0+1=1 */
					/* MULT=24: Multiply sys pll by 4+24=40 */
					/* SPLL_CLK = 8MHz / 1 * 40 / 2 = 160 MHz */
	while(SCG->SPLLCSR & 0x800000); /* Ensure SPLLCSR unlocked */
	SCG->SPLLCSR = 0x00000001; 	/* LK=0: SPLLCSR can be written */
					/* SPLLCMRE=0: SPLL CLK monitor IRQ if enabled */
					/* SPLLCM=0: SPLL CLK monitor disabled */
					/* SPLLSTEN=0: SPLL disabled in Stop modes */
					/* SPLLEN=1: Enable SPLL */
	while(!(SCG->SPLLCSR & 0x1000000)); /* Wait for SPLL valid */
}

/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */