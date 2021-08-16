;/**************************************************************************//**
; * @file     startup_CMSDK_CM0.s
; * @brief    CMSIS Cortex-M0 Core Device Startup File for
; *           Device CMSDK_CM0
; * @version  V3.01
; * @date     06. March 2012
; *
; * @note
; * Copyright (C) 2012 ARM Limited. All rights reserved.
; *
; * @par
; * ARM Limited (ARM) is supplying this software for use with Cortex-M
; * processor based microcontrollers.  This file can be freely distributed
; * within development tools that are supporting such ARM based processors.
; *
; * @par
; * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
; * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
; * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
; * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
; * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
; *
; ******************************************************************************/
;/*
;//-------- <<< Use Configuration Wizard in Context Menu >>> ------------------
;*/


; <h> Stack Configuration
;   <o> Stack Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> Heap Configuration
;   <o>  Heap Size (in Bytes) <0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000100

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit


                PRESERVE8
                THUMB


; Vector Table Mapped to Address 0 at Reset

                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp              ; Top of Stack
                DCD     Reset_Handler             ; Reset Handler
                DCD     NMI_Handler               ; NMI Handler
                DCD     HardFault_Handler         ; Hard Fault Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     SVC_Handler               ; SVCall Handler
                DCD     0                         ; Reserved
                DCD     0                         ; Reserved
                DCD     PendSV_Handler            ; PendSV Handler
                DCD     SysTick_Handler           ; SysTick Handler
                DCD     PWM_4_Handler       ; 00,
                DCD     PWM_5_Handler       ; 01,
                DCD     PWM_0_Handler       ; 02,
                DCD     PWM_1_Handler       ; 03,
                DCD     UART2_ALL_Handler   ; 04,
                DCD     ADC_Handler         ; 05,
                DCD     PORT0_COMB_Handler  ; 06,
                DCD     PWD_Handler         ; 07,
                DCD     TIMER0_Handler      ; 08,
                DCD     TIMER1_Handler      ; 09,
                DCD     TIMER2_Handler      ; 10,
                DCD     PWM_2_Handler       ; 11,
                DCD     PWM_3_Handler       ; 12,
                DCD     I2C_SLAVE_Handler   ; 13,
                DCD     SCP_TXD1_ALL_Handler ; 14,
                DCD     SCP_RXD1_Handler     ; 15,
                DCD     PORT1_COMB_Handler  ; 16,
                DCD     PD_PHY_Handler      ; 17,
                DCD     PD_TYPEC_Handler    ; 18,
                DCD     XTAL_FAIL_Handler   ; 19,
                DCD     I2C_MASTER_Handler ; 20,
                DCD     I2C_MASTER1_Handler ; 21,
                DCD     DPDN_COMP_Handler   ; 22,
                DCD     SCP_TXD2_ALL_Handler ; 23,
                DCD     SCP_RXD2_Handler     ; 24,
                DCD     CHIP_OT_Handler     ; 25,
                DCD     VSYS_OV_Handler     ; 26,
                DCD     ISNS_OC_Handler     ; 27,
                DCD     SCP_TXD3_ALL_Handler ; 28,
                DCD     SCP_RXD3_Handler     ; 29,
                DCD     INT30_Handler       ; 30,
                DCD     INT31_Handler       ; 31,
__Vectors_End

__Vectors_Size  EQU     __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY


; Reset Handler

Reset_Handler   PROC
                EXPORT  Reset_Handler             [WEAK]
                IMPORT  SystemInit
                IMPORT  __main
                LDR     R0, =SystemInit
                BLX     R0
                LDR     R0, =__main
                BX      R0
                ENDP


; Dummy Exception Handlers (infinite loops which can be modified)

NMI_Handler     PROC
                EXPORT  NMI_Handler               [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler         [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler               [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler            [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
               EXPORT  SysTick_Handler            [WEAK]
               B       .
               ENDP
Default_Handler PROC
                EXPORT PWM_4_Handler           [WEAK]
                EXPORT PWM_5_Handler           [WEAK]
                EXPORT PWM_0_Handler           [WEAK]
                EXPORT PWM_1_Handler           [WEAK]
                EXPORT UART2_ALL_Handler       [WEAK]
                EXPORT ADC_Handler             [WEAK]
                EXPORT PORT0_COMB_Handler      [WEAK]
                EXPORT PWD_Handler             [WEAK]
                EXPORT TIMER0_Handler          [WEAK]
                EXPORT TIMER1_Handler          [WEAK]
                EXPORT TIMER2_Handler          [WEAK]
                EXPORT PWM_2_Handler           [WEAK]
                EXPORT PWM_3_Handler           [WEAK]
                EXPORT I2C_SLAVE_Handler       [WEAK]
                EXPORT SCP_TXD1_ALL_Handler     [WEAK]
                EXPORT SCP_RXD1_Handler         [WEAK]
                EXPORT PORT1_COMB_Handler      [WEAK]
                EXPORT PD_PHY_Handler          [WEAK]
                EXPORT PD_TYPEC_Handler        [WEAK]
                EXPORT XTAL_FAIL_Handler       [WEAK]
                EXPORT I2C_MASTER_Handler     [WEAK]
                EXPORT I2C_MASTER1_Handler     [WEAK]
                EXPORT DPDN_COMP_Handler       [WEAK]
                EXPORT SCP_TXD2_ALL_Handler     [WEAK]
                EXPORT SCP_RXD2_Handler         [WEAK]                
                EXPORT CHIP_OT_Handler         [WEAK]
                EXPORT VSYS_OV_Handler         [WEAK]
                EXPORT ISNS_OC_Handler         [WEAK]
                EXPORT SCP_TXD3_ALL_Handler     [WEAK]
                EXPORT SCP_RXD3_Handler         [WEAK]
                EXPORT INT30_Handler           [WEAK]
                EXPORT INT31_Handler           [WEAK]

PWM_4_Handler
PWM_5_Handler
PWM_0_Handler
PWM_1_Handler
UART2_ALL_Handler
ADC_Handler
PORT0_COMB_Handler
PWD_Handler
TIMER0_Handler
TIMER1_Handler
TIMER2_Handler
PWM_2_Handler
PWM_3_Handler
I2C_SLAVE_Handler
SCP_TXD1_ALL_Handler
SCP_RXD1_Handler
PORT1_COMB_Handler
PD_PHY_Handler
PD_TYPEC_Handler
XTAL_FAIL_Handler
I2C_MASTER_Handler
I2C_MASTER1_Handler
DPDN_COMP_Handler
SCP_TXD2_ALL_Handler
SCP_RXD2_Handler
CHIP_OT_Handler
VSYS_OV_Handler
ISNS_OC_Handler
SCP_TXD3_ALL_Handler
SCP_RXD3_Handler
INT30_Handler
INT31_Handler

                B       .
                ENDP


                ALIGN


; User Initial Stack & Heap

                IF      :DEF:__MICROLIB

                EXPORT  __initial_sp
                EXPORT  __heap_base
                EXPORT  __heap_limit

                ELSE

                IMPORT  __use_two_region_memory
                EXPORT  __user_initial_stackheap

__user_initial_stackheap PROC
                LDR     R0, =  Heap_Mem
                LDR     R1, =(Stack_Mem + Stack_Size)
                LDR     R2, = (Heap_Mem +  Heap_Size)
                LDR     R3, = Stack_Mem
                BX      LR
                ENDP

                ALIGN

                ENDIF


                END
