#include "CPS8852Series.h"
#include "variable.h"

volatile uint32_t test_info __attribute__((section(".ARM.__at_0x20001808")));
volatile uint32_t test_flag __attribute__((section(".ARM.__at_0x20001804")));
volatile uint32_t test_case __attribute__((section(".ARM.__at_0x20001800")));
uint32_t g_cp1_good_die = 0;


DEBOUNCE_STATUS g_gpio_debounce_status;
