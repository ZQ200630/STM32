/*
 * @Descripttion:
 * @version: 1.0.0
 * @Author: Jason
 * @Date: 2020-08-21 11:44:00
 * @LastEditors: Jason
 * @LastEditTime: 2020-08-21 12:12:09
 */

#include "delay.h"
#include "iic.h"
#include "menu.h"
#include "oled.h"
#include "stm32f4xx.h"

/**
 * @description: Main Function
 * @param {}
 * @return {}
 * @author: Jason
 */
int main(void) {
    delay_init(168);
    // EXTIX_Init();
    OLED_Init(); //初始化OLED
    menu_init();

    delay_ms(2000);

    key_down();

    delay_ms(2000);

    key_down();

    delay_ms(2000);

    key_down();

    delay_ms(2000);

    key_right();

    delay_ms(2000);

    key_down();

    delay_ms(2000);

    key_left();

    delay_ms(2000);

    key_left();

    delay_ms(2000);

    key_right();

    delay_ms(2000);

    key_down();

    while (1) {
    }
}
