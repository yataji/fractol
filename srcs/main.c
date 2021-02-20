/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2021/02/20 17:29:59 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		choice(t_mlx *mlx)
{
	if (mlx->ac[1][0] == '4')
	{
		treecorns_thread(mlx);
		menu(*mlx);
	}
	else if (mlx->ac[1][0] == '3')
	{
		burningship_thread(mlx);
		menu(*mlx);
	}
	else if (mlx->ac[1][0] == '2')
	{
		julia_thread(mlx);
		menu(*mlx);
	}
	else if (mlx->ac[1][0] == '1')
	{
		mandelbrot_thread(mlx);
		menu(*mlx);
	}
}

char		*namefntr(char **ac)
{
	if (ac[1][0] == '1')
		return ("Mandelbrot");
	else if (ac[1][0] == '2')
		return ("Julia");
	else if (ac[1][0] == '3')
		return ("Burningship");
	else if (ac[1][0] == '4')
		return ("treecorns");
	return (NULL);
}

t_mlx		init(char **ac)
{
	t_mlx	mlx;

	mlx.w.xmin = -2;
	mlx.w.ymin = -2;
	mlx.w.xmax = 2;
	mlx.w.ymax = 2;
	mlx.it = 100.0;
	mlx.c = (t_point){0.0, 0.0};
	mlx.pause = 0;
	mlx.color = 0;
	mlx.ac = ac;
	mlx.r.i = 0;
	mlx.r.j = 1;
	mlx.r.l = 2;
	mlx.ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT + 200
			, namefntr(ac));
	mlx.img_ptr = mlx_new_image(mlx.ptr, MAXWIDTH, MAXHEIGHT);
	mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
			&mlx.size_line, &mlx.end);
	return (mlx);
}

int			main(int v, char **c)
{
	t_mlx	mlx;

	if (v == 2 && ft_strlen(c[1]) == 1)
		if (c[1][0] == '1' || c[1][0] == '2' ||
				c[1][0] == '3' || c[1][0] == '4')
		{
			mlx = init(c);
			choice(&mlx);
			mlx_hook(mlx.win_ptr, 6, 0, &mousemove, &mlx);
			mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
			mlx_hook(mlx.win_ptr, 2, 0, &keypress, &mlx);
			mlx_hook(mlx.win_ptr, 17, 0, &ft_exit, &mlx);
			mlx_loop(mlx.ptr);
		}
	if (v != 2 || c[1][0] != '1' || c[1][0] != '2' ||
			c[1][0] != '3' || c[1][0] != '4')
	{
		ft_putendl("Usage: ./fractol \"chose (1 || 2 || 3 || 4).\"\n");
		ft_putendl("1- mandelbrot.\n2- julia.\n3- burningship.\n4- treecorns.");
	}
	return (0);
}
