/*
 * @Author: rikkastley xyc00710@icloud.com
 * @Date: 2026-10-03 22:38:52
 * @LastEditors: rikkastley xyc00710@icloud.com
 * @LastEditTime: 2026-10-03 23:09:33
 * @FilePath: \f103_hw1\Tasks\src\Tick.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "Tick.h"
#include "main.h"
#include "tim.h"     /* 为了用 htim2  */
#include "iwdg.h"    /* 为了用 hiwdg  */

/* ===== 作业硬性要求：变量名必须叫 tick，类型必须 volatile uint32_t ===== */
volatile uint32_t tick = 0;

/* ===== Tasks 的初始化：让 TIM2 的更新中断真正开始工作 ===== */
void TickInit(void)
{
    HAL_TIM_Base_Start_IT(&htim2);
}

/* ===== 定时器更新回调：每 1 ms 自动被调用一次 ===== */
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)      /* 必须判断：该回调由所有定时器共用，后续工程会同时开启多个定时器 */
    {
        tick++;                      /* 作业要求：tick 自增 1 */
        
    }
}