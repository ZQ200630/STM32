/*
 * @Descripttion:
 * @version: 1.0.0
 * @Author: Jason
 * @Date: 2020-08-21 11:44:00
 * @LastEditors: Jason
<<<<<<< HEAD
<<<<<<< HEAD
 * @LastEditTime: 2020-08-26 22:49:11
=======
 * @LastEditTime: 2020-08-26 16:40:02
>>>>>>> test
=======
 * @LastEditTime: 2020-08-26 16:42:40
>>>>>>> test
 */

#include "delay.h"
#include "iic.h"
#include "menu.h"
#include "oled.h"
#include "stm32f4xx.h"
#include "usart.h"

Node* current;
/**
 * @description: Main Function
 * @param {}
 * @return {}
 * @author: Jason
 */
 int GAIN_ARR[] = {1, 10, 33, 100};
 int GAIN_INDEX = 0;
 int FILTER_TYPE = 0;
 int FILTER_FREQUENCY = 1;
 int FILTER_FREQUENCY_CACHE = 10;
int main(void) {
	int len, t;
    delay_init(168);
    // EXTIX_Init();
    OLED_Init(); //初始化OLED
    menu_init();

    uart_init(115200);

    while (1) {
		if(USART_RX_STA&0x8000)
		{					   
			len=USART_RX_STA&0x3fff;
			for(t=0;t<len;t++)
			{
				USART_SendData(USART1, USART_RX_BUF[t]);         
				while(USART_GetFlagStatus(USART1,USART_FLAG_TC)!=SET);
			}
			USART_RX_STA=0;
		
			if(USART_RX_BUF[0] == 'u') {
				if(current->id == 107) {
					if(FILTER_FREQUENCY_CACHE < 20) {
						FILTER_FREQUENCY_CACHE++;
					}
				} else {
				key_up();
				}
			}
			if(USART_RX_BUF[0] == 'd') {
				if(current->id == 107) {
					if(FILTER_FREQUENCY_CACHE > 1) {
						FILTER_FREQUENCY_CACHE--;
					}
				} else {
				key_down();
				}
			}
			if(USART_RX_BUF[0] == 'l') {
				key_left();
			}
			if(USART_RX_BUF[0] == 'r') {
				key_right();
			}
			if(USART_RX_BUF[0] == '0') {
				GAIN_INDEX = 0;
			}
			if(USART_RX_BUF[0] == '1') {
				GAIN_INDEX = 1;
			}
			if(USART_RX_BUF[0] == '2') {
				GAIN_INDEX = 2;
			}
			if(USART_RX_BUF[0] == '3') {
				GAIN_INDEX = 3;
			}
			if(current->id == 102 && USART_RX_BUF[0] == 'o') {
				GAIN_INDEX = current->value;
				key_left();
			}
			if(current->id == 105 && USART_RX_BUF[0] == 'o') {
				FILTER_TYPE = current->value;
				key_left();
			}
			
			if(current->id == 107 && USART_RX_BUF[0] == 'o') {
				FILTER_FREQUENCY = FILTER_FREQUENCY_CACHE;
				key_left();
			}
		}
		if(current->id == 1) {
			OLED_ShowNum(44,30, GAIN_ARR[GAIN_INDEX], 3, 24);
			OLED_Refresh_Gram();
		}
		if(current->id == 3 || current->id == 4) {
			u8* arr;
			if(FILTER_TYPE == 0) {
				arr = "LOWPASS";
			} else {
				arr = "HIGHPASS";
			}
			OLED_ShowString(45, 18, arr, 12);
			OLED_ShowNum(45,34, FILTER_FREQUENCY, 3, 12);
			OLED_ShowString(70, 34, "KHz", 12);
			OLED_Refresh_Gram();
		}
		if(current->id == 107) {
			OLED_ShowNum(25,30, FILTER_FREQUENCY_CACHE, 3, 24);
			OLED_ShowString(70, 50, "KHz", 12);
			OLED_Refresh_Gram();
		}
		
		// 更改电路参数
		
		
		
		
		
		
    }
}
