#include "SystemInit.h"


void SystemInit(void)
{
    SYSCTL_MOSCCTL_R &= (~SYSCTL_MOSCCTL_NOXTAL);
    return ;
}