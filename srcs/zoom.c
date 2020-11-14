/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 03:45:34 by yataji            #+#    #+#             */
/*   Updated: 2020/11/14 03:48:09 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

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

int			mousepress(int button, int x, int y, void *param)
{
	t_mlx	*mlx;
	double	x1;
	double	y1;

	mlx = (t_mlx *)param;
	x1 = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	y1 = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
	if (button == 5)
	{
		applyzoom(mlx, x1, y1, 0.8);
	}
	else if (button == 4)
	{
		applyzoom(mlx, x1, y1, 1.2);
	}
	choice(mlx);
	if (button == 1)
		mlx->pause = !mlx->pause ? 1 : 0;
	return (0);
}
