/**************************************************************************//**
 * @file     CPS8852Series.h
 * @version  
 * $Revision:  $
 * $Date:  $
 * @brief    CPS8852 Series Peripheral Access Layer Header File
 *
 * @note
 * Copyright (C) All rights reserved.
 *
 ******************************************************************************/



#ifndef __CPS8852SERIES_H__
#define __CPS8852SERIES_H__

#ifdef __cplusplus
 extern "C" {
#endif

/*
 * ==========================================================================
 * ---------- Interrupt Number Definition -----------------------------------
 * ==========================================================================
*/

typedef enum IRQn
{
/******  Cortex-M0 Processor Exceptions Numbers ***************************************************/

/* ToDo: use this Cortex interrupt numbers if your device is a CORTEX-M0 device                   */
  NonMaskableInt_IRQn           = -14,      /*!<  2 Cortex-M0 Non Maskable Interrupt              */
  HardFault_IRQn                = -13,      /*!<  3 Cortex-M0 Hard Fault Interrupt                */
  SVCall_IRQn                   = -5,       /*!< 11 Cortex-M0 SV Call Interrupt                   */
  PendSV_IRQn                   = -2,       /*!< 14 Cortex-M0 Pend SV Interrupt                   */
  SysTick_IRQn                  = -1,       /*!< 15 Cortex-M0 System Tick Interrupt               */

/******  CMSDK Specific Interrupt Numbers *********************************************************/
  PWM_4_IRQn                    = 0,   
  PWM_5_IRQn                    = 1,   
  PWM_0_IRQn                    = 2,   
  PWM_1_IRQn                    = 3,   
  UART2_ALL_IRQn                = 4,   
  ADC_IRQn                      = 5,   
  PORT0_COMB_IRQn               = 6,   
  PWD_IRQn                      = 7,   
  TIMER0_IRQn                   = 8,   
  TIMER1_IRQn                   = 9,   
  TIMER2_IRQn                   = 10,  
  PWM_2_IRQn                    = 11,  
  PWM_3_IRQn                    = 12,  
  I2C_SLAVE_IRQn                = 13,  
  SCP_TXD1_ALL_IRQn             = 14,
  SCP_RXD1_IRQn                 = 15,
  PORT1_COMB_IRQn               = 16,  
  PD_PHY_IRQn                   = 17,  
  PD_TYPEC_IRQn                 = 18,  
  XTAL_FAIL_IRQn                = 19,  
  I2C_MASTER_IRQn              	= 20,
  I2C_MASTER1_IRQn              = 21,  
  DPDN_COMP_IRQn                = 22,
  SCP_TXD2_ALL_IRQn             = 23,
  SCP_RXD2_IRQn                 = 24,
  CHIP_OT_IRQn                  = 25,
  VSYS_OV_IRQn                  = 26,
  ISNS_OC_IRQn                  = 27,  
  SCP_TXD3_ALL_IRQn             = 28,
  SCP_RXD3_IRQn                 = 29,  
  INT30_IRQn                    = 30,  
  INT31_IRQn                    = 31   
} IRQn_Type;


/*
 * ==========================================================================
 * ----------- Processor and Core Peripheral Section ------------------------
 * ==========================================================================
 */

/* Configuration of the Cortex-M0 Processor and Core Peripherals */
#define __CM0_REV                 0x0000    /*!< Core Revision r0p0                               */
#define __NVIC_PRIO_BITS          2         /*!< Number of Bits used for Priority Levels          */
#define __Vendor_SysTickConfig    0         /*!< Set to 1 if different SysTick Config is used     */
#define __MPU_PRESENT             0         /*!< MPU present or not                               */

/*@@}*/ /* end of group CMSDK_CMSIS */


#include "core_cm0.h"                       /* Cortex-M0 processor and core peripherals           */
#include "system_CPS8852Series.h"           /* System include file                                */

#if defined ( __CC_ARM   )
#pragma anon_unions
#endif



typedef struct
{
    __IO uint32_t sysc_clk_div:2;
    __IO uint32_t reserved_31_1:30;
}CLK_DIV_T;

typedef struct
{
    __IO uint32_t sysc_peri_cg_timer0:1;
    __IO uint32_t sysc_peri_cg_timer1:1;
    __IO uint32_t sysc_peri_cg_timer2:1;
    __IO uint32_t sysc_peri_cg_uart2:1;
    __IO uint32_t sysc_peri_cg_adc:1;
    __IO uint32_t sysc_peri_cg_pwm0:1;
    __IO uint32_t sysc_peri_cg_pwm1:1;
    __IO uint32_t sysc_peri_cg_pwm2:1;
    __IO uint32_t sysc_peri_cg_pwm3:1;
    __IO uint32_t sysc_peri_cg_pwm4:1;
    __IO uint32_t sysc_peri_cg_pwm5:1;
    __IO uint32_t sysc_peri_cg_pwm0_lp:1;
    __IO uint32_t sysc_peri_cg_pwm1_lp:1;
    __IO uint32_t sysc_peri_cg_pwm2_lp:1;
    __IO uint32_t sysc_peri_cg_pwm4_lp:1;
    __IO uint32_t sysc_peri_cg_pwm5_lp:1;
    __IO uint32_t sysc_peri_cg_dac_ctrl:1;
    __IO uint32_t sysc_peri_cg_i2c_master0:1;
    __IO uint32_t sysc_peri_cg_pdh:1;
    __IO uint32_t sysc_peri_cg_pdl:1;
    __IO uint32_t sysc_peri_cg_pwd0:1;
    __IO uint32_t sysc_peri_cg_pwd1:1;
    __IO uint32_t sysc_peri_cg_pwd2:1;
    __IO uint32_t sysc_peri_cg_pwd3:1;
    __IO uint32_t sysc_peri_cg_i2c_master1:1;
    __IO uint32_t sysc_peri_cg_pwm3_lp:1;
    __IO uint32_t sysc_peri_cg_scp:1;
    __IO uint32_t reserved_31_27:5;
}CLK_PERI_T;

typedef struct
{
    __IO uint32_t DATA;
    __IO uint32_t DATAOUT;
    __IO uint32_t RESERVED0[2];
    __IO uint32_t OUTPUT_ENABLE_SET;
    __IO uint32_t OUTPUT_ENALBE_CLR;
    __IO uint32_t ALTFUNCSET;
    __IO uint32_t ALTFUNCCLR;
    __IO uint32_t INTENSET;
    __IO uint32_t INTENCLR;
    __IO uint32_t INTTYPESET;
    __IO uint32_t INTTYPECLR;
    __IO uint32_t INTPOLSET;
    __IO uint32_t INTPOLCLR;
    union 
    {
        __I uint32_t  INTSTATUS;
        __O uint32_t  INTCLEAR;
    };
    uint32_t RESERVED1[241];
    __IO uint32_t LB_MASKED[256];
    __IO uint32_t UB_MASKED[256];
}GPIO_T;

typedef struct
{
    __IO uint32_t gp0:2;
    __IO uint32_t gp1:2;
    __IO uint32_t gp2:2;
    __IO uint32_t gp3:2;
    __IO uint32_t gp4:2;
    __IO uint32_t gp5:2;
    __IO uint32_t gp6:2;
    __IO uint32_t gp7:2;
    __IO uint32_t gp8:2;
    __IO uint32_t gp9:2;
    __IO uint32_t gp10:2;
    __IO uint32_t gp11:2;
    __IO uint32_t gp12:2;
    __IO uint32_t gp13:2;
    __IO uint32_t gp14:2;
    __IO uint32_t gp15:2;
}PIN_MUL_SET0_T;

typedef struct
{
    __IO uint32_t gp0:2;
    __IO uint32_t gp1:2;
    __IO uint32_t gp2:2;
    __IO uint32_t gp3:2;
    __IO uint32_t gp4:2;
    __IO uint32_t gp5:2;
    __IO uint32_t gp6:2;
    __IO uint32_t gp7:2;
}PIN_MUL_SET1_T;

typedef struct
{
    __IO uint32_t i2c_master_prer:16;
    __IO uint32_t reserved_31_16:16;
}I2C_MASTER0_T;

typedef struct
{
    __IO uint32_t DATA;
    __IO uint32_t STATE;
    __IO uint32_t CTRL;
    union
    {
        __I uint32_t INTSTATUS;
        __O uint32_t INTCLEAR;
    };
    __IO uint32_t BAUDDIV_VALUE;
}UART2_T;

typedef struct
{
    __IO uint32_t rg_eflash_mode;
}EFLASH_T;

typedef struct
{
    __IO uint32_t rg_eflash_pin_value;
}EFLASH_PIN_T;

typedef struct
{
    __IO uint32_t rg_eflash_write_enable_data:1;
    __IO uint32_t rg_eflash_write_enable_info:1;
    __IO uint32_t rg_eflash_write_enable_trim:1;
    __IO uint32_t reserved_31_04:29;
}EFLASH_WRITE_ENABLE_T;







/* Peripheral and SRAM base address */
#define FLASH_BASE                  ((uint32_t)0x00000000)
#define SRAM_BASE                   ((uint32_t)0x20000000)
#define APB_BASE                    ((uint32_t)0x40000000)
#define AHB_BASE                    ((uint32_t)0x40010000)

#define CLK_DIV_BASE                (AHB_BASE+  0x4000)         // System Clock Controller Base Address
#define CLK_PERI_BASE               (AHB_BASE+  0x4010)         // System Clock Controller Base Address
#define GPIO0_BASE                  (AHB_BASE+  0x0000)
#define GPIO1_BASE                  (AHB_BASE+  0x1000)
#define PIN_MUL_SET_BASE            (AHB_BASE+  0x4080)
#define EFLASH_BASE                 (AHB_BASE+  0x5000)
#define EFLASH_PIN_BASE             (AHB_BASE+  0x5004)
#define EFLASH_WRITE_ENABLE_BASE    (AHB_BASE+  0x501C)

#define UART2_BASE                  (APB_BASE+  0x6000)
#define I2C_MASTER0_BASE            (APB_BASE+  0xB800)
        
        
        
#define CLK_DIV                     ((CLK_DIV_T *) CLK_DIV_BASE)
#define CLK_PERI                    ((CLK_PERI_T *) CLK_PERI_BASE)
#define GPIO0                       ((GPIO_T *) GPIO0_BASE)
#define GPIO1                       ((GPIO_T *) GPIO1_BASE)
#define PIN_MUL_SET0                ((PIN_MUL_SET0_T *) PIN_MUL_SET_BASE)
#define PIN_MUL_SET1                ((PIN_MUL_SET1_T *) PIN_MUL_SET_BASE)
#define I2C_MASTER0                 ((I2C_MASTER0_T *) I2C_MASTER0_BASE)
#define UART2                       ((UART2_T *) UART2_BASE)
#define EFLASH                      ((EFLASH_T *) EFLASH_BASE)
#define EFLASH_PIN                  ((EFLASH_PIN_T *) EFLASH_PIN_BASE)
#define EFLASH_WRITE_ENABLE         ((EFLASH_WRITE_ENABLE_T *) EFLASH_WRITE_ENABLE_BASE)





//=============================================================================
/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outpw(port,value)     *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inpw(port)            (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outps(port,value)     *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inps(port)            (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outpb(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inpb(port)            (*((volatile unsigned char *)(port)))

/**
  * @brief Set a 32-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 32-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 32-bit aligned
  */
#define outp32(port,value)    *((volatile unsigned int *)(port)) = value

/**
  * @brief Get a 32-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 32-bit data from
  * @return  32-bit unsigned value stored in specified I/O port
  * @note The input port must be 32-bit aligned
  */
#define inp32(port)           (*((volatile unsigned int *)(port)))

/**
  * @brief Set a 16-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 16-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  * @note The output port must be 16-bit aligned
  */
#define outp16(port,value)    *((volatile unsigned short *)(port)) = value

/**
  * @brief Get a 16-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 16-bit data from
  * @return  16-bit unsigned value stored in specified I/O port
  * @note The input port must be 16-bit aligned
  */
#define inp16(port)           (*((volatile unsigned short *)(port)))

/**
  * @brief Set a 8-bit unsigned value to specified I/O port
  * @param[in] port Port address to set 8-bit data
  * @param[in] value Value to write to I/O port
  * @return  None
  */
#define outp8(port,value)     *((volatile unsigned char *)(port)) = value

/**
  * @brief Get a 8-bit unsigned value from specified I/O port
  * @param[in] port Port address to get 8-bit data from
  * @return  8-bit unsigned value stored in specified I/O port
  */
#define inp8(port)            (*((volatile unsigned char *)(port)))



/** @addtogroup legacy_Constants Legacy Constants
  Legacy Constants
  @{
*/


#define E_SUCCESS   0
#ifndef NULL    
#define NULL        0
#endif  
    
#define TRUE        1
#define FALSE       0

#define ENABLE      1
#define DISABLE     0

#define SUCCESS     1
#define FAILED      0

/* Define one bit mask */
#define BIT0    0x00000001
#define BIT1    0x00000002
#define BIT2    0x00000004
#define BIT3    0x00000008
#define BIT4    0x00000010
#define BIT5    0x00000020
#define BIT6    0x00000040
#define BIT7    0x00000080
#define BIT8    0x00000100
#define BIT9    0x00000200
#define BIT10   0x00000400
#define BIT11   0x00000800
#define BIT12   0x00001000
#define BIT13   0x00002000
#define BIT14   0x00004000
#define BIT15   0x00008000
#define BIT16   0x00010000
#define BIT17   0x00020000
#define BIT18   0x00040000
#define BIT19   0x00080000
#define BIT20   0x00100000
#define BIT21   0x00200000
#define BIT22   0x00400000
#define BIT23   0x00800000
#define BIT24   0x01000000
#define BIT25   0x02000000
#define BIT26   0x04000000
#define BIT27   0x08000000
#define BIT28   0x10000000
#define BIT29   0x20000000
#define BIT30   0x40000000
#define BIT31   0x80000000

/* Byte Mask Definitions */
#define BYTE0_Msk               (0x000000FF)
#define BYTE1_Msk               (0x0000FF00)
#define BYTE2_Msk               (0x00FF0000)
#define BYTE3_Msk               (0xFF000000)

#define _GET_BYTE0(u32Param)    ((u32Param & BYTE0_Msk)      )  /*!< Extract Byte 0 (Bit  0~ 7) from parameter u32Param */
#define _GET_BYTE1(u32Param)    ((u32Param & BYTE1_Msk) >>  8)  /*!< Extract Byte 1 (Bit  8~15) from parameter u32Param */
#define _GET_BYTE2(u32Param)    ((u32Param & BYTE2_Msk) >> 16)  /*!< Extract Byte 2 (Bit 16~23) from parameter u32Param */
#define _GET_BYTE3(u32Param)    ((u32Param & BYTE3_Msk) >> 24)  /*!< Extract Byte 3 (Bit 24~31) from parameter u32Param */

/*@@}*/ /* end of group CMSDK_PeripheralDecl */

/*@@}*/ /* end of group CMSDK_Definitions */


/******************************************************************************/
/*                         Peripheral header files                            */
/******************************************************************************/
#include "uart.h"
#include "eflash.h"


#ifdef __cplusplus
}
#endif

#endif  /* CMSDK_H */
