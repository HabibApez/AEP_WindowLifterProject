/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: lpti.h $
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
 * $Log: lpit.h  $
  ============================================================================*/
#ifndef LPIT_H
#define LPIT_H

/* Includes */
/*============================================================================*/
#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\pcc.c"

/* Constants and types */
/*============================================================================*/

/** Peripheral LPITx base addresses */
#define LPIT_BASE_ADDRESS      0X40037000

/** LPIT - Size of Registers Arrays */
#define LPIT_TMR_COUNT          4

typedef unsigned int T_ULONG; 
typedef unsigned char T_UBYTE; 

/** LPIT - Register Layout Typedef */
typedef struct {
  T_ULONG VERID;                             /**< Version ID Register, offset: 0x0 */
  T_ULONG PARAM;                             /**< Parameter Register, offset: 0x4 */
  T_ULONG MCR;                               /**< Module Control Register, offset: 0x8 */
  T_ULONG MSR;                               /**< Module Status Register, offset: 0xC */
  T_ULONG MIER;                              /**< Module Interrupt Enable Register, offset: 0x10 */
  T_ULONG SETTEN;                            /**< Set Timer Enable Register, offset: 0x14 */
  T_ULONG CLRTEN;                            /**< Clear Timer Enable Register, offset: 0x18 */
  T_UBYTE RESERVED_0[4];
  struct {                                         /* offset: 0x20, array step: 0x10 */
    T_ULONG TVAL;                              /**< Timer Value Register, array offset: 0x20, array step: 0x10 */
    T_ULONG CVAL;                              /**< Current Timer Value, array offset: 0x24, array step: 0x10 */
    T_ULONG TCTRL;                             /**< Timer Control Register, array offset: 0x28, array step: 0x10 */
    T_UBYTE RESERVED_0[4];
  } TMR[LPIT_TMR_COUNT];
} S_LPIT; 

/** Peripheral LPIT base pointers*/
#define LPIT_Address ((S_LPIT *)LPIT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
