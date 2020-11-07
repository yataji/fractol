/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 13:35:24 by yataji            #+#    #+#             */
/*   Updated: 2020/11/06 04:48:00 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_mlx param)
{
	t_mlx *mlx = &param;
	double x, y;
	t_point	c;
	t_point	z;
	int	iter;

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
				c.x =  4 * x / MAXWIDTH - 2;
				c.y = 4 * y / MAXHEIGHT - 2;
				iter = 1;
				while (powf(z.x, 2) + powf(z.y, 2) < 4 && iter < MAXIT)
				{
					double tmp = z.x;
					z.x = (powf(z.x, 2) - powf(z.y, 2) + c.x);
					z.y = (2 * tmp * z.y + c.y);
					iter++;
				}
				revers(mlx, x, y, color(iter));
			}
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return 0;
}
