#ifndef __TEST_CP2_H__
#define __TEST_CP2_H__

#define TEST_CP2_BIN37_CHECK_GOOD_DIE_RECORD    (0x37)
#define TEST_CP2_BIN05_REF_CELL_ERASE           (0x05)
#define TEST_CP2_BIN31_VERIFY_MRG1              (0x31)
#define TEST_CP2_BIN31_VERIFY_MRG1              (0x31)
#define TEST_CP2_BIN40_GOOD_DIE                 (0x42)


#define TI_DONE     0xFA
#define TI_FAIL     0xF0
#define TI_INIT     0xF5
#define TI_VPP2V    0x01
#define TI_VPP11V   0x02
#define TI_VCC1P8V  0x03
#define TI_VCC2P0V  0x04
#define TI_VCC1P6V  0x05
#define TI_VPP10P1V 0x06
#define TI_VPP12P5V 0x07
#define TI_VPP8V    0x08
#define TI_VPP12P2V 0x09
#define TI_VPP9P5V  0x0A
#define TI_VPP4P9V  0x0B

#define TEST_BUSY   0xDD
#define TEST_IDLE   0xEE


void wait_continue_test(void);
uint8_t test_cp2_bin37(void);
uint8_t test_cp2_bin05(void);
uint8_t test_cp2_bin31(void);
uint8_t test_cp2_bin40(void);

#endif
