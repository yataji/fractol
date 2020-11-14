/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:43:23 by yataji            #+#    #+#             */
/*   Updated: 2020/11/14 04:33:57 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

double		absolu(double calc)
{
	if (calc > 0)
		return (calc);
	else
		return (calc * -1.0);
}

void		set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
}

int			keypress(int key, void *param)
{
	t_mlx	*mlx;
	double	per;

	mlx = (t_mlx *)param;
	key == 53 ? exit(0) : 0;
	key == 15 ? mlx->w.xmin = -2 : 0;
	key == 15 ? mlx->w.ymin = -2 : 0;
	key == 15 ? mlx->w.xmax = 2 : 0;
	key == 15 ? mlx->w.ymax = 2 : 0;
	key == 126 || key == 125 ? per = (mlx->w.ymax - mlx->w.ymin) * 0.05 : 0;
	key == 126 ? mlx->w.ymin += per : 0;
	key == 126 ? mlx->w.ymax += per : 0;
	key == 125 ? mlx->w.ymin -= per : 0;
	key == 125 ? mlx->w.ymax -= per : 0;
	key == 123 || key == 124 ? per = (mlx->w.xmax - mlx->w.xmin) * 0.05 : 0;
	key == 123 ? mlx->w.xmin += per : 0;
	key == 123 ? mlx->w.xmax += per : 0;
	key == 124 ? mlx->w.xmin -= per : 0;
	key == 124 ? mlx->w.xmax -= per : 0;
	choice(mlx);
	return (0);
}

void		choice(t_mlx *mlx)
{
	if (*mlx->ac == '3')
		burningship_thread(mlx);
	if (*mlx->ac == '2')
		julia_thread(mlx);
	if (*mlx->ac == '1')
		mandelbrot_thread(mlx);
}

int			mousemove(int mx, int my, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx *)param;
	if (!mlx->pause && *mlx->ac == '2')
	{
		set(mlx, &mlx->c, mx, my);
		choice(mlx);
	}
	return (0);
}
