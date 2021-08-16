#include "CPS8852Series.h"


void uart2_open(uint32_t baudrate)
{
    CLK_PERI->sysc_peri_cg_uart2 = 0x01;
    UART2->BAUDDIV_VALUE = (24 * 1000000 / (CLK_DIV->sysc_clk_div + 1)) / baudrate;
    
    // TX only
    UART2->CTRL = 0x01;
    PIN_MUL_SET0->gp7 = 0;
    
    GPIO0->OUTPUT_ENALBE_CLR = 1 << 11;
}
