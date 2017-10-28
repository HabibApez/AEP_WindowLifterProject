/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.h $
 * $Revision: version 2 $
 * $Author: Habib Apez & Estefania L�pez $
 * $Date: 2017-10-28  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \button
    Header file of button HAL module.
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
/*  Author             |        Version     | FILE VERSION (AND INSTANCE)     */
/*----------------------------------------------------------------------------*/
/* Habib Apez          |          1         |   Initial version               */
/* Habib Apez          |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: button.h  $
  ============================================================================*/
#ifndef BUTTON_H
#define BUTTON_H

/* Includes */
/*============================================================================*/
#include "D:\RepoGitSVN\AEP_WindowLifterProject\MCAL\io.c"
#include "D:\RepoGitSVN\AEP_WindowLifterProject\MCAL\port.c"
//#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\wdt.c"

/* Constants and types */
/*============================================================================*/
#define PTE5 5		/* Port PTE5, bit 5: UP_BUTTON intput (UP Button) */
#define PTA12 12	/* Port PTA12, bit 12: DOWN_BUTTON intput (DOWN Button) */
#define PTA13 13	/* Port PTA13, bit 13: ANTIPINCH_BUTTON intput (ANTIPINCH Button) */

/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
