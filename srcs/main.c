/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2020/11/10 05:56:25 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					color(int iter)
{
	double			per;
	int				color;
	unsigned char	*ptr;

	per = iter / MXIT;
	ptr = (unsigned char *)&color;
	ptr[3] = 0;
	ptr[0] = 255 * (1.0 - per) * powf(per, 3) * 9;
	ptr[1] = 255 * powf(1.0 - per, 2) * powf(per, 2) * 15;
	ptr[2] = 255 * powf(1.0 - per, 3) * per * 8.5;
	return (color);
}

void				revers(t_mlx *fdf, int x, int y, int color)
{
	fdf->dtadd[x + y * (int)MAXWIDTH] = color;
}

t_mlx				init(char *ac)
{
	t_mlx			mlx;

	mlx.w.xmin = -2;
	mlx.w.ymin = -2;
	mlx.w.xmax = 2;
	mlx.w.ymax = 2;
	mlx.mx = 0;
	mlx.my = 0;
	mlx.c = (t_point){0.0, 0.0};
	mlx.bpp = 0;
	mlx.size_line = 0;
	mlx.julia = 0;
	mlx.pause = 0;
	mlx.color = 0;
	mlx.ac = ac;
	return (mlx);
}

int					main(int av, char **ac)
{
	t_mlx	mlx;

	if (av == 2)
	{
		mlx = init(ac[1]);
		mlx.ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT +
				200, "fractall");
		mlx.img_ptr = mlx_new_image(mlx.ptr, MAXWIDTH, MAXHEIGHT);
		mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
				&mlx.size_line, &mlx.end);
		choice(&mlx);
		mlx_hook(mlx.win_ptr, 6, 0, &mousemove, &mlx);
		mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
		mlx_hook(mlx.win_ptr, 2, 0, &keypress, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
	{
		ft_putendl("Usage: ./fractol chose (1 || 2 || 3).\n");
		ft_putendl("1 - mandelbrot.\n2 - julia.\n3 - burningship");
	}
	return (0);
}
