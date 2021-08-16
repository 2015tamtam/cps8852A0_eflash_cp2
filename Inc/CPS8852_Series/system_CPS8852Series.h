/**************************************************************************//**
 * @file     system_CPS8852Series.h
 * @version  
 * $Revision:  $
 * $Date:  $
 * @brief    CPS8852 Series CMSIS System Header File
 *
 * @note
 * Copyright (C) All rights reserved.
 *
 ******************************************************************************/
#ifndef __SYSTEM_CPS8852SERIES_H__
#define __SYSTEM_CPS8852SERIES_H__

#ifdef __cplusplus
extern "C"
{
#endif
/*---------------------------------------------------------------------------------------------------------*/
/* Macro Definition                                                                                        */
/*---------------------------------------------------------------------------------------------------------*/

/* Using UART2 */
#define DEBUG_PORT  UART2


/**
 * Initialize the system
 *
 * @param  None
 * @return None
 *
 * @brief  Setup the microcontroller system
 *         Initialize GPIO directions and values
 */
extern void SystemInit(void);


/**
 * Update SystemCoreClock variable
 *
 * @param  None
 * @return None
 *
 * @brief  Updates the SystemCoreClock with current core Clock
 *         retrieved from CPU registers.
 */
extern void SystemCoreClockUpdate(void);

#ifdef __cplusplus
}
#endif
#endif
