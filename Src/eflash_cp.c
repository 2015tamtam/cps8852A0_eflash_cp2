#include <stdio.h>
#include "CPS8852Series.h"
#include "variable.h"
#include "eflash_cp.h"


void eflash_delay_us(int us)
{
    int i, j;
    for(i = 0; i < us; i++)
    {
        for(j = 0; j < 7; j++);
    }
}

void eflash_set_TM(uint32_t value)
{
    int temp = RG_EFLASH_PIN_NVSTR_MSK |
                RG_EFLASH_PIN_SE_MSK |
                RG_EFLASH_PIN_MAS1_SET((value & 0x01)) |
                RG_EFLASH_PIN_XE_SET((value >> 2) & 0x01) |
                RG_EFLASH_PIN_YE_SET((value >> 3) & 0x01) |
                RG_EFLASH_PIN_ERASE_SET((value >> 4) & 0x01) |
                RG_EFLASH_PIN_PROG_SET((value >> 5) & 0x01);
    
    // Clear
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_TMR_MSK;
    EFLASH_PIN->rg_eflash_pin_value = 0;
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_NVSTR_MSK | RG_EFLASH_PIN_SE_MSK;
    
    EFLASH_PIN->rg_eflash_pin_value = temp;
    
    // TM latch
    EFLASH_PIN->rg_eflash_pin_value = temp | RG_EFLASH_PIN_TMR_MSK;
    EFLASH_PIN->rg_eflash_pin_value = temp;
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_NVSTR_MSK | RG_EFLASH_PIN_SE_MSK;
    
    // Keep TMR low
    EFLASH_PIN->rg_eflash_pin_value = 0;
    __NOP();
}

void eflash_ref_cell_erase(void)
{
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_XE_MSK | RG_EFLASH_PIN_ERASE_MSK;
    eflash_delay_us(5);
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_XE_MSK |
                                        RG_EFLASH_PIN_ERASE_MSK |
                                        RG_EFLASH_PIN_NVSTR_MSK;
    eflash_delay_us(20000);     // Terase 20ms
    EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_XE_MSK | RG_EFLASH_PIN_NVSTR_MSK;
    eflash_delay_us(5);
    EFLASH_PIN->rg_eflash_pin_value = 0;
    eflash_delay_us(1);
}

uint8_t eflash_verify(int ifren, int data, int xadrmax, int marg, int mode)
{
    int dout;
    int exp;
    int xadrint = 0;
    int xadrinc = 1;
    int diag_yadr_mask = 31;
    int ckbd = 0x00000000;
    
    if(mode == VERIFY_EVEN)
    {
        xadrint = 1;
        xadrinc = 2;
    }
    
    if(mode == VERIFY_ODD)
    {
        xadrinc = 2;
    }
    ifren = 0;
    for(int xadr = xadrint; xadr < xadrmax; xadr = xadr+xadrinc)
    {
        EFLASH_PIN->rg_eflash_pin_value = RG_EFLASH_PIN_IFREN_SET(ifren) |
                                            RG_EFLASH_PIN_XADR_SET(xadr) |
                                            RG_EFLASH_PIN_XE_MSK |
                                            RG_EFLASH_PIN_YE_MSK |
                                            RG_EFLASH_PIN_TMR_SET(marg==0);
        
        if(mode == VERIFY_CKBD || mode == VERIFY_CKBD_)
        {
            if((xadr&0x1) == (mode&0x1))
                ckbd = 0x00000000;
            else
                ckbd = 0xFFFFFFFF;
        }
        for(int yadr = 0; yadr < 32; yadr++)
        {
            if((mode == VERIFY_DIAGONAL) && ((xadr & 31) == (yadr & diag_yadr_mask)))
            {
                exp = 0x00000000;
            }
            else if(mode == VERIFY_CKBD || mode == VERIFY_CKBD_)
            {
                if((yadr & 0x1) == 0)
                    exp = ckbd;
                else
                    exp = ~ckbd;
            }
            else
            {
                exp = data;
            }
            if(g_cp1_good_die==1 & ifren==1 & xadr==0 & yadr==0)
            {
                exp = 0x5555AAAA;
            }
            EFLASH_PIN->rg_eflash_pin_value |= RG_EFLASH_PIN_YADR_MSK;
            EFLASH_PIN->rg_eflash_pin_value |= RG_EFLASH_PIN_SE_MSK;
            if(marg)
            {
                // Tmrg < 200ns
//                __ISB;
                __NOP();
            }
            dout = EFLASH_PIN->rg_eflash_pin_value;
            if(dout != exp)
            {
                printf ("\nx:%x y:%x %x %x\n",xadr,yadr,dout,exp);
                return FAILED;
            }
            EFLASH_PIN->rg_eflash_pin_value &= ~(RG_EFLASH_PIN_SE_MSK);
        }
    }
    EFLASH_PIN->rg_eflash_pin_value = 0;
    eflash_delay_us(1);
    return SUCCESS;
}
