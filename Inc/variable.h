#ifndef __VARIABLE_H__
#define __VARIABLE_H__

typedef struct
{
    uint8_t old_index;
    uint8_t new_index;
    uint8_t debounce_counter;
    uint8_t entry_mode;
}DEBOUNCE_STATUS;

extern volatile uint32_t test_info __attribute__((section(".ARM.__at_0x20001808")));
extern volatile uint32_t test_flag __attribute__((section(".ARM.__at_0x20001804")));
extern volatile uint32_t test_case __attribute__((section(".ARM.__at_0x20001800")));
extern uint32_t g_cp1_good_die;


extern DEBOUNCE_STATUS g_gpio_debounce_status;

#endif
