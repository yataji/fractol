/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:50:03 by yataji            #+#    #+#             */
/*   Updated: 2020/11/08 04:46:07 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	burningship(t_mlx param)
{
	t_mlx *mlx = &param;
	double x, y;
	t_point c;
	t_point z;
	int iter;

	if (!mlx->pause)
	{
		x=-1;
		while (++x < MAXWIDTH)
		{
			y = -1;
			while (++y < MAXHEIGHT)
			{
				z.x = 0;
				z.y = 0;
				c.x =  (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
				c.y =  (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
				iter = 1;
				while ((z.x * z.x) + (z.y * z.y) < 4 && iter < MAXIT)
				{
					double tmp = fabs(z.x * z.x - z.y * z.y + c.x);
					z.y = fabs(2 * z.x * z.y + c.y);
					z.x = tmp;
					iter++;
				}
				revers(mlx, x, y, color(iter));
			}
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return 0;
}
