#include "stm32f10x.h"

int main(void) 
{
    SystemInit();  // Инициализация системы (необходимо для CMSIS)

    RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;  // Включаем тактирование порта C
    GPIOC->CRH &= ~(GPIO_CRH_CNF8 | GPIO_CRH_CNF9 | GPIO_CRH_CNF10 |
                    GPIO_CRH_MODE8 | GPIO_CRH_MODE9 | GPIO_CRH_MODE10);
    GPIOC->CRH |= GPIO_CRH_MODE8 | GPIO_CRH_MODE9 | GPIO_CRH_MODE10;  // Настраиваем PC8, PC9 и PC10 как выходы

    UART1_Init();  // Инициализация UART1

    while (1) 
    {
        GPIOC->BSRR = GPIO_BSRR_BS8;  // Красный светодиод включен, остальные выключены
        GPIOC->BSRR = GPIO_BSRR_BR9;
        GPIOC->BSRR = GPIO_BSRR_BR10;
        UART1_SendString("Red\n");
        delay_ms(3000);

        GPIOC->BSRR = GPIO_BSRR_BR8;  // Желтый светодиод включен, остальные выключены
        GPIOC->BSRR = GPIO_BSRR_BS9;
        GPIOC->BSRR = GPIO_BSRR_BR10;
        UART1_SendString("Yellow\n");
        delay_ms(1000);

        GPIOC->BSRR = GPIO_BSRR_BR8;  // Зеленый светодиод включен, остальные выключены
        GPIOC->BSRR = GPIO_BSRR_BR9;
        GPIOC->BSRR = GPIO_BSRR_BS10;
        UART1_SendString("Green\n");
        delay_ms(3000);
    }
}
