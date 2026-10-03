#ifndef TASKS_INC_TICK_H
#define TASKS_INC_TICK_H

#include <stdint.h>

extern volatile uint32_t tick;   /* 全局变量，对外声明 */

void TickInit(void);             /* 启动定时器 */

#endif