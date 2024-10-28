#include "wave.h"

void wave_init(void){
	HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, 2048);
	HAL_DAC_Start(&hdac1,DAC_CHANNEL_1);
}

//T = 100-100000,num=0-T
void set_square_wave(u32 T,u32 count,u8 compare){
	if(count <= (u32)(T * (((float)compare)/100.0f))){
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MAX);
	}else{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MIN);
	}
}

u32 sin_out_data = 0;
void set_sine_wave(u32 T,u32 count,u8 compare){
	if(count <= (u32)((float)T * (((float)compare)/100.0f))){
		float i = (float)(count) / (float)(T);
		sin_out_data =  (u32)(2047.0f * (1.0f + sin(2.0f*PI*i)));
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, sin_out_data);
	}else{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MIN);
	}
}

void set_triangle_wave(u32 T,u32 count,u8 compare){
	if(count <= (u32)((float)T * (((float)compare)/100.0f))){
		u32 out_data = 0;
		float k = 0;
		k = (2 * DAC_MAX) / T;
		if(count <= (u32)(0.5f * T)){
			out_data = k * count - 1;
		}else{
			out_data = 8000 - (k * count);
		}
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, out_data);
	}else{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MIN);
	}
}

void set_flat_top_wave(u32 T,u32 count,u8 compare){
	if(count <= (u32)((float)T * (((float)compare)/100.0f))){
		u32 out_data = 0;
		float k = 0;
		k = ((float)DAC_MAX) / (0.2f * (float)T);
		
		if(count < (u32)(0.2f * (float)T)){
			out_data = (u32)(k * (float)count);
		}else if(count <= (u32)(0.8f * (float)T)){
			out_data = DAC_MAX;
		}else{
			out_data = 4095 - (k * (count - (0.8f * T)));
		}
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, out_data);
	}else{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MIN);
	}
}

void set_sawtooth_wave(u32 T,u32 count,u8 compare){
	if(count <= (u32)((float)T * (((float)compare)/100.0f))){
		u32 out_data = 0;
		float k = 0;
		k = (float)DAC_MAX/(float)T;
		out_data = (u32)(k * (float)count);
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, out_data);
	}else{
		HAL_DAC_SetValue(&hdac1, DAC_CHANNEL_1, DAC_ALIGN_12B_R, DAC_MIN);
	}
}
