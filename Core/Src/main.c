#include <bsp_usart.h>
#include "stm32f4xx.h"
#include "bsp_led.h"
#include "bsp_systick.h"
#include "bsp_exti.h"


extern uint32_t ledGreenFlag;

int main()
{
    sysTickConfig();
    extiConfig();
    ledInitConfig();
    ledTurnOff();
    usartConfig();

    uint8_t data[20] = "Hello World!\n";

    uint16_t recvData = 0;
    while (1)
    {
//        usartSendString(data);
//        delayms(1000);
//        recvData = USART_ReceiveData(USART1);
//        USART_SendData(USART1, recvData);
    }
}
