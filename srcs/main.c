#include "fractol.h"
#include "libft.h"
#include "mlx.h"

static int	ft_error(char *msg)
{
	ft_putendl(msg);
	ft_putendl("Choose one of the following:");
	ft_putendl("Mandelbrot, Julia, Burningship");
	return (1);
}

static void	hooks(t_env	*env)
{
	mlx_key_hook(env->win, hook_keydown, &env);
	mlx_hook(env->win, 4, 1L << 2, hook_mousedown, &env);
	mlx_hook(env->win, 5, 1L << 3, hook_mouseup, &env);
	mlx_hook(env->win, 6, 1L << 6, hook_mousemove, &env);
}

int	main(int ac, char **av)
{
	t_env	*env;

	if (ac < 2)
		return (ft_error("Usage: ./fractol [set] [rnumber] [inumber]"));
	if (match(av[1]) == 0)
		return (ft_error("Error: invalid name"));
	if ((env = init(av[1])) == NULL)
		return (ft_error("Error: mlx init fail"));
	reset_viewport(env);
	render(env);
	hooks(env);
	mlx_loop(env->mlx);
}
