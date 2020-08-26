#include "menu.h"

Node *current;
Node *setting;
Node *root;
unsigned char mode;

Node Menu_1_1_2 = {NULL, {NULL}, 2, 2, "Channel 1", "PulseWidth", 123, 0, 1};
Node Menu_1_1_1 = {NULL, {NULL}, 2, 1, "Channel 1", "Frequency", 123, 0, 2};


Node Menu_1_2_1 = {NULL, {NULL}, 2, 1, "Channel 2", "Frequency", 123, 0, 3};
Node Menu_1_2_2 = {NULL, {NULL}, 2, 2, "Channel 2", "PulseWidth", 123, 0, 4};

Node Menu_1_3_1 = {NULL, {NULL}, 2, 1, "Channel 3", "Frequency", 123, 0, 5};
Node Menu_1_3_2 = {NULL, {NULL}, 2, 2, "Channel 3", "PulseWidth", 123, 0, 6};

Node Menu_1_4_1 = {NULL, {NULL}, 2, 1, "Channel 4", "Frequency", 123, 0, 7};
Node Menu_1_4_2 = {NULL, {NULL}, 2, 2, "Channel 4", "PulseWidth", 123, 0, 8};

Node Menu_1_1 = {NULL, {&Menu_1_1_1, &Menu_1_1_2}, 4, 1, "Main Menu", "Channel 1", 123, 1, 9};
Node Menu_1_2 = {NULL, {&Menu_1_2_1, &Menu_1_2_2}, 4, 2, "Main Menu", "Channel 2", 123, 1, 10};
Node Menu_1_3 = {NULL, {&Menu_1_3_1, &Menu_1_3_2}, 4, 3, "Main Menu", "Channel 3", 123, 1, 11};
Node Menu_1_4 = {NULL, {&Menu_1_4_1, &Menu_1_4_2}, 4, 4, "Main Menu", "Channel 4", 123, 1, 12};

Node Menu_1 = {NULL, {&Menu_1_1, &Menu_1_2, &Menu_1_3, &Menu_1_4}, 1, 1, "123123", "Test111", 0, 1, 13};


/**
 * @description: 初始化菜单树形结构
 * @param {}
 * @return {} 
 */
void menu_init(void) {
	Menu_1_1_1.father = &Menu_1_1;
    Menu_1_1_2.father = &Menu_1_1;
	Menu_1_2_1.father = &Menu_1_2;
	Menu_1_2_2.father = &Menu_1_2;
	Menu_1_3_1.father = &Menu_1_3;
	Menu_1_3_2.father = &Menu_1_3;
	Menu_1_4_1.father = &Menu_1_4;
	Menu_1_4_2.father = &Menu_1_4;
    Menu_1_1.father = &Menu_1;
	Menu_1_2.father = &Menu_1;
	Menu_1_3.father = &Menu_1;
	Menu_1_4.father = &Menu_1;
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
	
	if(current->id <= 6) {
	refresh(1);
	} else {
	refresh(0);
	}
}

void key_right() {
    if (current->is_dir) {
        current = current->son[0];
    } else {
        if (mode == UNMODIFIED) {
            //mode = MODIFIED;
        }
    }
	refresh(0);
}

void key_up() {
    if (mode == MODIFIED) {
        //TODO ???????????VALUE??
    } else {
        if (current->index == 1) {
            current = current->father->son[current->father->count];
        } else {
            current = current->father->son[current->index - 1];
        }
    }
	refresh(1);
}

void key_down() {
    if (mode == MODIFIED) {
        //TODO ???????????VALUE??
    } else {
        if (current->index == current->count) {
            current = current->father->son[0];
        } else {
            current = current->father->son[current->index];
        }
    }
	if(current->id <= 6) {
	refresh(1);
	} else {
	refresh(0);
	}
	
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
