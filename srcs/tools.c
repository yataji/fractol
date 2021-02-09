/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 05:43:23 by yataji            #+#    #+#             */
/*   Updated: 2021/02/02 19:32:47 by yataji           ###   ########.fr       */
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

int					clr(int iter, t_mlx mlx)
{
	double			per;
	int				color;
	unsigned char	*ptr;

	per = iter / mlx.it;
	ptr = (unsigned char *)&color;
	ptr[3] = 0;
	ptr[mlx.r.i] = 255 * (1.0 - per) * powf(per, 3) * 9;
	ptr[mlx.r.j] = 255 * powf(1.0 - per, 2) * powf(per, 2) * 15;
	ptr[mlx.r.l] = 255 * powf(1.0 - per, 3) * per * 8.5;
	return (color);
}

int					ft_exit(t_mlx *mlx, int key)
{
	mlx_clear_window(mlx->ptr, mlx->win_ptr);
	mlx_destroy_window(mlx->ptr, mlx->win_ptr);
	key == 36 ? main(2, mlx->ac) : exit(0);
	return (0);
}
