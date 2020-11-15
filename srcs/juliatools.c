/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliatools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 06:09:37 by yataji            #+#    #+#             */
/*   Updated: 2020/11/15 06:13:51 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
	mlx_string_put(mlx->ptr, mlx->win_ptr, 450, MAXWIDTH + 70,
			0xffff00, ft_itoa(x));
	mlx_string_put(mlx->ptr, mlx->win_ptr, 450, MAXWIDTH + 90,
			0xffff00, ft_itoa(y));
}

int			mousemove(int mx, int my, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->pause && *mlx->ac == '2')
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		set(mlx, &mlx->c, mx, my);
		choice(mlx);
	}
	return (0);
}
