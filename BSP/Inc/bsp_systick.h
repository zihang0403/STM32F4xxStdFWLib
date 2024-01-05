#ifndef __BSP_SYSTICK_H
#define __BSP_SYSTICK_H

#include "stm32f4xx.h"

void sysTickConfig(void);
void timeDecrement(void);
void delayms(uint32_t xms);

#endif
