#include "main.h"
#include "show.h"
#include "lcd.h"

#include "string.h"
#include "stdio.h"

void show_set_main(u8 num){	
	show_zt();
	show_bx();
	show_pl();
	show_zkb();
	color_set(0);
	switch(num){
		case 0:show_zt();break;
		case 1:show_bx();break;
		case 2:show_pl();break;
		case 3:show_zkb();break;
	}
	color_set(1);
}
void show_zt(void){
	LCD_ShowChar(Line0,319 - 10, 0);
	LCD_ShowChar(Line0,319 - 34, 1);
}
void show_bx(void){
	LCD_ShowChar(Line2,319 - 10, 2);
	LCD_ShowChar(Line2,319 - 34, 3);
	LCD_ShowChar(Line2,319 - 58, 4);
	LCD_ShowChar(Line2,319 - 82, 5);
}
void show_pl(void){
	LCD_ShowChar(Line4,319 - 10, 6);
	LCD_ShowChar(Line4,319 - 34, 7);
	LCD_ShowChar(Line4,319 - 58, 11);
	LCD_ShowChar(Line4,319 - 82, 12);
}
void show_zkb(void){
	LCD_ShowChar(Line6,319 - 10, 8);
	LCD_ShowChar(Line6,319 - 34, 9);
	LCD_ShowChar(Line6,319 - 58, 10);
	LCD_ShowChar(Line6,319 - 82, 11);
	LCD_ShowChar(Line6,319 - 106, 12);
}

void show_set_bx(u8 num){
	switch(num){
		case 0:show_fb();break;
		case 1:show_zxb();break;
		case 2:show_sjb();break;
		case 3:show_pdb();break;
		case 4:show_jcb();break;
	}
}
void show_fb(void){
	LCD_ShowChar(Line2,319 - 158, 17);
	LCD_ShowChar(Line2,319 - 182, 26);
	LCD_ShowChar(Line2,319 - 206, 250);
}
void show_zxb(void){
	LCD_ShowChar(Line2,319 - 158, 18);
	LCD_ShowChar(Line2,319 - 182, 19);
	LCD_ShowChar(Line2,319 - 206, 26);
}
void show_sjb(void){
	LCD_ShowChar(Line2,319 - 158, 20);
	LCD_ShowChar(Line2,319 - 182, 21);
	LCD_ShowChar(Line2,319 - 206, 26);
}
void show_pdb(void){
	LCD_ShowChar(Line2,319 - 158, 22);
	LCD_ShowChar(Line2,319 - 182, 23);
	LCD_ShowChar(Line2,319 - 206, 26);
}
void show_jcb(void){
	LCD_ShowChar(Line2,319 - 158, 24);
	LCD_ShowChar(Line2,319 - 182, 25);
	LCD_ShowChar(Line2,319 - 206, 26);
}


void show_set_pl(u16 data){
	char buf[10];
	sprintf(buf,"%04d",data);
	LCD_ShowString(Line4,319 - 158,(u8*)buf);
}
void show_set_zkb(u8 data){
	char buf[10];
	sprintf(buf,"%03d",data);
	LCD_ShowString(Line6,319 - 158,(u8*)buf);
}


void show_state(u8 state_num){
	if(state_num){
		LCD_ShowChar(Line0, 319 - 140, 13);
		LCD_ShowChar(Line0, 319 - 164, 14);
	}else{
		LCD_ShowChar(Line0, 319 - 140, 15);
		LCD_ShowChar(Line0, 319 - 164, 16);
	}
}
void color_set(u8 num){
	if(num){
		LCD_SetBackColor(White);
		LCD_SetTextColor(Black);
	}else{
		LCD_SetBackColor(Black);
		LCD_SetTextColor(White);
	}
}

