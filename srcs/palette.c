#include "fractol.h"

t_palette	get_palette(int i)
{
	if (i == 0)
		return (t_palette){5, {0x333333, 0x995555, 0x888888, 0xAAAAAA, 0xDDDDDD}};
	else if (i == 1)
		return (t_palette){5, {0x331C0D, 0x3C3717, 0x32682B, 0x4F9340, 0xA1D700}};
	else
		return (t_palette){5, {0x0D1C33, 0x17373C, 0x2B6832, 0x4F9300, 0xA1D700}};
}
