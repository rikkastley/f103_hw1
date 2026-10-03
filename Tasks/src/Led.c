#include "Led.h"
#include "main.h"          /* 为了用 LED_GPIO_Port / LED_Pin */

void LedInit(void)
{
    /* PC13 低电平点亮板载灯（作业表里的要求） */
    HAL_GPIO_WritePin(LED_GPIO_Port, LED_Pin, GPIO_PIN_RESET);
}