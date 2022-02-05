#include <stdint.h>
#include <stdio.h>
#include "SystemInit.h"
#include "GPIO.h"


int main (void)
{
    // This function is responsible to configure the system clock
    SystemInit();
    gpio_setup_n();
    GPIO_PORTN_DATA_R |= (1 << 0);
    while (1){};
    return 0;
}