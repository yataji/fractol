/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:43:23 by yataji            #+#    #+#             */
/*   Updated: 2020/11/15 07:11:28 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				dt(t_mlx *mlx, int x, int y, int color)
{
	mlx->dtadd[x + y * (int)MAXWIDTH] = color;
}

double				absolu(double calc)
{
	if (calc > 0)
		return (calc);
	else
		return (calc * -1.0);
}

void				changecolor(t_mlx *mlx)
{
	mlx->r.i++;
	mlx->r.j++;
	mlx->r.l++;
	mlx->r.l > 2 ? mlx->r.l = 0 : 0;
	mlx->r.j > 2 ? mlx->r.j = 0 : 0;
	mlx->r.i > 2 ? mlx->r.i = 0 : 0;
}

int					clr(int iter, int i, int j, int l)
{
	double			per;
	int				color;
	unsigned char	*ptr;

	per = iter / MXIT;
	ptr = (unsigned char *)&color;
	ptr[3] = 0;
	ptr[i] = 255 * (1.0 - per) * powf(per, 3) * 9;
	ptr[j] = 255 * powf(1.0 - per, 2) * powf(per, 2) * 15;
	ptr[l] = 255 * powf(1.0 - per, 3) * per * 8.5;
	return (color);
}

void				choice(t_mlx *mlx)
{
	if (*mlx->ac == '3')
	{
		burningship_thread(mlx);
		menu(*mlx);
	}
	else if (*mlx->ac == '2')
	{
		julia_thread(mlx);
		menu(*mlx);
	}
	else if (*mlx->ac == '1')
	{
		mandelbrot_thread(mlx);
		menu(*mlx);
	}
}
