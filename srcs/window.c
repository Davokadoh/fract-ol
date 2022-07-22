#include <stdlib.h>
#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static t_img	*del_img(t_env *env)
{
	if (env->img)
	{
		if (env->img->bff)
			mlx_destroy_image(env->mlx, env->img->bff);
		//ft_memdel(env->&img); //Needs to be added to libft
	}
	return (NULL);
}

static t_img	*new_image(t_env *env)
{
	t_img	*img;

	if ((img = malloc(sizeof(t_img))) == NULL)
		return (NULL);
	if ((img->bff = mlx_new_image(env->mlx, WIN_W, WIN_H)) == NULL)
		return (del_img(env));
	img->ptr = mlx_get_data_addr(img->bff, &img->bpp, &img->line_size, &img->endian);
	return (img);
}

static t_env		*del_env(t_env *env)
{
	if (env->win != NULL)
		mlx_destroy_window(env->mlx, env->win);
	if (env->img != NULL)
		del_img(env);
	//ft_memdel((void **)&env);//Need to be added to libft
	return (NULL);
}

t_env	*init(char *fractal)
{
	t_env	*env;
	char	*title;

	if ((env = malloc(sizeof(t_env))) == NULL)
		return (NULL);
	title = ft_strjoin("fract'ol - ", fractal);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, WIN_W, WIN_H, title);
	free(title);
	env->img = new_image(env);
	env->pixels = malloc(sizeof(t_pixel) * WIN_W * WIN_H);
	if (env == NULL || env->mlx == NULL || env->win == NULL || env->img == NULL || env->pixels == NULL)
		return (del_env(env));
	env->mouse.down = 0;
	env->palette = get_palette(2);
	env->smooth = 1;
	return (env);
}
