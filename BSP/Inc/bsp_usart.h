#ifndef __BSP_USART_H
#define __BSP_USART_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_usart.h"
#include "stm32f4xx_rcc.h"
#include "misc.h"

void usartConfig(void);
void usartSendString(char str[]);

#endif
