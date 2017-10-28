/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: pcc.c $
 * $Revision: version 2$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    pcc module for SK32144 uC.
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
 * $Log: pcc.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "pcc.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
S_PCC *rps_PCC = PCC_Address;


/* Private functions prototypes */
/*============================================================================*/
void pcc_EnablePeripheralClock(T_UBYTE lub_PeripheralId);


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/

void pcc_EnablePeripheralClock(T_UBYTE lub_PeripheralId){
  rps_PCC-> raul_PCCn[lub_PeripheralId] = 0x40000000;
}


 /* Notice: the file ends with a blank new line to avoid compiler warnings */