#include "bsp_systick.h"

// 1 tick = 1 / 180MHz          s
// 1 tick = 1 / 180,000,000     s
// 180 tick = 180 / 180,000,000 s
//          = 1 / 1,000,000 s
//          = 1 us
// 180,000 tick = 1 / 1,000 s
//              = 1 ms

uint32_t gTimeDecrement;

void sysTickConfig(void)
{
    SysTick_Config(180000);//180,000 1ms产生一次中断
}

void delayms(uint32_t xms)
{
    gTimeDecrement = xms;

    while (gTimeDecrement > 0);
}

void timeDecrement(void)
{
    gTimeDecrement--;
}
