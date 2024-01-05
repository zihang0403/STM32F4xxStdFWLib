#include "bsp_led.h"

void ledInitConfig(void)
{
    GPIO_InitTypeDef beefInitParam;
    GPIO_InitTypeDef redLedInitParam;
    GPIO_InitTypeDef greenLedInitParam;
    GPIO_InitTypeDef blueLedInitParam;
    GPIO_InitTypeDef k1InitParam;
    GPIO_InitTypeDef k2InitParam;

    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOH, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOI, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    
    beefInitParam.GPIO_Pin = BEEF_PIN;
    beefInitParam.GPIO_Mode = GPIO_Mode_OUT;
    beefInitParam.GPIO_Speed = GPIO_Speed_50MHz;
    // 推挽 高电平低电平两种状态，开漏 高、低电平、高阻态三种状态
    beefInitParam.GPIO_OType = GPIO_OType_PP;//推挽
    // 上拉 默认为高电平 下拉 默认为低电平
    beefInitParam.GPIO_PuPd = GPIO_PuPd_UP;
    
    redLedInitParam.GPIO_Pin = RED_LED_PIN;
    redLedInitParam.GPIO_Mode = GPIO_Mode_OUT;
    redLedInitParam.GPIO_Speed = GPIO_Speed_50MHz;
    redLedInitParam.GPIO_OType = GPIO_OType_PP;
    redLedInitParam.GPIO_PuPd = GPIO_PuPd_UP;

    greenLedInitParam.GPIO_Pin = GREEN_LED_PIN;
    greenLedInitParam.GPIO_Mode = GPIO_Mode_OUT;
    greenLedInitParam.GPIO_Speed = GPIO_Speed_50MHz;
    greenLedInitParam.GPIO_PuPd = GPIO_PuPd_UP;

    blueLedInitParam.GPIO_Pin = BLUE_LED_PIN;
    blueLedInitParam.GPIO_Mode = GPIO_Mode_OUT;
    blueLedInitParam.GPIO_Speed = GPIO_Speed_50MHz;
    blueLedInitParam.GPIO_OType = GPIO_OType_PP;
    blueLedInitParam.GPIO_PuPd = GPIO_PuPd_UP;

    k1InitParam.GPIO_Pin = BUTTON_K1_PIN;
    k1InitParam.GPIO_Mode = GPIO_Mode_IN;
    k1InitParam.GPIO_Speed = GPIO_Speed_50MHz;

    k2InitParam.GPIO_Pin = BLUE_LED_PIN;
    k2InitParam.GPIO_Mode = GPIO_Mode_IN;
    k2InitParam.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(BEEF_PORT, &beefInitParam);
    GPIO_Init(RED_LED_PORT, &redLedInitParam);
    GPIO_Init(GREEN_LED_PORT, &greenLedInitParam);
    GPIO_Init(BLUE_LED_PORT, &blueLedInitParam);
    GPIO_Init(BUTTON_K1_PORT, &k1InitParam);
    GPIO_Init(BUTTON_K2_PORT, &k2InitParam);
}

void ledTurnOn(void)
{
    GPIO_SetBits(BEEF_PORT, BEEF_PIN);
    GPIO_ResetBits(RED_LED_PORT, RED_LED_PIN);
    GPIO_ResetBits(GREEN_LED_PORT, GREEN_LED_PIN);
    GPIO_ResetBits(BLUE_LED_PORT, BLUE_LED_PIN);
}

void ledTurnOff(void)
{
    GPIO_ResetBits(BEEF_PORT, BEEF_PIN);
    GPIO_SetBits(RED_LED_PORT, RED_LED_PIN);
    GPIO_SetBits(GREEN_LED_PORT, GREEN_LED_PIN);
    GPIO_SetBits(BLUE_LED_PORT, BLUE_LED_PIN);
}

//void delay(uint32_t time)
//{
//    for (uint32_t i = 0; i < time; i++)
//    {
//        for (uint32_t j = 0; j < 0x7FFFFF; j++);
//    }
//}
