/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: 10_segment_bar.c $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \10_segment_bar.c
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
 * $Log: 10_segment_bar.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "segmentbar.h"


/* Constants and types  */
/*============================================================================*/


/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/
void Init_Bar(void);
void Set_Level_Bar(T_UBYTE level);

/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

/** Check if action is allowed by overload protection.
 To avoid overheating of the door locking motors and hardware failure
 the software shall limit the number of activations in a short period.
 This function checks if the limitation algorithm allows or not
 a certain activation of the motors.
 \returns TRUE if the activation is allowed, FALSE if not
*/
void Init_Bar(void){
  Peripheral_Clock_Enable(PCC_PORTA_INDEX);
  Peripheral_Clock_Enable(PCC_PORTC_INDEX);
  Peripheral_Clock_Enable(PCC_PORTD_INDEX);
  Peripheral_Clock_Enable(PCC_PORTE_INDEX);
  
  IO_Output_Pin(PTA, 1<<PTA8 | 1<<PTA9);
  IO_Output_Pin(PTC, 1<<PTC8 | 1<<PTC9);
  IO_Output_Pin(PTD, 1<<PTD2 | 1<<PTD3 | 1<<PTD8 | 1<<PTD9 | 1<<PTD17);
  IO_Output_Pin(PTE, 1<<PTE12);
  
  Configure_Pin_Mode(PORTA, PTA8, 0x00000100);
  Configure_Pin_Mode(PORTA, PTA9, 0x00000100);
  Configure_Pin_Mode(PORTC, PTC8, 0x00000100);
  Configure_Pin_Mode(PORTC, PTC9, 0x00000100);
  Configure_Pin_Mode(PORTD, PTD2, 0x00000100);
  Configure_Pin_Mode(PORTD, PTD3, 0x00000100);
  Configure_Pin_Mode(PORTD, PTD8, 0x00000100);
  Configure_Pin_Mode(PORTD, PTD9, 0x00000100);
  Configure_Pin_Mode(PORTD, PTD17, 0x00000100);
  Configure_Pin_Mode(PORTE, PTE12, 0x00000100);
}

void Set_Level_Bar(T_UBYTE level){
  switch(level){
  
  case 0: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Clear(PTC, 1<<PTC8);
            IO_Output_Clear(PTD, 1<<PTD8);
            IO_Output_Clear(PTD, 1<<PTD9);
            IO_Output_Clear(PTD, 1<<PTD2);
            IO_Output_Clear(PTD, 1<<PTD3);
            break;
  case 1: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Clear(PTC, 1<<PTC8);
            IO_Output_Clear(PTD, 1<<PTD8);
            IO_Output_Clear(PTD, 1<<PTD9);
            IO_Output_Clear(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 2: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Clear(PTC, 1<<PTC8);
            IO_Output_Clear(PTD, 1<<PTD8);
            IO_Output_Clear(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 3: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Clear(PTC, 1<<PTC8);
            IO_Output_Clear(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 4: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Clear(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 5: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Clear(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 6: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Clear(PTD, 1<<PTD17);
            IO_Output_Set(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 7: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Clear(PTE, 1<<PTE12);
            IO_Output_Set(PTD, 1<<PTD17);
            IO_Output_Set(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 8: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Clear(PTA, 1<<PTA8);
            IO_Output_Set(PTE, 1<<PTE12);
            IO_Output_Set(PTD, 1<<PTD17);
            IO_Output_Set(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 9: 
            IO_Output_Clear(PTA, 1<<PTA9);
            IO_Output_Set(PTA, 1<<PTA8);
            IO_Output_Set(PTE, 1<<PTE12);
            IO_Output_Set(PTD, 1<<PTD17);
            IO_Output_Set(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
  case 10: 
            IO_Output_Set(PTA, 1<<PTA9);
            IO_Output_Set(PTA, 1<<PTA8);
            IO_Output_Set(PTE, 1<<PTE12);
            IO_Output_Set(PTD, 1<<PTD17);
            IO_Output_Set(PTC, 1<<PTC9);
            IO_Output_Set(PTC, 1<<PTC8);
            IO_Output_Set(PTD, 1<<PTD8);
            IO_Output_Set(PTD, 1<<PTD9);
            IO_Output_Set(PTD, 1<<PTD2);
            IO_Output_Set(PTD, 1<<PTD3);
            break;
            
  default: 
            break;
  }
}


/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */