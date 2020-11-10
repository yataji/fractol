/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:50:03 by yataji            #+#    #+#             */
/*   Updated: 2020/11/10 05:12:43 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			*burningship(void *param)
{
	t_mlx		*mlx;
	t_thread	n;

	n.x = -1;
	mlx = (t_mlx *)param;
	while (++n.x < MAXWIDTH / 2)
	{
		n.y = -1;
		while (++n.y < MAXHEIGHT / 2)
		{
			n.z.x = 0;
			n.z.y = 0;
			n.c.x = (mlx->w.xmax - mlx->w.xmin) * n.x / MAXWIDTH + mlx->w.xmin;
			n.c.y = (mlx->w.ymax - mlx->w.ymin) * n.y / MAXHEIGHT + mlx->w.ymin;
			mlx->iter[0] = 1;
			while (powf(n.z.x, 2) + powf(n.z.y, 2) < 4 && ++mlx->iter[0] < MXIT)
			{
				mlx->tmp[0] = n.z.x;
				n.z.x = fabs(powf(n.z.x, 2) - powf(n.z.y, 2) + n.c.x);
				n.z.y = fabs(2 * mlx->tmp[0] * n.z.y + n.c.y);
			}
			revers(mlx, n.x, n.y, color(mlx->iter[0]));
		}
	}
	return (0);
}

void			*burningship2(void *param)
{
	t_mlx		*mlx;
	t_thread	n;

	n.x = MAXWIDTH / 2 - 1;
	mlx = (t_mlx *)param;
	while (++n.x < MAXWIDTH)
	{
		n.y = -1;
		while (++n.y < MAXHEIGHT / 2)
		{
			n.z.x = 0;
			n.z.y = 0;
			n.c.x = (mlx->w.xmax - mlx->w.xmin) * n.x / MAXWIDTH + mlx->w.xmin;
			n.c.y = (mlx->w.ymax - mlx->w.ymin) * n.y / MAXHEIGHT + mlx->w.ymin;
			mlx->iter[1] = 1;
			while (powf(n.z.x, 2) + powf(n.z.y, 2) < 4 && ++mlx->iter[1] < MXIT)
			{
				mlx->tmp[1] = n.z.x;
				n.z.x = fabs(powf(n.z.x, 2) - powf(n.z.y, 2) + n.c.x);
				n.z.y = fabs(2 * mlx->tmp[1] * n.z.y + n.c.y);
			}
			revers(mlx, n.x, n.y, color(mlx->iter[1]));
		}
	}
	return (0);
}

void			*burningship3(void *param)
{
	t_mlx		*mlx;
	t_thread	n;

	n.x = -1;
	mlx = (t_mlx *)param;
	while (++n.x < MAXWIDTH / 2)
	{
		n.y = MAXHEIGHT / 2 - 1;
		while (++n.y < MAXHEIGHT)
		{
			n.z.x = 0;
			n.z.y = 0;
			n.c.x = (mlx->w.xmax - mlx->w.xmin) * n.x / MAXWIDTH + mlx->w.xmin;
			n.c.y = (mlx->w.ymax - mlx->w.ymin) * n.y / MAXHEIGHT + mlx->w.ymin;
			mlx->iter[2] = 1;
			while (powf(n.z.x, 2) + powf(n.z.y, 2) < 4 && ++mlx->iter[2] < MXIT)
			{
				mlx->tmp[2] = n.z.x;
				n.z.x = fabs(powf(n.z.x, 2) - powf(n.z.y, 2) + n.c.x);
				n.z.y = fabs(2 * mlx->tmp[2] * n.z.y + n.c.y);
			}
			revers(mlx, n.x, n.y, color(mlx->iter[2]));
		}
	}
	return (0);
}

void			*burningship4(void *param)
{
	t_mlx		*mlx;
	t_thread	n;

	n.x = MAXWIDTH / 2 - 1;
	mlx = (t_mlx *)param;
	while (++n.x < MAXWIDTH)
	{
		n.y = MAXHEIGHT / 2 - 1;
		while (++n.y < MAXHEIGHT)
		{
			n.z.x = 0;
			n.z.y = 0;
			n.c.x = (mlx->w.xmax - mlx->w.xmin) * n.x / MAXWIDTH + mlx->w.xmin;
			n.c.y = (mlx->w.ymax - mlx->w.ymin) * n.y / MAXHEIGHT + mlx->w.ymin;
			mlx->iter[3] = 1;
			while (powf(n.z.x, 2) + powf(n.z.y, 2) < 4 && ++mlx->iter[3] < MXIT)
			{
				mlx->tmp[3] = n.z.x;
				n.z.x = fabs(powf(n.z.x, 2) - powf(n.z.y, 2) + n.c.x);
				n.z.y = fabs(2 * mlx->tmp[3] * n.z.y + n.c.y);
			}
			revers(mlx, n.x, n.y, color(mlx->iter[3]));
		}
	}
	return (0);
}

void			burningship_thread(t_mlx *mlx)
{
	pthread_t	thread[4];

	pthread_create(&thread[0], NULL, &burningship, mlx);
	pthread_create(&thread[1], NULL, &burningship2, mlx);
	pthread_create(&thread[2], NULL, &burningship3, mlx);
	pthread_create(&thread[3], NULL, &burningship4, mlx);
	pthread_join(thread[0], NULL);
	pthread_join(thread[1], NULL);
	pthread_join(thread[2], NULL);
	pthread_join(thread[3], NULL);
	mlx_put_image_to_window(mlx->ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}
