/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2022/07/22 15:30:27 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		hook_mousedown(int button, int x, int y, t_env *env)
{
	if (button == 4)
	{
		zoom(x, y, &env->viewport, 1 / ZOOM);
		render(env);
	}
	else if (button == 5)
	{
		zoom(x, y, &env->viewport, ZOOM);
		render(env);
	}
	if (y < 0)
		return (0);
	env->mouse.down |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	env->mouse.down &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_env *env)
{
	double w;
	double h;

	env->mouse.last_x = env->mouse.x;
	env->mouse.last_y = env->mouse.y;
	env->mouse.x = x;
	env->mouse.y = y;
	env->viewport.mouse = pixel_to_cmplx(x, y, &env->viewport);
	if (env->mouse.down & (1 << 1))
	{
		w = (env->viewport.xmax - env->viewport.xmin) * env->viewport.zoom;
		h = (env->viewport.ymax - env->viewport.ymin) * env->viewport.zoom;
		env->viewport.offx += (double)(env->mouse.last_x - env->mouse.x)
			/ WIN_W * w;
		env->viewport.offy += (double)(env->mouse.last_y - env->mouse.y)
			/ WIN_H * h;
	}
	if (env->mouse.down)
		render(env);
	return (0);
}
