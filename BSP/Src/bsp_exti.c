#include "bsp_exti.h"

static void nvicInitConfig(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef nvicInitParam = {
        EXTI15_10_IRQn,
        0, 
        0,
        ENABLE
    };

    NVIC_Init(&nvicInitParam);
}

static void gpioInitConfig(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef gpioInitParam = {
        GPIO_Pin_13,
        GPIO_Mode_IN,
        GPIO_Speed_50MHz,
        GPIO_OType_PP,
        GPIO_PuPd_DOWN
    };

    GPIO_Init(GPIOC, &gpioInitParam);
}

static void extiPeriphConfig(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
    EXTI_InitTypeDef extiInitParam = {
        EXTI_Line13,
        EXTI_Mode_Interrupt,
        EXTI_Trigger_Rising_Falling,
        ENABLE
    };

    EXTI_Init(&extiInitParam);

    SYSCFG_EXTILineConfig(EXTI_PortSourceGPIOC, EXTI_PinSource13);
}

void extiConfig(void)
{
    nvicInitConfig();
    gpioInitConfig();
    extiPeriphConfig();
}
