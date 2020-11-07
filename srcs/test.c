/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:50:03 by yataji            #+#    #+#             */
/*   Updated: 2020/11/06 04:31:02 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int test(t_mlx param)
{
	t_mlx *mlx = &param;
	double x, y;
	t_point c;
	t_point z;
	int iter;

	if (!mlx->pause)
	{
		//      mlx_clear_window(mlx->init, mlx->win);
		//      c.x = 4 * mx / MAXWIDTH - 2;
		//      c.y = 4 * my / MAXHEIGHT - 2;
		//      printf("%d mx: \t%d my: ", mx, my);
		x=-1;
		while (++x < MAXWIDTH)
		{
			y = -1;
			while (++y < MAXHEIGHT)
			{
				z.x = 0;
				z.y = 0;
				//c.x =  4 * x / MAXWIDTH - 2;
				//c.y = 4 * y / MAXHEIGHT - 2;
				c.y = 0.088;
				c.x = -0.46;
				iter = 1;
				while (powf(c.x, 2) + powf(c.y, 2) < 4 && iter < MAXIT)
				{
					double tmp = c.x;
					z.x = (powf(c.x, 2) - powf(c.y, 2) + z.x);
					z.y = (2 * tmp * z.y + z.y);
					iter++;
				}
				revers(mlx, x, y, color(iter));
				//my_pixel_put_to_image(mlx->img_color, mlx->dtadd, mlx->size_line, mlx->bpp, x, y);
				//  mlx_pixel_put(mlx.ptr, mlx.win_ptr, x, y, iter  == MAXIT ? 0:color(iter));
			}
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return 0;
}
