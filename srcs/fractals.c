#include "libft.h"
#include "fractol.h"

t_fractal	*get_fractals(void)
{
	static t_fractal array[8] = {
		{"mandelbrot", mandelbrot_viewport, mandelbrot_iterate, 0},
		{"julia", julia_viewport, julia_iterate, 1},
		{"burningship", burningship_viewport, burningship_iterate, 0},
		{NULL, NULL, NULL, 0}
	};

	return (array);
}

t_fractal	*match(char *str)
{
	t_frctl	*f;
	int		i;

	f = get_fractals();
	i = 0;
	while (f[i].name != NULL)
	{
		if (ft_strcmp(f[i].name, str) == 0)
			return (&f[i]);
		i++;
	}
	return (&f[i]);
}

