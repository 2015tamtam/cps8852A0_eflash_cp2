#include <stdio.h>
#include "CPS8852Series.h"
#include "variable.h"
#include "eflash_cp.h"
#include "test_cp2.h"


#define XADR_MAX 384        // 48K

void delay_us(int us)
{
    int i, j;
    for(i = 0; i < us; i++)
    {
        for(j = 0; j < 7; j++);
    }
}

void get_giop_status_debounce(void)
{
    if((GPIO0->DATA & BIT10) == BIT10)
    {
        g_gpio_debounce_status.new_index = 1;
        
        if(g_gpio_debounce_status.new_index ==
            g_gpio_debounce_status.old_index)
        {
            g_gpio_debounce_status.debounce_counter++;
            if(g_gpio_debounce_status.debounce_counter >= 20)
            {
                g_gpio_debounce_status.debounce_counter = 0;
                g_gpio_debounce_status.entry_mode = TRUE;
            }
        }
        else
        {
            g_gpio_debounce_status.debounce_counter = 0;
        }
    }
    else
    {
        g_gpio_debounce_status.new_index = 0;
    }
    g_gpio_debounce_status.old_index = g_gpio_debounce_status.new_index;
}

void wait_continue_test(void)
{
    // Notify error
    GPIO0->DATAOUT |= BIT9;     // GPIO-9-Output
    while(1)
    {
        // GPIO-10-Input
        get_giop_status_debounce();
        if(g_gpio_debounce_status.entry_mode == TRUE)
        {
            g_gpio_debounce_status.entry_mode = FALSE;
            break;
        }
    }
    test_info = TI_INIT;
    GPIO0->DATAOUT &= ~BIT9;
    delay_us(5000);
}

uint8_t eflash_margx_verify_xx(int xx,int mode)
{
    if(eflash_verify(1, xx, 8, 1, mode) == FAILED)
        return FAILED;

    if(eflash_verify(0, xx, XADR_MAX, 1, mode) == FAILED)
        return FAILED;
    return SUCCESS;
}

uint8_t test_cp2_bin37(void)
{    
    test_case = TEST_CP2_BIN37_CHECK_GOOD_DIE_RECORD;
    
    printf("\nTest Case Num(0x20001800) = 0x%x\n", (*((volatile uint32_t *)0x20001800)));
    
    EFLASH->rg_eflash_mode = 0;
    if((*((volatile uint32_t *)0x0000C000)) != 0x5555AAAA)
        return FAILED;
    return SUCCESS;
}

uint8_t test_cp2_bin05(void)
{
    test_case = TEST_CP2_BIN05_REF_CELL_ERASE;
    
    printf("\nTest Case Num(0x20001800) = 0x%02x\n", (*((volatile uint32_t *)0x20001800)));
    
    eflash_set_TM(0x2B);
    eflash_ref_cell_erase();
    eflash_set_TM(0x3B);
    return SUCCESS;
}

uint8_t test_cp2_bin31(void)
{
    test_case = TEST_CP2_BIN31_VERIFY_MRG1;
    
    printf("\nTest Case Num(0x20001800) = 0x%x\n", (*((volatile uint32_t *)0x20001800)));
    
    EFLASH->rg_eflash_mode = 1;
    g_cp1_good_die = 1;
    eflash_set_TM(0x0A);
    return eflash_margx_verify_xx(0xFFFFFFFF, VERIFY_NORMAL);
}

uint8_t test_cp2_bin40(void)
{
    test_case = TEST_CP2_BIN40_GOOD_DIE;
    
    printf("\nTest Case Num(0x20001800) = 0x%x\n", (*((volatile uint32_t *)0x20001800)));
    
    EFLASH->rg_eflash_mode = 0;
    EFLASH_WRITE_ENABLE->rg_eflash_write_enable_info = 1;
    
    // For CP2 repeat testing
    if((*((volatile uint32_t *)0x00000C004)) == 0xFFFFFFFF)
    {
        *((volatile uint32_t *)0x00000C004) = 0x5555AAAA;
    }
    if((*((volatile uint32_t *)0x0000C000)) != 0x5555AAAA)
        return FAILED;
    return SUCCESS;
}
