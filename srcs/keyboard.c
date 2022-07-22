/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 05:33:43 by pbondoer          #+#    #+#             */
/*   Updated: 2022/07/22 13:38:42 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "keys.h"
#include <stdlib.h>

int		draw_hooks(int key, t_env *env)
{
	int		doot;

	doot = 0;
	if (key >= K_DIGIT_1 && key <= K_DIGIT_1 + 3)
		env->palette = get_palette(key - K_DIGIT_1);
	else if (key == K_NUM_ENTER)
		env->smooth = 1 - env->smooth;
	else
		doot = 1;
	if (!doot)
		render(env);
	return (doot);
}

void	move(int key, t_env *env)
{
	double w;
	double h;

	w = (env->viewport.xmax - env->viewport.xmin) * env->viewport.zoom;
	h = (env->viewport.ymax - env->viewport.ymin) * env->viewport.zoom;
	if (key == K_UP)
		env->viewport.offy -= h * 0.05f;
	if (key == K_DOWN)
		env->viewport.offy += h * 0.05f;
	if (key == K_LEFT)
		env->viewport.offx -= w * 0.05f;
	if (key == K_RIGHT)
		env->viewport.offx += w * 0.05f;
}

int		hook_keydown(int key, t_env *env)
{
	if (key == K_ESC)
		exit(EXIT_SUCCESS);
	if (key == K_NUM_0)
		reset_viewport(env);
	if (key == K_NUM_MULT)
		env->viewport.max *= 2;
	if (key == K_NUM_DIV)
		if (env->viewport.max / 2 >= 2)
			env->viewport.max /= 2;
	if (key == K_NUM_PLUS)
		zoom(WIN_W / 2, WIN_H / 2, &env->viewport, 1 / ZOOM);
	if (key == K_NUM_MINUS)
		zoom(WIN_W / 2, WIN_H / 2, &env->viewport, ZOOM);
	move(key, env);
	if (draw_hooks(key, env))
		render(env);
	return (0);
}
