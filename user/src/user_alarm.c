/**
 * @file    user_alarm.c
 * @brief   8.8 作业：流水灯报警系统。
 *          
 */
#include "user_alarm.h"
   /* LED 驱动的函数声明 */
#define DELAY_VARIATION_MS 50U

/* 函数定义：这里才是函数的具体实现 */
void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms)
{
  uint16_t i = 0U; /* 循环计数变量 */

  /* if 判断：LED 编号只允许 1~4 */
  if (led_num > LED_COUNT)
  {
    return; /* return 直接结束当前函数 */
  }

  /* for 循环：初始化; 判断条件; 每次循环后执行 */
  for (i = 0U; i < times; i++)
  {
    led_on(led_num);          /* 点亮指定 LED */
    HAL_Delay(delay_ms);      /* 延时一段时间 */
    led_off(led_num);         /* 熄灭指定 LED */
    HAL_Delay(delay_ms);
  }
}

void beep(uint32_t beep_ms)
{
  buzzer_on();          /* 打开蜂鸣器 */
  HAL_Delay(beep_ms);   /* 保持响一段时间 */
  buzzer_off();         /* 关闭蜂鸣器 */
}

void waterfall_led(uint8_t start_led,uint8_t led_count, uint16_t blink_times, uint32_t delay_ms,uint32_t delay_variation_ms,uint8_t beep_on)
{
    /* while 循环：条件成立就反复执行 {} 里的代码 */
    while (start_led <= led_count)
    {
        blink_times = 1;
        blink_led(start_led, blink_times, delay_ms);
        if(beep_on == BEEP_ON)//判断是否在灯间隔闪烁时响起蜂鸣器
        {
            beep(delay_ms);
        }
        start_led++; /* 等价于 start_led = current_led + 1 */
        /* if / else 判断：让延时每次变快一点，到 100 后重新回到初始值 */
        if (delay_ms > 100U)
        {
            delay_ms -= delay_variation_ms;
        }
        else
        {
            delay_ms = DELAY_MS;
        }
    }
}


void alarm_sys_func(uint8_t mode,uint16_t times)
{
    uint16_t delay_ms = DELAY_MS;
    switch (mode)
    {
    case MODE_STANDBY:
        break;
    
    case MODE_RUNNING:
        for (int i = 0 ;i < times;i++)
        {
            waterfall_led(1U,LED_COUNT,BLINK_TIMES,DELAY_MS,0,0);
        } 
        
        break;
    case MODE_ALARM:
        
        for (int i = 0; i < times;i++)
        {
            
            waterfall_led(1U,LED_COUNT,BLINK_TIMES,delay_ms,DELAY_VARIATION_MS,BEEP_ON);
            delay_ms -= DELAY_VARIATION_MS;
        }
        
        break;
    }
}

