#include "mytim.h"

extern mymenu menu;
mywave wave;

u16 i=0;
//100000hz,fre:  min:1000hz,max:1hz
//compare 0-100
//10us in
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
	if(htim->Instance == TIM4){
		if(wave.current_tick < wave.cycle){
			wave.current_tick++;
		}else{
			wave.current_tick = 0;
		}
		
	}
}

void tim_init(void){
	wave_init();
	HAL_TIM_Base_Start_IT(&htim4);
	set_timer(0);
}

void set_timer(u8 num){
	htim4.Instance->CR1 = num;
}

float Get_ADC_num(){
	float ADC_GET = 0;
	HAL_ADC_Start(&hadc1);
	ADC_GET = ((float)HAL_ADC_GetValue(&hadc1)) / 4000;
	if(ADC_GET < 0.05f){
		ADC_GET = 0;
	}else if(ADC_GET > 1.0f){
		ADC_GET = 1.0f;
	}
	return ADC_GET;
}

