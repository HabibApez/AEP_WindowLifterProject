/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: wdt.h $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-24 $
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
#ifndef WDT_H
#define WDT_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/

typedef unsigned int T_ULONG; 
typedef unsigned char T_UBYTE; 

/** Peripheral WDT base addresses */
#define WDT_BASE_ADDRESS      0x40052000

/** WDOG - Register Layout Typedef */
typedef struct {
  T_ULONG CS;                                /**< Watchdog Control and Status Register, offset: 0x0 */
  T_ULONG CNT;                               /**< Watchdog Counter Register, offset: 0x4 */
  T_ULONG TOVAL;                             /**< Watchdog Timeout Value Register, offset: 0x8 */
  T_ULONG WIN;                               /**< Watchdog Window Register, offset: 0xC */
} S_WDT;

/** Peripheral WDT base pointers*/
#define WDT_Address ((S_WDT *)WDT_BASE_ADDRESS)

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
