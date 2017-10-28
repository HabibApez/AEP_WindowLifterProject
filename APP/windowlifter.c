/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: windowlifter.c $
 * $Revision: version 2 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \file
    Source of windowlifter.c
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
 * $Log: windowlifter.c  $
  ============================================================================*/

/* Includes */
/*============================================================================*/
#include "windowlifter.h"


/* Constants and types  */
/*============================================================================*/
#define TOP 10
#define BOTTON 0   
    
/* Variables */
/*============================================================================*/
T_UBYTE Up_Flag, Down_Flag, level = 0;



/* Private functions prototypes */
/*============================================================================*/
void Antipinch(void);


/* Inline functions */
/*============================================================================*/

/*
void Wait_50ms(){
  T_ULONG x;
  for(x = 0; x < 0x0000FFFF; x++);       
}

void Wait_400ms(){
  T_ULONG x;
  for(x = 0; x < 0x000FFFFF; x++);       
}

void Wait_5s(){
  T_ULONG x;
  for(x = 0; x < 0x01FFFFFF; x++);       
}

void Wait_450ms(){
  Wait_400ms();
  Wait_50ms();
}


void Turn_On_UpLED(void){
  PTE-> PSOR |= 1<<PTE4;
}

void Turn_On_DownLED(void){
  PTD-> PSOR |= 1<<PTD1;
}

void Turn_On_AntipinchLED(void){
  PTC-> PSOR |= 1<<PTC17;
}

void Turn_Off_UpLED(void){
  PTE-> PCOR |= 1<<PTE4;
}

void Turn_Off_DownLED(void){
  PTD-> PCOR |= 1<<PTD1;
}

void Turn_Off_AntipinchLED(void){
  PTC-> PCOR |= 1<<PTC17;
}
*/


/* Private functions */
/*============================================================================*/

void UpNormal(void){
  if(ButtonAntipinch_Valid_Debounce()){
    Antipinch();
  }
  else {
    if(level<TOP){
      Turn_On_UpLED();
      level++;
      Wait_400ms();
      Set_Level_Bar(level);
      Turn_Off_UpLED();
    }
  }
}


void DownNormal(void){
  if(level>BOTTON){
    Turn_On_DownLED();
    level--;
    Wait_400ms();
    Set_Level_Bar(level);
    Turn_Off_DownLED();
  }
}

void OneTouchUp(void){
  while(level<TOP & Up_Flag){
    if(ButtonDown_Valid_Debounce())
      Up_Flag = 0;
    if(Up_Flag)
      UpNormal(); //Verify if it comes from a onetouch
  }
}


void OneTouchDown(void){

  while(level>BOTTON & Down_Flag){ 
    if(ButtonUp_Valid_Debounce())
      Down_Flag = 0;
    if(Down_Flag)
    DownNormal();       
  }
}

void Antipinch(void){
  Turn_Off_UpLED();
  Up_Flag = 0;
  Down_Flag = 1;
  Turn_On_AntipinchLED();          
  OneTouchDown();
  Wait_5s();
  Turn_Off_AntipinchLED();
  
}

/** Check if action is allowed by overload protection.



*/
/* Exported functions */
/*============================================================================*/


int main(void)              
{
    Init_Clock();
    Init_Buttons();
    Init_Leds();
    Init_Bar();
    Init_Timer();
    
 /*
    for(;;) {
      
      if(ButtonUp_Valid_Debounce()){
        Turn_On_UpLED();
        Wait_400ms();
        Turn_Off_UpLED();
      }
      if(ButtonDown_Valid_Debounce()){
        Turn_On_DownLED();
        Wait_400ms();
        Turn_Off_DownLED();
      }
      if(ButtonAntipinch_Valid_Debounce()){
        Turn_On_AntipinchLED();
        Wait_400ms();
        Turn_Off_AntipinchLED();
      }
    }
      
*/
        
    for(;;){
        
      start:
        if(ButtonUp_Valid_Debounce()){
          Up_Flag = 1;
          Wait_450ms();
          if(ButtonUp_Press()){
            Up_normal:
              UpNormal();
              if(ButtonUp_Press())
                goto Up_normal;
              else
                goto start;
          }
          else{
            OneTouchUp();
            if(Up_Flag==0)
              Wait_400ms();
            goto start;
          }
          Up_Flag = 0;
        }
        else {
          if(ButtonDown_Valid_Debounce()){
            Down_Flag = 1;
            Wait_450ms();
            if(ButtonDown_Press()){
              Down_normal:
                DownNormal();
                if(ButtonDown_Press())
                  goto Down_normal;
                else
                  goto start;
              }
              else {
                OneTouchDown();
                if(Down_Flag==0)
                  Wait_400ms();
                goto start;
              }
            Down_Flag = 0;
            }
            else 
              goto start;
            }
          }
        
  return 0;
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
