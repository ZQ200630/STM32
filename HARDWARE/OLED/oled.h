/*
 * @Author: your name
 * @Date: 2020-07-31 12:56:35
 * @LastEditTime: 2020-08-01 19:05:25
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \USERe:\KeilProject\STM32template\HARDWARE\OLED\oled.h
 */ 
#ifndef __OLED_H
#define __OLED_H			  	 
#include "sys.h"
#include "stdlib.h"	    
//////////////////////////////////////////////////////////////////////////////////	 
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//ALIENTEK STM32F407开发板
//OLED 驱动代码	   
//正点原子@ALIENTEK
//技术论坛:www.openedv.com
//创建日期:2014/5/4
//版本：V1.0
//版权所有，盗版必究。
//Copyright(C) 广州市星翼电子科技有限公司 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 	  
 

//OLED模式设置
//0: 4线串行模式  （模块的BS1，BS2均接GND）
//1: 并行8080模式 （模块的BS1，BS2均接VCC）
//2：I2C模式
#define OLED_MODE 	2 
		    						  
//-----------------OLED端口定义----------------  					   
#define OLED_CS 	PBout(7)
#define OLED_RST    PGout(15)	
#define OLED_RS 	PDout(6)
#define OLED_WR 	PAout(4)		  
#define OLED_RD 	PDout(7)

 
//使用4线串行接口时使用 
#define OLED_SCLK 	PCout(6)
#define OLED_SDIN 	PCout(7)

		     
#define OLED_CMD  	0		//写命令
#define OLED_DATA 	1		//写数据

//I2C专用控制函数
void Write_IIC_Command(unsigned char IIC_Command);
void Write_IIC_Data(unsigned char IIC_Data);

//OLED控制用函数
void OLED_WR_Byte(u8 dat,u8 cmd);	    
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Refresh_Gram(void);	
							   		    
void OLED_Init(void);
void OLED_Clear(void);
void OLED_DrawPoint(u8 x,u8 y,u8 t);
void OLED_DrawX(u8 x, u8 y);
void OLED_Fill(u8 x1,u8 y1,u8 x2,u8 y2,u8 dot);
void OLED_ShowChar(u8 x,u8 y,u8 chr,u8 size,u8 mode);
void OLED_ShowNum(u8 x,u8 y,u32 num,u8 len,u8 size);
void OLED_ShowString(u8 x,u8 y,const u8 *p,u8 size);	 
#endif  
	 


