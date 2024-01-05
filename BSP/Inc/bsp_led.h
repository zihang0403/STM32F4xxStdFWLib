#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_conf.h"

#define BEEF_PIN GPIO_Pin_11
#define RED_LED_PIN GPIO_Pin_10
#define GREEN_LED_PIN GPIO_Pin_11
#define BLUE_LED_PIN GPIO_Pin_12
#define BUTTON_K1_PIN GPIO_Pin_0
#define BUTTON_K2_PIN GPIO_Pin_13

#define BEEF_PORT GPIOI
#define RED_LED_PORT GPIOH
#define GREEN_LED_PORT GPIOH
#define BLUE_LED_PORT GPIOH
#define BUTTON_K1_PORT GPIOA
#define BUTTON_K2_PORT GPIOC

#define LED_GREEN_ON GPIO_ResetBits(GREEN_LED_PORT, GREEN_LED_PIN);
#define LED_RED_ON GPIO_ResetBits(RED_LED_PORT, RED_LED_PIN);
#define LED_BLUE_ON GPIO_ResetBits(BLUE_LED_PORT, BLUE_LED_PIN);

#define LED_GREEN_OFF GPIO_SetBits(GREEN_LED_PORT, GREEN_LED_PIN);
#define LED_RED_OFF GPIO_SetBits(RED_LED_PORT, RED_LED_PIN);
#define LED_BLUE_OFF GPIO_SetBits(BLUE_LED_PORT, BLUE_LED_PIN);

void ledInitConfig(void);
void ledTurnOn(void);
void ledTurnOff(void);
//void delay(uint32_t time);

#endif
