#include "fractol.h"

/*
int	mandelbrot_iterate(t_cmplx c)
{
	int	r_sqr;
	int	i_sqr;
	int	index;
	t_cmplx	z;

	z = c;
	index = 0;
	while (index < 50) //Change 50 to MAX
	{
		r_sqr = z.r * z.r; 
		i_sqr = z.i * z.i;
		if (r_sqr + i_sqr > 4)
		{
			index = 50;
			break;
		}
		z.i = 2 * z.r * z.i + c.i;
		z.r = r_sqr - i_sqr + c.r; //maybe r2 - i2
		index++;
	}
	return (index);
}
*/

void	mandelbrot_viewport(t_viewport *view)
{
	view->xmin = -2.0f;
	view->xmax = 1.0f;
	view->ymin = -1.0f;
	view->ymax = 1.0f;
	view->offx = -0.5f;
}

int	mandelbrot_iterate(t_cmplx c)
{
	t_cmplx	z;
	t_cmplx	temp;
	int			i;
	int max = 100;

	z = c;
	i = 0;
	while (z.r * z.r + z.i * z.i < (1 << 8) && i < max)
	{
		temp.r = z.r * z.r - z.i * z.i + c.r;
		temp.i = z.r * z.i * 2 + c.i;
		if (z.r == temp.r && z.i == temp.i)
		{
			i = max;
			break ;
		}
		z.r = temp.r;
		z.i = temp.i;
		i++;
	}
	return (i);
}

