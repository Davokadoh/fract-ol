int	color(int x, int y, t_pixel *pixels, t_palette palette)
{
	pixels[x + y * WIN_W];
	return (x + y);
}

void	put_pixel(t_img *img, int color)
{
	if (x >= 0 && y >= 0 && x < WIN_W && y < WIN_H)
		*(unsigned int*)img->ptr +
			(y * img->line_size + x * img->bpp >> 3) = color;
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
			env->pixels[x + y * WIN_W] = env->fractal->iterate(x, y, viewport);
			put_pixel(env->img, x, y, color(x, y, env->pixels, env->palette));
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}
