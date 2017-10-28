/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: io.h $
 * $Revision: version 1$
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-23 $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \io.h
    Header file of io module for SK32144 uC.
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
 * $Log: io.h  $
  ============================================================================*/
#ifndef IO_H
#define IO_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/

/** Peripheral GPIO base addresses */
#define GPIOA_BASE_ADDRESS      0X400FF000
#define GPIOB_BASE_ADDRESS      0X400FF040
#define GPIOC_BASE_ADDRESS      0X400FF080
#define GPIOD_BASE_ADDRESS      0X400FF0C0
#define GPIOE_BASE_ADDRESS      0X400FF100

//typedef unsigned int T_ULONG; 

/** GPIO - Register Layout Typedef */
typedef struct {
  T_ULONG rul_PDOR;                   /**< Port Data Output Register,          offset: 0x00 */
  T_ULONG rul_PSOR;                   /**< Port Set Output Register,           offset: 0x04 */
  T_ULONG rul_PCOR;                   /**< Port Clear Output Register,         offset: 0x08 */
  T_ULONG rul_PTOR;                   /**< Port Toggle Output Register,        offset: 0x0C */
  T_ULONG rul_PDIR;                   /**< Port Data Input Register,           offset: 0x10 */
  T_ULONG rul_PDDR;                   /**< Port Data Direction Register,       offset: 0x14 */
  T_ULONG rul_PIDR;                   /**< Port Input Disable Register,        offset: 0x18 */

} S_GPIO; 

/** Peripheral PTx base pointers*/
#define PTA_Address ((S_GPIO *)GPIOA_BASE_ADDRESS)
#define PTB_Address ((S_GPIO *)GPIOB_BASE_ADDRESS)
#define PTC_Address ((S_GPIO *)GPIOC_BASE_ADDRESS)
#define PTD_Address ((S_GPIO *)GPIOD_BASE_ADDRESS)
#define PTE_Address ((S_GPIO *)GPIOE_BASE_ADDRESS)



/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
