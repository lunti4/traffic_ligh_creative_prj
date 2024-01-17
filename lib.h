#pragma once

#include "stm32f10x.h"

/// @brief Функция для формирования задержки
/// @param ms Время в миллисекундах
void delay_ms(uint32_t ms);

/// @brief Функция инициализации UART
void UART1_Init(void);

/// @brief Функия для отправки символа в буфер
/// @param ch Символ для отправки
void UART1_SendChar(char ch);

/// @brief Функция для отправки строки в буфер
/// @param str Адрес первого элемента строки
void UART1_SendString(const char *str);
