/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: 10_segment_bar.c $
 * $Revision: version 2$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \10_segment_bar.c
    short description in one sentence end with dot.
    detailed
    multiline
    description of the file
    Source file of 10 Segment LED Bar HAL module.
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
/* Estefania López     |          2         |   Naming conventions            */
/*                     |                    |   and MISRA checked             */
/*============================================================================*/
/*                               OBJECT HISTORY                               */
/*============================================================================*/
/*
 * $Log: segmentbar.c  $
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
void segmentbar_InitBar(void);
void segmentbar_SetLevelBar(T_UBYTE lub_level);

/* Inline functions */
/*============================================================================*/




/* Private functions */
/*============================================================================*/

void segmentbar_InitBar(void){
  pcc_EnablePeripheralClock(PCC_rps_PORTA_INDEX);
  pcc_EnablePeripheralClock(PCC_rps_PORTC_INDEX);
  pcc_EnablePeripheralClock(PCC_rps_PORTD_INDEX);
  pcc_EnablePeripheralClock(PCC_rps_PORTE_INDEX);
  
  io_Output_Pin(rps_PTA, 1<<rps_PTA8 | 1<<rps_PTA9);
  io_Output_Pin(rps_PTC, 1<<rps_PTC8 | 1<<rps_PTC9);
  io_Output_Pin(rps_PTD, 1<<rps_PTD2 | 1<<rps_PTD3 | 1<<rps_PTD8 | 1<<rps_PTD9 | 1<<rps_PTD17);
  io_Output_Pin(rps_PTE, 1<<rps_PTE12);
  
  port_ConfigurePinMode(rps_PORTA, rps_PTA8, 0x00000100);
  port_ConfigurePinMode(rps_PORTA, rps_PTA9, 0x00000100);
  port_ConfigurePinMode(rps_PORTC, rps_PTC8, 0x00000100);
  port_ConfigurePinMode(rps_PORTC, rps_PTC9, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, rps_PTD2, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, rps_PTD3, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, rps_PTD8, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, rps_PTD9, 0x00000100);
  port_ConfigurePinMode(rps_PORTD, rps_PTD17, 0x00000100);
  port_ConfigurePinMode(rps_PORTE, rps_PTE12, 0x00000100);
}

void segmentbar_SetLevelBar(T_UBYTE lub_level){
  switch(lub_level){
  
  case 0: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_ClearOutput(rps_PTC, 1<<rps_PTC8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD9);
            io_ClearOutput(rps_PTD, 1<<rps_PTD2);
            io_ClearOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 1: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_ClearOutput(rps_PTC, 1<<rps_PTC8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD9);
            io_ClearOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 2: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_ClearOutput(rps_PTC, 1<<rps_PTC8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 3: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_ClearOutput(rps_PTC, 1<<rps_PTC8);
            io_ClearOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 4: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_ClearOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 5: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_ClearOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 6: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_ClearOutput(rps_PTD, 1<<rps_PTD17);
            io_SetOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 7: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_ClearOutput(rps_PTE, 1<<rps_PTE12);
            io_SetOutput(rps_PTD, 1<<rps_PTD17);
            io_SetOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 8: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_ClearOutput(rps_PTA, 1<<rps_PTA8);
            io_SetOutput(rps_PTE, 1<<rps_PTE12);
            io_SetOutput(rps_PTD, 1<<rps_PTD17);
            io_SetOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 9: 
            io_ClearOutput(rps_PTA, 1<<rps_PTA9);
            io_SetOutput(rps_PTA, 1<<rps_PTA8);
            io_SetOutput(rps_PTE, 1<<rps_PTE12);
            io_SetOutput(rps_PTD, 1<<rps_PTD17);
            io_SetOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
  case 10: 
            io_SetOutput(rps_PTA, 1<<rps_PTA9);
            io_SetOutput(rps_PTA, 1<<rps_PTA8);
            io_SetOutput(rps_PTE, 1<<rps_PTE12);
            io_SetOutput(rps_PTD, 1<<rps_PTD17);
            io_SetOutput(rps_PTC, 1<<rps_PTC9);
            io_SetOutput(rps_PTC, 1<<rps_PTC8);
            io_SetOutput(rps_PTD, 1<<rps_PTD8);
            io_SetOutput(rps_PTD, 1<<rps_PTD9);
            io_SetOutput(rps_PTD, 1<<rps_PTD2);
            io_SetOutput(rps_PTD, 1<<rps_PTD3);
            break;
            
  default: 
            break;
  }
}


/* Exrps_PORTEd functions */
/*============================================================================*/


 /* Notice: the file ends with a blank new line to avoid compiler warnings */