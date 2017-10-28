/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: port.c $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23  $
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
/*                     |                    |                                 */
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
S_PORT *PORTA = PORTA_Address;
S_PORT *PORTB = PORTB_Address;
S_PORT *PORTC = PORTC_Address;
S_PORT *PORTD = PORTD_Address;
S_PORT *PORTE = PORTE_Address;


/* Private functions prototypes */
/*============================================================================*/
void Configure_Pin_Mode( S_PORT *Port, T_UBYTE Pin, T_ULONG Mode);


/* Inline functions */
/*============================================================================*/
void Configure_Pin_Mode( S_PORT *Port, T_UBYTE Pin, T_ULONG Mode){
  Port->PCR[Pin] = Mode;
}

/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */