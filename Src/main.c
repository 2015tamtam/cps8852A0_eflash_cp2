#include <stdio.h>
#include <time.h>
#include "CPS8852Series.h"
#include "variable.h"
#include "test_cp2.h"


#define IPLL_48MHZ

//const uint32_t sys_clock_buffer[4] = {24000000, 24000000, 16000000, 12000000};

void cps_clock_init(uint32_t clock)
{
    int div = 0;

    switch(clock)
    {
        case 24000000:
        {
            div = 0;
            break;
        }
        case 16000000:
        {
            div = 2;
            break;
        }
        case 12000000:
        default:
        {
            div = 3;
            break;
        }
    }
    CLK_DIV->sysc_clk_div = div;
    
    // Enable 12MHz for PD
    CLK_PERI->sysc_peri_cg_pdh = 1;
    CLK_PERI->sysc_peri_cg_pdl = 1;
}

void system_init(void)
{
    uint32_t clock = 24000000;
    
    // analog register enable
    (*(__IO uint32_t *)0x4000E75C) = 0x1250;
    
    // Enable PLL ---> rstb
    (*(__IO uint32_t *)0x4000F100) |= 0x114120;
    
    // Enable analog PLL
    (*(__IO uint32_t *)0x4000F080) = 0x20000000;
    
    // Enable CLK Gating
    (*(__IO uint32_t *)0x4001400C) = 0x00;
    
    // Use PLL
    (*(__IO uint32_t *)0x40014008) = 0x01;
    
    // OSC 8M trim data	before change to HS mode, set trim data @@@@@@@@@@@
    (*(__IO uint32_t *)0x4000F004) = 0xF77FE91F;
    
    // Use HS speed	, Don't use HS mode in PLL 144 -> to fix by pll.rstb = 1
    (*(__IO uint32_t *)0x40014004) = 0x01;
    
    // Init 12MHz clock for PD module
    cps_clock_init(clock);
    
    SysTick_Config(clock / 1000);
    NVIC_EnableIRQ(SysTick_IRQn);
    NVIC_SetPriority(SysTick_IRQn, 1);
}

int main(void)
{
    uint8_t status = SUCCESS;
    
    system_init();
    uart2_open(115200);

    printf("\n");
    printf("+--------------------------------------------+\n");
    printf("|   CSP 8852 Sample Code                     |\n");
    printf("+--------------------------------------------+\n");
    
    printf ("\nCPS8852 eFlash CP2 TEST, %s,%s\n", __DATE__, __TIME__);
    
    // Notify-Output
    GPIO0->OUTPUT_ENABLE_SET |= BIT9;
    PIN_MUL_SET0->gp9 = 0;
    GPIO0->DATAOUT &= ~BIT9;
        
    GPIO0->OUTPUT_ENABLE_SET |= BIT15;
    PIN_MUL_SET0->gp15 = 1;
    GPIO0->DATAOUT &= ~BIT15;
    
      // Notify-Input
    GPIO0->OUTPUT_ENALBE_CLR |= BIT10;
    PIN_MUL_SET0->gp10 = 0;
    GPIO0->DATAOUT &= ~BIT10;
    
    EFLASH->rg_eflash_mode = 1;
    
    if(test_cp2_bin37() == FAILED)
    {
        status = FAILED;
        wait_continue_test();
    }
    if(test_cp2_bin05() == FAILED)
    {
        status = FAILED;
        wait_continue_test();
    }
    if(test_cp2_bin31() == FAILED)
    {
        status = FAILED;
        wait_continue_test();
    }
    if(test_cp2_bin40() == FAILED)
    {
        status = FAILED;
        wait_continue_test();
    }
    
    if(status == SUCCESS)
        test_info = TI_DONE;
    else
        test_info = TI_FAIL;
    
    test_flag = TEST_IDLE;
    
    // Test done - GPIO15-High
    GPIO0->DATAOUT |= (0x01 << 15);

    while(1);
}
