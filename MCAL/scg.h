/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: scg.h $
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
 * $Log: filename.h  $
  ============================================================================*/
#ifndef SCG_H
#define SCG_H

/* Includes */
/*============================================================================*/
#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\wdt.c"

typedef unsigned int T_ULONG; 
typedef unsigned char T_UBYTE; 

/* Constants and types */
/*============================================================================*/

/** Peripheral SCG base addresses */
#define SCG_BASE_ADDRESS 0x40064000

/** SCG - Register Layout Typedef */
typedef struct {
  T_ULONG VERID;                             /**< Version ID Register, offset: 0x0 */
  T_ULONG PARAM;                             /**< Parameter Register, offset: 0x4 */
  T_UBYTE RESERVED_0[8];
  T_ULONG CSR;                               /**< Clock Status Register, offset: 0x10 */
  T_ULONG RCCR;                              /**< Run Clock Control Register, offset: 0x14 */
  T_ULONG VCCR;                              /**< VLPR Clock Control Register, offset: 0x18 */
  T_ULONG HCCR;                              /**< HSRUN Clock Control Register, offset: 0x1C */
  T_ULONG CLKOUTCNFG;                        /**< SCG CLKOUT Configuration Register, offset: 0x20 */
  T_UBYTE RESERVED_1[220];
  T_ULONG SOSCCSR;                           /**< System OSC Control Status Register, offset: 0x100 */
  T_ULONG SOSCDIV;                           /**< System OSC Divide Register, offset: 0x104 */
  T_ULONG SOSCCFG;                           /**< System Oscillator Configuration Register, offset: 0x108 */
  T_UBYTE RESERVED_2[244];
  T_ULONG SIRCCSR;                           /**< Slow IRC Control Status Register, offset: 0x200 */
  T_ULONG SIRCDIV;                           /**< Slow IRC Divide Register, offset: 0x204 */
  T_ULONG SIRCCFG;                           /**< Slow IRC Configuration Register, offset: 0x208 */
  T_UBYTE RESERVED_3[244];
  T_ULONG FIRCCSR;                           /**< Fast IRC Control Status Register, offset: 0x300 */
  T_ULONG FIRCDIV;                           /**< Fast IRC Divide Register, offset: 0x304 */
  T_ULONG FIRCCFG;                           /**< Fast IRC Configuration Register, offset: 0x308 */
  T_UBYTE RESERVED_4[756];
  T_ULONG SPLLCSR;                           /**< System PLL Control Status Register, offset: 0x600 */
  T_ULONG SPLLDIV;                           /**< System PLL Divide Register, offset: 0x604 */
  T_ULONG SPLLCFG;                           /**< System PLL Configuration Register, offset: 0x608 */
} S_SCG;

/** Peripheral SCG base pointers*/
#define SCG_Address ((S_SCG *)SCG_BASE_ADDRESS)


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
