#ifndef __EFLASH_CP_H__
#define __EFLASH_CP_H__

enum VERIFY_MODE
{
    VERIFY_NORMAL = 0,
    VERIFY_DIAGONAL,
    VERIFY_CKBD,
    VERIFY_CKBD_,
    VERIFY_EVEN,
    VERIFY_ODD,
};

#define RG_EFLASH_PIN_XE_POS            (0)
#define RG_EFLASH_PIN_XE_MSK            (0x01UL << RG_EFLASH_PIN_XE_POS)
#define RG_EFLASH_PIN_XE_SET(num)       (num << RG_EFLASH_PIN_XE_POS)
    
#define RG_EFLASH_PIN_YE_POS            (1)
#define RG_EFLASH_PIN_YE_MSK            (0x01UL << RG_EFLASH_PIN_YE_POS)
#define RG_EFLASH_PIN_YE_SET(num)       (num << RG_EFLASH_PIN_YE_POS)
    
#define RG_EFLASH_PIN_SE_POS            (2)
#define RG_EFLASH_PIN_SE_MSK            (0x01UL << RG_EFLASH_PIN_SE_POS)
#define RG_EFLASH_PIN_SE_SET(num)       (num << RG_EFLASH_PIN_SE_POS)
    
#define RG_EFLASH_PIN_PROG_POS          (3)
#define RG_EFLASH_PIN_PROG_MSK          (0x01UL << RG_EFLASH_PIN_PROG_POS)
#define RG_EFLASH_PIN_PROG_SET(num)     (num << RG_EFLASH_PIN_PROG_POS)
    
#define RG_EFLASH_PIN_ERASE_POS         (4)
#define RG_EFLASH_PIN_ERASE_MSK         (0x01UL << RG_EFLASH_PIN_ERASE_POS)
#define RG_EFLASH_PIN_ERASE_SET(num)    (num << RG_EFLASH_PIN_ERASE_POS)
    
#define RG_EFLASH_PIN_NVSTR_POS         (5)
#define RG_EFLASH_PIN_NVSTR_MSK         (0x01UL << RG_EFLASH_PIN_NVSTR_POS)
#define RG_EFLASH_PIN_NVSTR_SET(num)    (num << RG_EFLASH_PIN_NVSTR_POS)
    
#define RG_EFLASH_PIN_MAS1_POS          (6)
#define RG_EFLASH_PIN_MAS1_MSK          (0x01UL << RG_EFLASH_PIN_MAS1_POS)
#define RG_EFLASH_PIN_MAS1_SET(num)     (num << RG_EFLASH_PIN_MAS1_POS)
    
#define RG_EFLASH_PIN_IFREN_POS         (7)
#define RG_EFLASH_PIN_IFREN_MSK         (0x01UL << RG_EFLASH_PIN_IFREN_POS)
#define RG_EFLASH_PIN_IFREN_SET(num)    (num << RG_EFLASH_PIN_IFREN_POS)

#define RG_EFLASH_PIN_XADR_POS          (8)
#define RG_EFLASH_PIN_XADR_MSK          (0x01UL << RG_EFLASH_PIN_XADR_POS)
#define RG_EFLASH_PIN_XADR_SET(num)     (num << RG_EFLASH_PIN_XADR_POS)

#define RG_EFLASH_PIN_YADR_POS          (17)
#define RG_EFLASH_PIN_YADR_MSK          (0x01UL << RG_EFLASH_PIN_YADR_POS)
#define RG_EFLASH_PIN_YADR_SET(num)     (num << RG_EFLASH_PIN_YADR_POS)

#define RG_EFLASH_PIN_TMR_POS           (22)
#define RG_EFLASH_PIN_TMR_MSK           (0x01UL << RG_EFLASH_PIN_TMR_POS)
#define RG_EFLASH_PIN_TMR_SET(num)      (num << RG_EFLASH_PIN_TMR_POS)


void eflash_set_TM(uint32_t value);
void eflash_ref_cell_erase(void);
uint8_t eflash_verify(int ifren, int data, int xadrmax, int marg, int mode);

#endif
