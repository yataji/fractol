/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juliatools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 06:09:37 by yataji            #+#    #+#             */
/*   Updated: 2021/02/02 19:32:38 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		set(t_mlx *mlx, t_point *point, int x, int y)
{
	char *sx;
	char *sy;

	sx = ft_itoa(x);
	sy = ft_itoa(y);
	point->x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
	mlx_string_put(mlx->ptr, mlx->win_ptr, 450, MAXWIDTH + 70,
			0xffff00, sx);
	mlx_string_put(mlx->ptr, mlx->win_ptr, 450, MAXWIDTH + 90,
			0xffff00, sy);
	ft_strdel(&sx);
	ft_strdel(&sy);
}

void		menujulia(t_mlx *mlx, int button, int x, int y)
{
	char *sx;
	char *sy;

	sx = ft_itoa(x);
	sy = ft_itoa(y);
	if (button == 5)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 70, 0xffff00, sx) : 0;
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 90, 0xffff00, sy) : 0;
	}
	else if (button == 4)
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 70, 0xffff00, sx) : 0;
		mlx->ac[0] == '2' ? mlx_string_put(mlx->ptr, mlx->win_ptr, 450,
				MAXWIDTH + 90, 0xffff00, sy) : 0;
	}
	ft_strdel(&sx);
	ft_strdel(&sy);
}
