#include "lib.h"
#include "stm32f10x.h"

void delay_ms(uint32_t ms)
{
    uint32_t i;
    uint32_t j;

    for (i = 0; i < ms; ++i)
    {
        for (j = 0; j < 7200; ++j);
    }
}

void UART1_Init(void) 
{
    RCC->APB2ENR |= RCC_APB2ENR_USART1EN;   // Включаем тактирование USART1
    GPIOA->CRH &= ~(GPIO_CRH_CNF9 | GPIO_CRH_MODE9);  // Очищаем биты конфигурации и режима для вывода PA9
    GPIOA->CRH |= GPIO_CRH_CNF9_1 | GPIO_CRH_MODE9;   // Устанавливаем режим "альтернативная функция" и "50 МГц" для вывода PA9

    USART1->BRR = 0x1D4C;  // Устанавливаем скорость передачи 9600 бит/с
    USART1->CR1 |= USART_CR1_TE;  // Включаем передачу данных
    USART1->CR1 |= USART_CR1_UE;  // Включаем USART1
}

void UART1_SendChar(char ch) 
{
    while (!(USART1->SR & USART_SR_TXE));  // Ждем, пока буфер передатчика освободится
    USART1->DR = ch;  // Записываем символ в буфер передатчика
}

void UART1_SendString(const char *str) 
{
    while (*str) 
    {
        UART1_SendChar(*str++);
    }
}