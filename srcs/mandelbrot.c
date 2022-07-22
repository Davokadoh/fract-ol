#include "fractol.h"

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

void	mandelbrot_viewport(t_viewport *view)
{
	view->xmin = -2.0f;
	view->xmax = 1.0f;
	view->ymin = -1.0f;
	view->ymax = 1.0f;
	view->offx = -0.5f;

}
