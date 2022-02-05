#include "inc/tm4c1294ncpdt.h"
#include <stdint.h>



void gpio_setup_n(void)
{
    SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R12; // Enable clock on portN
    GPIO_PORTN_DIR_R |= (1 << 0);   // Pin N0 as output
    GPIO_PORTN_AFSEL_R &= ~(0xFF);  // Guarantee that the pins are controlled by GPIO registers and not alternate functions pins
    GPIO_PORTN_PUR_R |= (1 << 0);   // Pull-up on port N0
    GPIO_PORTN_DEN_R |= (1 << 0);   // Digital mode
    return;
}