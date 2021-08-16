#include <stdio.h>
#include "CPS8852Series.h"


void eflash_delay_us(int us)
{
    int i, j;
    for(i = 0; i < us; i++)
    {
        for(j = 0; j < 7; j++);
    }
}

uint8_t eflash_standby(void)
{
}

uint8_t eflash_read(uint8_t ifren)
{
}

uint8_t eflash_byte_program(uint8_t ifren)
{
}

uint8_t eflash_page_erase(uint8_t ifren)
{
}

uint8_t eflash_mass_erase(uint8_t ifren)
{
}
