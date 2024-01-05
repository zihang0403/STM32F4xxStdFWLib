#include <bsp_systick.h>

static void nvicInitConfig(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

    NVIC_InitTypeDef nvicInitParam = {
            USART1_IRQn,
            0,
            0,
            ENABLE
    };

    NVIC_Init(&nvicInitParam);
}

static void gpioInitConfig(void)
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
    GPIO_InitTypeDef gpioTxInitParam = {
        GPIO_Pin_9,
        GPIO_Mode_AF,
        GPIO_Speed_100MHz,
        GPIO_OType_PP,
        GPIO_PuPd_UP
    };

    GPIO_InitTypeDef gpioRxInitParam = {
        GPIO_Pin_10,
        GPIO_Mode_AF,
        GPIO_Speed_100MHz,
        GPIO_OType_PP,
        GPIO_PuPd_UP
    };

    GPIO_Init(GPIOA, &gpioTxInitParam);
    GPIO_Init(GPIOA, &gpioRxInitParam);

    GPIO_PinAFConfig(GPIOA, GPIO_PinSource9, GPIO_AF_USART1);
    GPIO_PinAFConfig(GPIOA, GPIO_PinSource10, GPIO_AF_USART1);
}

static void usartInitConfig(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    USART_InitTypeDef usartInitParam = {
        115200,
        USART_WordLength_8b,
        USART_StopBits_1,
        USART_Parity_No,
        USART_Mode_Tx | USART_Mode_Rx,
        USART_HardwareFlowControl_None
    };

    USART_Init(USART1, &usartInitParam);
    USART_Cmd(USART1, ENABLE);

    USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
}

void usartConfig(void)
{
    nvicInitConfig();
    gpioInitConfig();
    usartInitConfig();
}

void usartSendString(char *str)
{
    while(*str != '\0')
    {
        USART_SendData(USART1, *str++);
        while(USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET);
        USART_ClearFlag(USART1, USART_FLAG_TC);
    }
}
