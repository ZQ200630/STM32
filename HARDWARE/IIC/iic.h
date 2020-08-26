/*
 * @Author: your name
 * @Date: 2020-07-31 19:12:57
 * @LastEditTime: 2020-07-31 20:50:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \USERe:\KeilProject\STM32template\HARDWARE\IIC\iic.h
 */ 
#ifndef __IIC_H
#define __IIC_H			  	 
#include "sys.h"
#include "delay.h"

#define  E2PROM_SDA  GPIO_Pin_7
#define  E2PROM_SCL  GPIO_Pin_6
#define  E2PROM_CMD_WRITE  0xa0
#define  E2PROM_CMD_READ   0xa1
#define  I2C_DELAY         254       //I2C延时

void IICInit( void );
void I2CStart( void );
void I2CStop( void );
unsigned char I2CSlaveAck( void );
void I2CWriteByte( unsigned char byte );
unsigned char I2CReadByte( void );
uint8_t E2promWriteByte( uint16_t addr, uint8_t data );
uint8_t E2promReadByte( unsigned short int addr );


#endif
