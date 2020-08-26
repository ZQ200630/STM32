#ifndef __MENU_H
#define __MENU_H

#include "stdlib.h"	
#include "oled.h"
#include "exti.h"

#define MODIFIED 0x36
#define UNMODIFIED 0x37

typedef struct _Node
{
    struct _Node* father;
    struct _Node* son[10];
    u8 count;
    u8 index;
    u8 title[20];
    u8 name[20];
    u8 value;
    u8 is_dir;
    u8 id;
} Node;

extern void menu_init(void);
extern void key_left(void);
void key_right(void);
void key_up(void);
void key_down(void);
void refresh(u8 isAllFresh);
void show1(u8 *title, Node* n1, u8 isAllFresh);
void show2(u8 *title, Node* n1, Node* n2, u8 index, u8 isAllFresh);
void show3(u8 *title, Node* n1, Node* n2, Node* n3, u8 index, u8 isAllFresh);



#endif
