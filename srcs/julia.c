/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 13:45:43 by yataji            #+#    #+#             */
/*   Updated: 2020/11/08 05:33:10 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void set(t_mlx *mlx, t_point *point, int x, int y)
{
	point->x =  (mlx->w.xmax - mlx->w.xmin) * x / MAXWIDTH + mlx->w.xmin;
	point->y =  (mlx->w.ymax - mlx->w.ymin) * y / MAXHEIGHT + mlx->w.ymin;
}


void		*julia(void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	double		x;
	double		y;
	t_point		z;
	int			iter;

	x= -1;
	while (++x < MAXWIDTH / 2)
	{
		y = -1;
		while (++y < MAXHEIGHT / 2)
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

void		*julia2(void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	double		x;
	double		y;
	t_point		z;
	int			iter;

	x = MAXWIDTH / 2 - 1;
	while (++x < MAXWIDTH)
	{
		y = -1;
		while (++y < MAXHEIGHT / 2)
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

void		*julia3(void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	double		x;
	double		y;
	t_point		z;
	int			iter;

	x=-1;
	while (++x < MAXWIDTH / 2)
	{
		y = MAXHEIGHT / 2 - 1;
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

void		*julia4(void *param)
{
	t_mlx *mlx = (t_mlx *)param;
	double		x;
	double		y;
	t_point		z;
	int			iter;

	x= MAXWIDTH / 2 - 1;
	while (++x < MAXWIDTH)
	{
		y = MAXHEIGHT / 2 - 1;
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
	return NULL;
}

void julia_thread(t_mlx *mlx)
{
	pthread_t thread[4];

	pthread_create(&thread[0], NULL, &julia, mlx);
	pthread_create(&thread[1], NULL, &julia2, mlx);
	pthread_create(&thread[2], NULL, &julia3, mlx);
	pthread_create(&thread[3], NULL, &julia4, mlx);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
}
