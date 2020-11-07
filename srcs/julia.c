/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:45:43 by yataji            #+#    #+#             */
/*   Updated: 2020/11/06 04:48:49 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		julia(int mx, int my, void *param)
{
	t_mlx		*mlx = (t_mlx *)param;
	double		x;
	double		y;
	t_point		c;
	t_point		z;
	int			iter;

	if (!mlx->pause)
	{
		c.x = 4 * mx / MAXWIDTH - 2;
		c.y = 4 * my / MAXHEIGHT - 2;
		x=-1;
		while (++x < MAXWIDTH)
		{
			y = -1;
			while (++y < MAXHEIGHT)
			{
				z.x = 4 * x / MAXWIDTH - 2;
				z.y = 4 * y / MAXHEIGHT - 2;
				iter = 1;
				while (powf(z.x, 2) + powf(z.y, 2) < 4 && iter < MAXIT)
				{
					double tmp = z.x;
					z.x = powf(z.x, 2) - powf(z.y, 2) + c.x;
					z.y = (2 * tmp * z.y + c.y);
					iter++;
				}
				revers(mlx, x, y, !mlx->color ? color(iter) : colora(iter));
			}
		}
		mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return 0;
}
