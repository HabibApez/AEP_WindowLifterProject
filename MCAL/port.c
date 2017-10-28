/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: port.c $
 * $Revision: version 2$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    port module for SK32144 uC.
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
 * $Log: port.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "port.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/
/** Pointers to S_PORT */
S_PORT *rps_PORTA = PORTA_Address;
S_PORT *rps_PORTB = PORTB_Address;
S_PORT *rps_PORTC = PORTC_Address;
S_PORT *rps_PORTD = PORTD_Address;
S_PORT *rps_PORTE = PORTE_Address;


/* Private functions prototypes */
/*============================================================================*/
void port_ConfigurePinMode(S_PORT *lps_Port, T_UBYTE lub_Pin, T_ULONG lul_Mode);


/* Inline functions */
/*============================================================================*/


/* Private functions */
/*============================================================================*/


/* Exported functions */
/*============================================================================*/
void Configure_Pin_Mode(S_PORT *lps_Port, T_UBYTE lub_Pin, T_ULONG lul_Mode){
  lps_Port->raul_PCR[lub_Pin] = lul_Mode;
}

 /* Notice: the file ends with a blank new line to avoid compiler warnings */