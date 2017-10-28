/*============================================================================*/
/*                        I BS SOFTWARE GROUP                                 */
/*============================================================================*/
/*                        OBJECT SPECIFICATION                                */
/*============================================================================*/
/*!
 * $Source: pcc.h $
 * $Revision: version 2 $
 * $Author: Habib Apez & Estefania López $
 * $Date: 2017-10-28  $
 */
/*============================================================================*/
/* DESCRIPTION :                                                              */
/** \pcc.h
    Header file of pcc module for SK32144 uC.
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
 * $Log: pcc.h  $
  ============================================================================*/

#ifndef PCC_H
#define PCC_H

/* Includes */
/*============================================================================*/


/* Constants and types */
/*============================================================================*/

    
typedef unsigned char T_UBYTE; 
    
    
/** Peripheral PCC base addresses */
#define PCC_BASE_ADDRESS        0x40065000
#define PCC_PCCn_COUNT          116

typedef unsigned int T_ULONG; 

/** PCC - Register Layout Typedef */
typedef struct {
  T_ULONG raul_PCCn[PCC_PCCn_COUNT];                   /**< Port Data Output Register,          offset: 0x00 */
} S_PCC; 

/** Peripheral PCC base pointers*/
#define PCC_Address ((S_PCC *)PCC_BASE_ADDRESS)



/* PCC index offsets */
#define PCC_FTFC_INDEX                           32
#define PCC_DMAMUX_INDEX                         33
#define PCC_FlexCAN0_INDEX                       36
#define PCC_FlexCAN1_INDEX                       37
#define PCC_FTM3_INDEX                           38
#define PCC_ADC1_INDEX                           39
#define PCC_FlexCAN2_INDEX                       43
#define PCC_LPSPI0_INDEX                         44
#define PCC_LPSPI1_INDEX                         45
#define PCC_LPSPI2_INDEX                         46
#define PCC_PDB1_INDEX                           49
#define PCC_CRC_INDEX                            50
#define PCC_PDB0_INDEX                           54
#define PCC_LPIT_INDEX                           55
#define PCC_FTM0_INDEX                           56
#define PCC_FTM1_INDEX                           57
#define PCC_FTM2_INDEX                           58
#define PCC_ADC0_INDEX                           59
#define PCC_RTC_INDEX                            61
#define PCC_LPTMR0_INDEX                         64
#define PCC_PORTA_INDEX                          73
#define PCC_PORTB_INDEX                          74
#define PCC_PORTC_INDEX                          75
#define PCC_PORTD_INDEX                          76
#define PCC_PORTE_INDEX                          77
#define PCC_FlexIO_INDEX                         90
#define PCC_EWM_INDEX                            97
#define PCC_LPI2C0_INDEX                         102
#define PCC_LPUART0_INDEX                        106
#define PCC_LPUART1_INDEX                        107
#define PCC_LPUART2_INDEX                        108
#define PCC_CMP0_INDEX                           115


/* Exported Variables */
/*============================================================================*/


/* Exported functions prototypes */
/*============================================================================*/

#endif  /* Notice: the file ends with a blank new line to avoid compiler warnings */
