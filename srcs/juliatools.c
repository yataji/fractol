/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliatools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 06:09:37 by yataji            #+#    #+#             */
/*   Updated: 2020/11/20 02:11:08 by yataji           ###   ########.fr       */
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

void		menujulia(t_mlx *mlx, int button, int x, int y)
{
	if (button == 5)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 70, 0xffff00, ft_itoa(x)) : 0;
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 90, 0xffff00, ft_itoa(y)) : 0;
	}
	else if (button == 4)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 70, 0xffff00, ft_itoa(x)) : 0;
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 90, 0xffff00, ft_itoa(y)) : 0;
	}
}
