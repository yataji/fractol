/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:45:43 by yataji            #+#    #+#             */
/*   Updated: 2020/11/20 02:08:07 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*julia(void *param)
{
	t_mlx		*mlx;
	double		x;
	double		y;
	t_point		z;

	x = -1;
	mlx = (t_mlx *)param;
	while (++x < MAXWIDTH / 2)
	{
		y = -1;
		while (++y < MAXHEIGHT / 2)
		{
			z.x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
			z.y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
			mlx->itr[0] = 1;
			while (z.x * z.x + z.y * z.y < 4 && ++mlx->itr[0] < mlx->it)
			{
				mlx->tmp[0] = z.x;
				z.x = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = (2 * mlx->tmp[0] * z.y + mlx->c.y);
			}
			dt(mlx, x, y, clr(mlx->itr[0], *mlx));
		}
	}
	return (0);
}

void			*julia1(void *param)
{
	t_mlx		*mlx;
	double		x;
	double		y;
	t_point		z;

	x = MAXWIDTH / 2 - 1;
	mlx = (t_mlx *)param;
	while (++x < MAXWIDTH)
	{
		y = -1;
		while (++y < MAXHEIGHT / 2)
		{
			z.x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
			z.y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
			mlx->itr[1] = 1;
			while (z.x * z.x + z.y * z.y < 4 && ++mlx->itr[1] < mlx->it)
			{
				mlx->tmp[1] = z.x;
				z.x = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = (2 * mlx->tmp[1] * z.y + mlx->c.y);
			}
			dt(mlx, x, y, clr(mlx->itr[1], *mlx));
		}
	}
	return (0);
}

void			*julia2(void *param)
{
	t_mlx		*mlx;
	double		x;
	double		y;
	t_point		z;

	x = -1;
	mlx = (t_mlx *)param;
	while (++x < MAXWIDTH / 2)
	{
		y = MAXHEIGHT / 2 - 1;
		while (++y < MAXHEIGHT)
		{
			z.x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
			z.y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
			mlx->itr[2] = 1;
			while (z.x * z.x + z.y * z.y < 4 && ++mlx->itr[2] < mlx->it)
			{
				mlx->tmp[2] = z.x;
				z.x = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = (2 * mlx->tmp[2] * z.y + mlx->c.y);
			}
			dt(mlx, x, y, clr(mlx->itr[2], *mlx));
		}
	}
	return (0);
}

void			*julia3(void *param)
{
	t_mlx		*mlx;
	double		x;
	double		y;
	t_point		z;

	x = MAXWIDTH / 2 - 1;
	mlx = (t_mlx *)param;
	while (++x < MAXWIDTH)
	{
		y = MAXHEIGHT / 2 - 1;
		while (++y < MAXHEIGHT)
		{
			z.x = (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
			z.y = (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
			mlx->itr[3] = 1;
			while (z.x * z.x + z.y * z.y < 4 && ++mlx->itr[3] < mlx->it)
			{
				mlx->tmp[3] = z.x;
				z.x = z.x * z.x - z.y * z.y + mlx->c.x;
				z.y = (2 * mlx->tmp[3] * z.y + mlx->c.y);
			}
			dt(mlx, x, y, clr(mlx->itr[3], *mlx));
		}
	}
	return (0);
}

void			julia_thread(t_mlx *mlx)
{
	pthread_t	thread[4];

	pthread_create(&thread[0], NULL, &julia, mlx);
	pthread_create(&thread[1], NULL, &julia1, mlx);
	pthread_create(&thread[2], NULL, &julia2, mlx);
	pthread_create(&thread[3], NULL, &julia3, mlx);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
