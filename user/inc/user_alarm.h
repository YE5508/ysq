/**
 * @file    user_alarm.h
 * @brief   8.8 作业：流水灯报警系统。
 *          
 */
#ifndef USER_ALARM_H
#define USER_ALARM_H

#ifdef __cplusplus
extern "C"
{
#endif
    #include "stm32h7xx_hal.h"
    #include "buzzer.h"
    #include "led.h"   

    #define MODE_STANDBY 1
    #define MODE_RUNNING 2
    #define MODE_ALARM 3
    #define DELAY_MS    500U  /* LED 亮/灭持续时间，单位毫秒 */
    #define BEEP_MS     300U  /* 蜂鸣器响一声的时长 */
    #define BEEP_ON 1
    #define BLINK_TIMES 3U  /*每颗LED的闪烁次数*/

    /* 函数声明（原型）：告诉编译器函数名、参数和返回值，定义在下方 USER CODE 4 */
    void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms);
    void beep(uint32_t beep_ms);
    void waterfall_led(uint8_t start_led,uint8_t led_count, uint16_t blink_times, uint32_t delay_ms,uint32_t delay_variation_ms,uint8_t beep_on);
    void alarm_sys_func(uint8_t mode,uint16_t times);
#ifdef __cplusplus
}
#endif

#endif /* USER_ALARM_H */