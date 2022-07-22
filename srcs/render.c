#include "fractol.h"
#include "mlx.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		*(unsigned int *)(img->ptr + (y * img->line_size + x * img->bpp / 8)) = color;
}

static int	color(int x, int y, t_env *env)
{
	unsigned int i;

	i = env->pixels[x + y * WIN_W].iterations;
	//if (i > 50) // change to maxIter
	//	return (0);
	return (env->palette.colors[i % env->palette.size]);
}

t_cmplx	pixel_to_cmplx(int x, int y, t_viewport *v)
{
	t_cmplx	c;


	c.r = (((double)x / WIN_W) * (v->xmax - v->xmin)) * v->zoom
		+ v->xmin + v->offx;
	c.i = (((double)y / WIN_H) * (v->ymax - v->ymin)) * v->zoom
		+ v->ymin + v->offy;
	return (c);
}

static int iterate(t_env *env, int x, int y)
{
	t_cmplx	c;

	c = pixel_to_cmplx(x, y, &env->viewport);
	if (env->name == JULIA)
		return (julia_iterate(c));
	else if (env->name == MANDEL)
		return (mandelbrot_iterate(c));
	else if (env->name == BS)
		return (burningship_iterate(c));
	else
		return (0);
}

void	render(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			env->pixels[x + y * WIN_W].iterations = iterate(env, x, y);
			put_pixel(env->img, x, y, color(x, y, env));
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->bff, 0, 0);
}

