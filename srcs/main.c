#include "fractol.h"
#include "libft.h"
#include "mlx.h"

void	hooks(t_mlx	*mlx)
{
	mlx_key_hook(mlx->win, hook_keydown, &mlx);
	//mlx_expose_hook(mlx->window, hook_expose, mlx); //what for
	mlx_hook(mlx->win, 4, 1L << 2, hook_mousedown, &mlx);
	mlx_hook(mlx->win, 5, 1L << 3, hook_mouseup, &mlx);
	mlx_hook(mlx->win, 6, 1L << 6, hook_mousemove, &mlx);
}

t_img	new_image(t_env *env)
{
	t_img	*img;

	img = malloc();
	img->img = mlx_new_image(env->mlx, WIN_W, WIN_H);
	img->ptr = mlx_get_data_addr(img->img, &img->bpp, &img->line_size,
		   	&img->endian);
	if (error)
		return (del_img());
}

t_env	init(t_fractl f)
{
	t_img	*img;
	t_env	*env;
	char	*title;

	env = malloc(sizeof(t_env));
	if (env == NULL)
		return (NULL);
	title = ft_strjoin("fract'ol - ", f->name);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, title);
	env->img = new_image(env);
	env->pixels = malloc(sizeof(t_pixel) * WIN_W * WIN_H);
	if (env == NULL || env->mlx == NULL || env->win == NULL || env->img == NULL
			env->pixels == NULL)
		return (free_exit());
	env->mouse.isdown = 0;
	env->fractal = f;
	env->mouselock = 1 - f->mouse // ???
	env->palette = get_palettes();
	env->smooth = 1;
	return (env);
}

int	main(int ac, char **av)
{
	t_env		env;
	t_frctl		f;

	if (ac < 2)
		return (ft_error("Usage: ./fractol [set] [rnumber] [inumber]"));
	if ((f = match(av[1]) == 0)
		return (ft_error("Error: invalid name"));
	if ((env = init(f)) == NULL)
		return (ft_error("Error: mlx init fail");
	render(env);
	hooks(env);
	mlx_loop(env->mlx);
	//return (0);
}
