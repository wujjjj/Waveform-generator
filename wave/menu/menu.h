#ifndef __MENU_H
#define __MENU_H

#include "main.h"

typedef struct{
	u8 state;
	u8 position;
	u8 set_flag;
	
	u8 mode;//enum wave
	u16 frequent;//0-1000
	u8 compare;//0-100
	
	u16 frequent2;
	u8 compare2;
}mymenu;

enum out_wave{
	square_wave = 0,
	sine_wave = 1,
	triangle_wave = 2,
	flat_top_wave = 3,
	sawtooth_wave = 4,
};


void menu_init(void);

void menu_select(u8 input);
void select_front(void);
void select_back(void);
void select_up(void);
void select_down(void);

void show(void);

#endif
