/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbondoer <pbondoer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/12 17:39:58 by pbondoer          #+#    #+#             */
/*   Updated: 2022/07/22 14:05:31 by jleroux          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft.h"

void		zoom(int x, int y, t_viewport *v, double z)
{
	double w;
	double h;
	double nw;
	double nh;

	w = (v->xmax - v->xmin) * (v->zoom);
	h = (v->ymax - v->ymin) * (v->zoom);
	nw = (v->xmax - v->xmin) * (v->zoom * z);
	nh = (v->ymax - v->ymin) * (v->zoom * z);
	v->zoom *= z;
	v->offx -= ((double)x / WIN_W) * (nw - w);
	v->offy -= ((double)y / WIN_H) * (nh - h);
}
