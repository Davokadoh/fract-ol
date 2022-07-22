#include "fractol.h"

void	reset_viewport(t_env *env)
{
	if (env->name == JULIA)
		julia_viewport(&env->viewport);
	else if (env->name == BS)
		burningship_viewport(&env->viewport);
	else if (env->name == MANDEL)
		mandelbrot_viewport(&env->viewport);
}
