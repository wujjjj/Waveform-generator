#ifndef __MYTIM_H
#define __MYTIM_H

#include "main.h"
#include "tim.h"
#include "adc.h"

#include "menu.h"
#include "wave.h"

typedef struct{
	u32 cycle;
	u32 current_tick;
}mywave;

void tim_init(void);
void set_timer(u8 num);
float Get_ADC_num(void);

#endif
