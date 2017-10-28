/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: leds.h $
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
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: led.h  $
  ============================================================================*/
#ifndef LED_H
#define LED_H

/* Includes */
/*============================================================================*/
//#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\io.c"

/* Constants and types */
/*============================================================================*/

#define PTE4 4		/* Port PTE4, bit 4: UP_LED output (blue LED) */
#define PTC17 17	/* Port PTC17, bit 17: ANTIPINCH_LED output (red LED) */
#define PTD1 1		/* Port PTD1, bit 1: DOWN_LED output (green LED) */    
 

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
