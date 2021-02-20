/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:33:09 by yataji            #+#    #+#             */
/*   Updated: 2021/02/19 16:55:51 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		change(t_mlx *mlx)
{
	mlx->w.xmin = -2;
	mlx->w.ymin = -2;
	mlx->w.xmax = 2;
	mlx->w.ymax = 2;
	if (mlx->ac[1][0] == '1')
		mlx->ac[1][0] = '2';
	else if (mlx->ac[1][0] == '2')
		mlx->ac[1][0] = '3';
	else if (mlx->ac[1][0] == '3')
		mlx->ac[1][0] = '4';
	else if (mlx->ac[1][0] == '4')
		mlx->ac[1][0] = '1';
	ft_exit(mlx, 36);
}

void		changefrctandreseet(t_mlx *mlx, int key)
{
	if (key == 36)
		change(mlx);
	else
	{
		key == 15 ? mlx->w.xmin = -2 : 0;
		key == 15 ? mlx->w.ymin = -2 : 0;
		key == 15 ? mlx->w.xmax = 2 : 0;
		key == 15 ? mlx->w.ymax = 2 : 0;
		key == 15 ? mlx->r.i = 0 : 0;
		key == 15 ? mlx->r.j = 1 : 0;
		key == 15 ? mlx->r.l = 2 : 0;
		key == 15 ? mlx->it = 100.0 : 0;
	}
}

int			keypress(int key, void *param)
{
	t_mlx	*mlx;
	double	per;

	mlx = (t_mlx *)param;
	key == 36 || key == 15 ? changefrctandreseet(mlx, key) : 0;
	key == 53 ? ft_exit(mlx, 53) : 0;
	key == 69 ? mlx->it += 50 : 0;
	key == 78 && mlx->it > 50 ? mlx->it -= 50 : 0;
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
	key == 8 ? changecolor(mlx) : 0;
	mlx_clear_window(mlx->ptr, mlx->win_ptr);
	choice(mlx);
	return (0);
}

int			mousepress(int button, int x, int y, void *param)
{
	t_mlx	*mlx;
	double	x1;
	double	y1;

	mlx = (t_mlx *)param;
	x1 = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	y1 = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
	if (button == 5)
	{
		menujulia(mlx, button, x, y);
		applyzoom(mlx, x1, y1, 0.8);
	}
	else if (button == 4)
	{
		menujulia(mlx, button, x, y);
		applyzoom(mlx, x1, y1, 1.2);
	}
	choice(mlx);
	if (button == 1)
		mlx->pause = !mlx->pause ? 1 : 0;
	return (0);
}

int			mousemove(int mx, int my, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (!mlx->pause && mlx->ac[1][0] == '2')
	{
		mlx_clear_window(mlx->ptr, mlx->win_ptr);
		set(mlx, &mlx->c, mx, my);
		choice(mlx);
	}
	return (0);
}
