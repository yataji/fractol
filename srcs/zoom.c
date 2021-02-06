/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 03:45:34 by yataji            #+#    #+#             */
/*   Updated: 2021/02/02 19:32:49 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void		applyzoom(t_mlx *e, double mouser, double mousei, double zoomfctr)
{
	double	interpolation;

	interpolation = zoomfctr;
	e->w.xmin = interpolate(mouser, e->w.xmin, interpolation);
	e->w.ymin = interpolate(mousei, e->w.ymin, interpolation);
	e->w.xmax = interpolate(mouser, e->w.xmax, interpolation);
	e->w.ymax = interpolate(mousei, e->w.ymax, interpolation);
}
