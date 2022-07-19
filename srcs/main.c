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
