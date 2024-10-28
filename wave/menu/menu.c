#include "main.h"
#include "menu.h"
#include "lcd.h"
#include "show.h"
#include "mytim.h"

mymenu menu;
extern mywave wave;

void menu_init(void){
	float adc = 0;
	LCD_Init();
	LCD_Clear(White);
	
	menu.state = 0;		//状态
	menu.compare = 90;	//占空比
	menu.compare2 = 90;	//占空比
	menu.frequent = 100;	//频率
	menu.frequent2 = 100;		//频率
	
	menu.mode = 0;		//波形模式
	menu.position = 0;	//选择位置
	menu.set_flag = 0;	//进入设置标志位
	
	show_state(0);
	color_set(0);
	show_zt();
	color_set(1);
	show_bx();
	show_pl();
	show_zkb();
	
	adc = Get_ADC_num();
	menu.compare = menu.compare2 + (u8)(adc * 10.0f);
	menu.frequent = menu.frequent2 + (u8)(adc * 100.0f);
	wave.cycle = (u32)(100000.0f / (menu.frequent));
	
	show_set_bx(0);
	show_set_pl(menu.frequent);
	show_set_zkb(menu.compare);
}

u8 key_flag[4];
void menu_select(u8 input){
	u8 i;
	float adc = 0;
	for(i=0;i<4;i++){
		if(input & (0x01<<i)){
			key_flag[i] = 1;
		}else{
			if(key_flag[i]){
				key_flag[i] = 0;
				switch(i){
					case 0:select_front();
						break;
					case 1:select_back();
						break;
					case 2:select_down();
						break;
					case 3:select_up();
						break;
				}
				show();
			}
		}
	}
	if(menu.set_flag){
		if(menu.position == 2){
			adc = Get_ADC_num();
			menu.frequent = menu.frequent2 + (u8)(adc * 100.0f);
			color_set(0);show_set_pl(menu.frequent);color_set(1);
			wave.cycle = (u32)(100000.0f / (menu.frequent));
		}else if(menu.position == 3){
			adc = Get_ADC_num();
			menu.compare = menu.compare2 + (u8)(adc * 10.0f);
			color_set(0);show_set_zkb(menu.compare);color_set(1);
		}
	}
}
void select_front(void){
	if(menu.set_flag){return;}
	menu.set_flag = 1;
}
void select_back(void){
	if(menu.set_flag==0){return;}
	menu.set_flag = 0;
}
void select_up(void){
	if(menu.set_flag){
		if(menu.position==2){
			if(menu.frequent2 >= 100){
				menu.frequent2-=100;
			}
		}else{	
			if(menu.compare2 >= 10){
				menu.compare2-=10;
			}
		}
	}else{
		if(menu.position < 3){
			menu.position++;
		}else{
			menu.position = 0;
		}
	}
}
void select_down(void){
	if(menu.set_flag){
		if(menu.position==2){
			if(menu.frequent2 < 900){
				menu.frequent2+=100;
			}
		}else{	
			if(menu.compare2 < 90){
				menu.compare2+=10;
			}
		}
	}else{
		if(menu.position > 0){
			menu.position--;
		}else{
			menu.position = 3;
		}
	}
}

void show(void){
	if(menu.set_flag){
		switch(menu.position){
			case 0:menu.state=!(menu.state);show_state(menu.state);set_timer(menu.state);menu.set_flag = 0;break;
			case 1:if(menu.mode < 4){menu.mode++;}else{menu.mode=0;}show_set_bx(menu.mode);menu.set_flag = 0;break;
		}
	}else{
		show_set_pl(menu.frequent);
		show_set_zkb(menu.compare);
		show_set_main(menu.position);
	}
}

