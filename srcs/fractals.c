#include "libft.h"
#include "fractol.h"

int	match(char *name)
{
	if (!ft_strncmp("Mandelbrot", name, 10))
		return (MANDEL);
	else if (!ft_strncmp("Julia", name, 5))
		return (JULIA);
	else if (!ft_strncmp("Burningship", name, 11))
		return (BS);
	else
		return (0);
}

