/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:45:43 by yataji            #+#    #+#             */
/*   Updated: 2020/11/08 04:43:51 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x =  (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y =  (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
}

int		julia(t_mlx *mlx)
{
	double		x;
	double		y;
	t_point		z;
	int			iter;

	x=-1;
	while (++x < MAXWIDTH)
	{
		y = -1;
		while (++y < MAXHEIGHT)
		{
			z.x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
			z.y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
			iter = 1;
			while (powf(z.x, 2) + powf(z.y, 2) < 4 && iter < MAXIT)
			{
				double tmp = z.x;
				z.x = powf(z.x, 2) - powf(z.y, 2) + mlx->c.x;
				z.y = (2 * tmp * z.y + mlx->c.y);
				iter++;
			}
			revers(mlx, x, y, !mlx->color ? color(iter) : colora(iter));
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return 0;
}
