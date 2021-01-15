/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 00:50:03 by yataji            #+#    #+#             */
/*   Updated: 2020/12/28 16:55:24 by yataji           ###   ########.fr       */
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
			mlx->itr[0] = 1;
			while (n.z.x * n.z.x + n.z.y * n.z.y < 4 && ++mlx->itr[0] < mlx->it)
			{
				mlx->tmp[0] = n.z.x;
				n.z.x = absolu(n.z.x * n.z.x - n.z.y * n.z.y + n.c.x);
				n.z.y = absolu(2 * mlx->tmp[0] * n.z.y + n.c.y);
			}
			dt(mlx, n.x, n.y, clr(mlx->itr[0], *mlx));
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
			mlx->itr[1] = 1;
			while (n.z.x * n.z.x + n.z.y * n.z.y < 4 && ++mlx->itr[1] < mlx->it)
			{
				mlx->tmp[1] = n.z.x;
				n.z.x = absolu(n.z.x * n.z.x - n.z.y * n.z.y + n.c.x);
				n.z.y = absolu(2 * mlx->tmp[1] * n.z.y + n.c.y);
			}
			dt(mlx, n.x, n.y, clr(mlx->itr[1], *mlx));
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
			mlx->itr[2] = 1;
			while (n.z.x * n.z.x + n.z.y * n.z.y < 4 && ++mlx->itr[2] < mlx->it)
			{
				mlx->tmp[2] = n.z.x;
				n.z.x = absolu(n.z.x * n.z.x - n.z.y * n.z.y + n.c.x);
				n.z.y = absolu(2 * mlx->tmp[2] * n.z.y + n.c.y);
			}
			dt(mlx, n.x, n.y, clr(mlx->itr[2], *mlx));
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
			mlx->itr[3] = 1;
			while (n.z.x * n.z.x + n.z.y * n.z.y < 4 && ++mlx->itr[3] < mlx->it)
			{
				mlx->tmp[3] = n.z.x;
				n.z.x = absolu(n.z.x * n.z.x - n.z.y * n.z.y + n.c.x);
				n.z.y = absolu(2 * mlx->tmp[3] * n.z.y + n.c.y);
			}
			dt(mlx, n.x, n.y, clr(mlx->itr[3], *mlx));
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
