/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2021/02/03 17:58:19 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		menu2(t_mlx mlx)
{
	char	*it;

	it = ft_itoa(mlx.it);
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 50, 0xffff00,
			"R           = Reset");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 70, 0xffff00,
			"c           = Color");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 150, 0xffff00,
			"+           = + 50 iteration");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 170, 0xffff00,
			"-           = - 50 iteration");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 90, 0xffff00,
			"Scroll UP   = Zoom UP");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 110, 0xffff00,
			"Scroll DOWN = Zoom DOWN");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 130, 0xffff00,
			"Entrer      = Change fractol");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 320, MAXHEIGHT + 110, 0xffff00,
			"iteration = ");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 450, MAXWIDTH + 110, 0xffff00,
			it);
	ft_strdel(&it);
}

void		menu(t_mlx mlx)
{
	mlx.ac[0] == '1' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Mandelbrot") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Julia") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 150, 0xffff00,
			"Mouse Left Button = stop && start") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 520,
			MAXHEIGHT + 170, 0xffff00, "moving julia") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 70, 0xffff00, "Mouse x   = ") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 90, 0xffff00, "Mouse y   = ") : 0;
	mlx.ac[0] == '3' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Burningship") : 0;
	mlx.ac[0] == '4' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Treecorns") : 0;
	menu2(mlx);
}

void		choice(t_mlx *mlx)
{
	if (*mlx->ac == '4')
	{
		treecorns_thread(mlx);
		menu(*mlx);
	}
	else if (*mlx->ac == '3')
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

t_mlx		init(char *ac)
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
	mlx.ac[0] = ac[0];
	mlx.r.i = 0;
	mlx.r.j = 1;
	mlx.r.l = 2;
	mlx.ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT + 200
			, "fractol");
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
			mlx = init(c[1]);
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
