/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: button.c $
 * $Revision: version 1 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23  $
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
 * $Log: button.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "button.h"


/* Constants and types  */
/*============================================================================*/

/* Variables */
/*============================================================================*/



/* Private functions prototypes */
/*============================================================================*/
void Init_Buttons(void);
T_UBYTE Button_Press(void);
T_UBYTE Button_Valid_Debounce(void);
//void Button_Handler(xxx);

/* Inline functions */
/*============================================================================*/
T_UBYTE ButtonUp_Press(){
  return IO_Get_Pin_Data(PTE, PTE5);
}

T_UBYTE ButtonDown_Press(){
  return IO_Get_Pin_Data(PTA, PTA12);
}

T_UBYTE ButtonAntipinch_Press(){
  return IO_Get_Pin_Data(PTA, PTA13);
}


/* Private functions */
/*============================================================================*/

void Init_Buttons(){
  //Wdt_Disable();
  Peripheral_Clock_Enable(PCC_PORTA_INDEX);
  Peripheral_Clock_Enable(PCC_PORTE_INDEX);

  IO_Input_Pin(PTA, 1<<PTA13);          /* Antipinch Button*/
  Configure_Pin_Mode(PORTA, PTA13, 0x00000110);  /* MUX = GPIO, input filter enabled */

  IO_Input_Pin(PTE, 1<<PTE5);          /* Up Button*/
  Configure_Pin_Mode(PORTE, PTE5, 0x00000110);  /* MUX = GPIO, input filter enabled */

  IO_Input_Pin(PTA, 1<<PTA12);          /* Down Button*/
  Configure_Pin_Mode(PORTA, PTA12, 0x00000110);  /* MUX = GPIO, input filter enabled */

}

T_UBYTE ButtonUp_Valid_Debounce(void){
  //T_ULONG count = 0;
  
  if(ButtonUp_Press()){
    Wait_50ms();
    //for(count = 0; count<0x0000FFFF; count++);
    if(ButtonUp_Press())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}

T_UBYTE ButtonDown_Valid_Debounce(void){
  //T_ULONG count = 0;
  
  if(ButtonDown_Press()){
    Wait_50ms();
    //for(count = 0; count<0x0000FFFF; count++);
    if(ButtonDown_Press())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}


T_UBYTE ButtonAntipinch_Valid_Debounce(void){
  //T_ULONG count = 0;
  
  if(ButtonAntipinch_Press()){
    Wait_50ms();
    //for(count = 0; count<0x0000FFFF; count++);
    if(ButtonAntipinch_Press())
      return 1;
    else
      return 0;
  }
  else
    return 0;
}



/* Exported functions */
/*============================================================================*/



 /* Notice: the file ends with a blank new line to avoid compiler warnings */