/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: 10_segment_bar.h $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
   Header file of 10 Segment LED Bar HAL module.
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
 * $Log: 10_segment_bar.h  $
  ============================================================================*/
#ifndef SEGMENTBAR_H
#define SEGMENTBAR_H

/* Includes */
/*============================================================================*/

//#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\pcc.c"
//#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\port.c"
//#include "C:\Documents_Continental\AEP_2017\Project 1\LED_BAR_LP\MCAL\io.c"

    
/* Constants and types */
/*============================================================================*/

#define PTA9 9		/* Port PTA9, bit 9: Top window segment output W[9] */
#define PTA8 8		/* Port PTA8, bit 8: window segment output W[8] */
#define PTE12 12	/* Port PTE12, bit 12: window segment output W[7] */
#define PTD17 17	/* Port PTD17, bit 17: window segment output W[6] */
#define PTC9 9		/* Port PTC9, bit 9: window segment output W[5] */
#define PTC8 8		/* Port PTC8, bit 8: window segment output W[4] */
#define PTD8 8		/* Port PTD8, bit 8: window segment output W[3] */
#define PTD9 9		/* Port PTD9, bit 9: window segment output W[2] */
#define PTD2 2		/* Port PTD2, bit 2: window segment output W[1] */
#define PTD3 3		/* Port PTD3, bit 3: Bottom window segment output W[0] */
    
/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
