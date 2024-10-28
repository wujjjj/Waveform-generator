#ifndef __SHOW_H
#define __SHOW_H

#include "main.h"

void show_set_main(u8 num);//0-3
void show_zt(void);
void show_bx(void);
void show_pl(void);
void show_zkb(void);

void show_set_bx(u8 num);//num=0-4
void show_fb(void);
void show_zxb(void);
void show_sjb(void);
void show_pdb(void);
void show_jcb(void);

void show_set_pl(u16 data);
void show_set_zkb(u8 data);

void show_state(u8 state_num);
void color_set(u8 num);

#endif
