#ifndef __WAVE_H
#define __WAVE_H

#include "main.h"
#include "dac.h"

#include "math.h"

#define PI 3.14159265358979323846f
#define DAC_MIN 0
#define DAC_MAX 4094

void wave_init(void);
void set_square_wave(u32 T,u32 count,u8 compare);
void set_sine_wave(u32 T,u32 count,u8 compare);
void set_triangle_wave(u32 T,u32 count,u8 compare);
void set_flat_top_wave(u32 T,u32 count,u8 compare);
void set_sawtooth_wave(u32 T,u32 count,u8 compare);

#endif
