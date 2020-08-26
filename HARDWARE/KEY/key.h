/*
 * @Author: your name
 * @Date: 2020-06-17 13:24:19
 * @LastEditTime: 2020-06-17 15:06:11
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \USERe:\KeilProject\STM32template\HARDWARE\KEY\key.h
 */ 
#ifndef __KEY_H
#define __KEY_H
#include "sys.h"

#define KEY_UP PAin(0)
#define KEY_LEFT PEin(2)
#define KEY_DOWN PEin(3)
#define KEY_RIGHT PEin(4)

void KEY_Init(void);

#endif
