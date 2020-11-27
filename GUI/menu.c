#include "menu.h"

extern Node *current;
Node *setting;
Node *root;
unsigned char mode;

Node Menu_1_1_1_1 = {NULL, {NULL}, 4, 1, "Adjust Amp", "10 db", 0, 0, 102};
Node Menu_1_1_1_2 = {NULL, {NULL}, 4, 2, "Adjust Amp", "20 db", 1, 0, 102};
Node Menu_1_1_1_3 = {NULL, {NULL}, 4, 3, "Adjust Amp", "30 db", 2, 0, 102};
Node Menu_1_1_1_4 = {NULL, {NULL}, 4, 4, "Adjust Amp", "40 db", 3, 0, 102};

Node Menu_1_1_1 = {NULL, {&Menu_1_1_1_1, &Menu_1_1_1_2, &Menu_1_1_1_3, &Menu_1_1_1_4}, 1, 1, "Amplifier", "GAIN:", 123, 1, 1};

Node Menu_1_2_1_1 = {NULL, {NULL}, 2, 1, "Type Adj", "LOWPASS", 0, 0, 105};
Node Menu_1_2_1_2 = {NULL, {NULL}, 2, 2, "Type Adj", "HIGHPASS", 1, 0, 105};

Node Menu_1_2_2_1 = {NULL, {NULL}, 1, 1, "Freq Adj", "Freq: ", 0, 0, 107};

Node Menu_1_2_1 = {NULL, {&Menu_1_2_1_1, &Menu_1_2_1_2}, 2, 1, "Filter", "Type:", 123, 1, 3};
Node Menu_1_2_2 = {NULL, {&Menu_1_2_2_1}, 2, 2, "Filter", "Freq:", 123, 1, 4};


Node Menu_1_1 = {NULL, {&Menu_1_1_1}, 2, 1, "Filter", "Amplifier", 123, 1, 5};
Node Menu_1_2 = {NULL, {&Menu_1_2_1, &Menu_1_2_2}, 2, 2, "Filter", "Filter", 123, 1, 6};


Node Menu_1 = {NULL, {&Menu_1_1, &Menu_1_2}, 1, 1, "Menu", "Filter", 0, 1, 7};


/**
 * @description: 初始化菜单树形结构
 * @param {}
 * @return {} 
 */
void menu_init(void) {
	Menu_1_1_1_1.father = &Menu_1_1_1;
	Menu_1_1_1_2.father = &Menu_1_1_1;
	Menu_1_1_1_3.father = &Menu_1_1_1;
	Menu_1_1_1_4.father = &Menu_1_1_1;
	
	Menu_1_2_1_1.father = &Menu_1_2_1;
	Menu_1_2_1_2.father = &Menu_1_2_1;
	
	Menu_1_2_2_1.father = &Menu_1_2_2;
	
	Menu_1_1_1.father = &Menu_1_1;
	Menu_1_2_1.father = &Menu_1_2;
	Menu_1_2_2.father = &Menu_1_2;
	
    Menu_1_1.father = &Menu_1;
	Menu_1_2.father = &Menu_1;
	
	Menu_1.father = NULL;
	current = &Menu_1_1;
	root = &Menu_1;
	refresh(0);
}

void key_left() {
    if (mode == MODIFIED) {
        mode = UNMODIFIED;
    } else {
        if (current->father == NULL) {
            if (current != setting) {
                current = setting;
            } else {
                current = root;
            }
        } else {
            current = current->father;
        }
    }
	refresh(1);
}

void key_right() {
    if (current->is_dir) {
        current = current->son[0];
    } else {
        if (mode == UNMODIFIED) {
            //mode = MODIFIED;
        }
    }
	refresh(1);
}

void key_up() {
    if (mode == MODIFIED) {

    } else {
        if (current->index == 1) {
            current = current->father->son[current->count-1];
        } else {
            current = current->father->son[current->index - 2];
        }
    }
	refresh(1);
}

void key_down() {
    if (mode == MODIFIED) {

    } else {
        if (current->index == current->count) {
            current = current->father->son[0];
        } else {
            current = current->father->son[current->index];
        }
    }
	refresh(1);
}

void refresh(u8 isAllFresh) {
    if (current == root) {
		OLED_Clear();
        OLED_ShowString(24, 0, "Wellcome", 16);
		OLED_Refresh_Gram();
    } else {
        Node **all = current->father->son;
    u8 index = current->index;
    u8 count = current->count;
    u8 *title = current->title;
	
	if(count == 1) {
		show1(title, all[0], isAllFresh);
	} else if(count == 2) {
		show2(title, all[0], all[1], index, isAllFresh);
	} else if (count >= 3) {
    if(index == 1) {
        Node* n1 = all[0];
        Node* n2 = all[1];
        Node* n3 = all[2];
        show3(title, n1, n2, n3, 1, isAllFresh);
    } else if(index == count) {
        Node* n1 = all[count - 3];
        Node* n2 = all[count - 2];
        Node* n3 = all[count - 1];
        show3(title, n1, n2, n3, 3, isAllFresh);
    } else {
        Node* n1 = all[index - 2];
        Node* n2 = all[index - 1];
        Node* n3 = all[index];
        show3(title, n1, n2, n3, 2, isAllFresh);
    }
}
}
}

void show1(u8 *title, Node* n1, u8 isAllFresh) {
	if(isAllFresh) OLED_Clear();
	OLED_ShowString(24, 0, n1->title, 16);
	OLED_DrawX(4, 24);
	OLED_ShowString(9, 18, n1->name, 12);
	OLED_Refresh_Gram();
}
void show2(u8 *title, Node* n1, Node* n2, u8 index, u8 isAllFresh) {
	if(isAllFresh) OLED_Clear();
	OLED_Fill(0, 16, 8, 63, 0);
	OLED_ShowString(24, 0, n1->title, 16);
	OLED_DrawX(4, 8 + index*16);
	OLED_ShowString(9, 18, n1->name, 12);
	OLED_ShowString(9, 34, n2->name, 12);
	OLED_Refresh_Gram();
}

void show3(u8 *title, Node* n1, Node* n2, Node* n3, u8 index, u8 isAllFresh) {
	if(isAllFresh) OLED_Clear();
	OLED_Fill(0, 16, 8, 63, 0);
	OLED_ShowString(24, 0, title, 16);
	OLED_DrawX(4, 8 + index*16);
	OLED_ShowString(9, 18, n1->name, 12);
	OLED_ShowString(9, 34, n2->name, 12);
	OLED_ShowString(9, 50, n3->name, 12);
	OLED_Refresh_Gram();
}
