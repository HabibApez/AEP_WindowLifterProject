/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: windowlifter.c $
 * $Revision: version 3 $
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
T_UBYTE lub_UpFlag, lub_DownFlag, lub_AntipinchFlag, lub_Level = 0;

/* Private functions prototypes */
/*============================================================================*/
void windowlifter_UpNormal(void);
void windowlifter_DownNormal(void);
void windowlifter_OneTouchUp(void);
void windowlifter_OneTouchDown(void);
void windowlifter_Antipinch(void);

/* Inline functions */
/*============================================================================*/

/* Private functions */
/*============================================================================*/

void windowlifter_UpNormal(void){
  if(button_DebounceButtonAntipinch()){
    windowlifter_Antipinch();
  }
  else {
    if(lub_Level<TOP){
      leds_TurnOnUpLED();
      lub_Level++;
      timer_Wait400ms();
      segmentbar_SetLevelBar(lub_Level, lub_UpFlag, lub_DownFlag);
      leds_TurnOffUpLED();
    }
  }
}


void windowlifter_DownNormal(void){
  if(lub_Level>BOTTON){
    leds_TurnOnDownLED();
    lub_Level--;
    timer_Wait400ms();
    segmentbar_SetLevelBar(lub_Level, lub_UpFlag, lub_DownFlag);
    leds_TurnOffDownLED();
  }
}

void windowlifter_OneTouchUp(void){
  while(lub_Level<TOP & lub_UpFlag){
    if(button_DebounceButtonDown())
      lub_UpFlag = 0;
    if(lub_UpFlag)
      windowlifter_UpNormal(); //Verify if it comes from a onetouch
  }
}


void windowlifter_OneTouchDown(void){

  while(lub_Level>BOTTON & lub_DownFlag){ 
    if(button_DebounceButtonUp() && (lub_AntipinchFlag == 0))
      lub_DownFlag = 0;
    if(lub_DownFlag)
    windowlifter_DownNormal();       
  }
}

void windowlifter_Antipinch(void){
  lub_AntipinchFlag = 1;
  leds_TurnOffUpLED();
  lub_UpFlag = 0;
  lub_DownFlag = 1;
  leds_TurnOnAntipinchLED();          
  windowlifter_OneTouchDown();
  timer_Wait5s();
  leds_TurnOffAntipinchLED();  
  lub_AntipinchFlag = 0;
}

/** Check if action is allowed by overload protection.



*/
/* Exported functions */
/*============================================================================*/


void main(void)              
{
    clock_InitClock();
    button_InitButtons();
    leds_InitLeds();
    segmentbar_InitBar();
    timer_InitTimer();
    
    for(;;){
        
      start:
        if(button_DebounceButtonUp()){
          lub_UpFlag = 1;
          timer_Wait490ms();
          if(button_CheckButtonUp()){
            Up_normal:
              lub_UpFlag = 1;
              windowlifter_UpNormal();
              if(button_CheckButtonUp()){
                lub_UpFlag = 0;
                goto Up_normal;
              }
              else {
                lub_UpFlag = 0;
                goto start;
              }
          }
          else{
            windowlifter_OneTouchUp();
            if(lub_UpFlag==0)
              timer_Wait400ms();
            lub_UpFlag = 0;
            goto start;
          }
        }
        else {
          if(button_DebounceButtonDown()){
            lub_DownFlag = 1;
            timer_Wait490ms();
            if(button_CheckButtonDown()){
              Down_normal:
                lub_DownFlag = 1;
                windowlifter_DownNormal();
                if(button_CheckButtonDown()){
                  lub_DownFlag = 0;
                  goto Down_normal;
                }
                else {
                  lub_DownFlag = 0;
                  goto start;
                }
              }
              else {
                windowlifter_OneTouchDown();
                if(lub_DownFlag==0)
                  timer_Wait400ms();
                lub_DownFlag = 0;
                goto start;
              }
            }
            else 
              goto start;
        }
    }
}
 /* Notice: the file ends with a blank new line to avoid compiler warnings */
