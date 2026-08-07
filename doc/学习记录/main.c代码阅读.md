![[Pasted image 20260807144234.png]]

![[Pasted image 20260807144259.png]]

# main.c
## 变量
### 文件内全局变量(PV内部)
无

### main函数内部局部变量

#### 定义
```C
  /* USER CODE BEGIN 1 */

  /* 局部变量：只能在 main 函数内使用 */

  uint8_t  current_led = 1U;              /* 当前要操作的 LED 编号 */

  uint16_t blink_times = BLINK_TIMES;/* 每颗 LED 闪烁次数 */

  uint32_t delay_ms    =

  DELAY_MS;   /* 亮/灭延时 */

  const uint8_t led_count = LED_COUNT; /* const 表示该变量不允许修改 */

  /* USER CODE END 1 */
```

#### 作用范围
只在main（）内部


## 函数
### 函数声明（标记PFP内）
```C
/* USER CODE BEGIN PFP */

/* 函数声明（原型）：告诉编译器函数名、参数和返回值，定义在下方 USER CODE 4 */

void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms);

void beep(uint32_t beep_ms);

/* USER CODE END PFP */
```



### 函数定义（标记4内）
```C
/* USER CODE BEGIN 4 */

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

    led_on(led_num);          /* 点亮指定 LED */

    HAL_Delay(delay_ms);      /* 延时一段时间 */

    led_off(led_num);         /* 熄灭指定 LED */

    HAL_Delay(delay_ms);

  }

}

  

void beep(uint32_t beep_ms)

{

  buzzer_on();          /* 打开蜂鸣器 */

  HAL_Delay(beep_ms);   /* 保持响一段时间 */

  buzzer_off();         /* 关闭蜂鸣器 */

}

/* USER CODE END 4 */
```

### 函数调用
#### 形参
```C
void blink_led(uint8_t led_num, uint16_t times, uint32_t delay_ms);
/*
led_num,times,delay_ms为blink_led()的形参
*/

void beep(uint32_t beep_ms);
/*
beep_ms为beep()函数的形参
*/

```

#### 实参
```C
    beep(BEEP_MS);//实参为宏BEEP_MS
    blink_led(current_led, blink_times, delay_ms);//实参为变量current_led, blink_times, delay_ms
```

## 关键字的使用

### for

1. blink_led()函数内部
```C

  /* for 循环：初始化; 判断条件; 每次循环后执行 */

  for (i = 0U; i < times; i++)

  {

    led_on(led_num);          /* 点亮指定 LED */

    HAL_Delay(delay_ms);      /* 延时一段时间 */

    led_off(led_num);         /* 熄灭指定 LED */

    HAL_Delay(delay_ms);

  }
/*用于让指定LED闪烁times次*/
```

### while
1. main（）的死循环
```C
while(1)
{
}
/*用于执行单片机的主程序*/
```
2. 死循环内的流水灯
```C
    while (current_led <= led_count)

    {

      blink_led(current_led, blink_times, delay_ms);

      current_led++; /* 等价于 current_led = current_led + 1 */

    }
    /*从起点按顺序闪烁小灯*/
```


### if
1. 死循环内，小灯延时时间改变条件判断
```C
    if (delay_ms > 100U)

    {

      delay_ms += 20U; /* 练习点：改成 += 20U 看速度变化方向 */

    }

    else

    {

      delay_ms = DELAY_MS;

    }
    /*初始delay_ms大于100，才能递增，否则不变*/
```

2. blink_led（）内部，由于只有LED1~4有对应的被配置的引脚，故只允许控制LED1~4
```C

  /* if 判断：LED 编号只允许 1~4 */

  if (led_num > LED_COUNT)

  {

    return; /* return 直接结束当前函数 */

  }

```

### switch
无

