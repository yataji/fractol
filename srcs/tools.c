/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:43:23 by yataji            #+#    #+#             */
/*   Updated: 2020/11/10 05:56:27 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
}

int			keypress(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	key == 53 ? exit(0) : 0;
	key == 123 ? mlx->w.xmax += 0.1 : 0;
	key == 123 ? mlx->w.xmin += 0.1 : 0;
	key == 124 ? mlx->w.xmax -= 0.1 : 0;
	key == 124 ? mlx->w.xmin -= 0.1 : 0;
	key == 126 ? mlx->w.ymax += 0.1 : 0;
	key == 126 ? mlx->w.ymin += 0.1 : 0;
	key == 125 ? mlx->w.ymax -= 0.1 : 0;
	key == 125 ? mlx->w.ymin -= 0.1 : 0;
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

int			mousepress(int button, int x, int y, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	x = 0;
	y = 0;
	if (button == 1)
		mlx->pause = !mlx->pause ? 1 : 0;
	return (0);
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
