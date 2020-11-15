/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2020/11/15 07:11:24 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		changefrctandreseet(t_mlx *mlx, int key)
{
	if (key == 36)
	{
		mlx->w.xmin = -2;
		mlx->w.ymin = -2;
		mlx->w.xmax = 2;
		mlx->w.ymax = 2;
		if (mlx->ac[0] == '1')
			mlx->ac[0] = '2';
		else if (mlx->ac[0] == '2')
			mlx->ac[0] = '3';
		else if (mlx->ac[0] == '3')
			mlx->ac[0] = '1';
	}
	else
	{
		key == 15 ? mlx->w.xmin = -2 : 0;
		key == 15 ? mlx->w.ymin = -2 : 0;
		key == 15 ? mlx->w.xmax = 2 : 0;
		key == 15 ? mlx->w.ymax = 2 : 0;
		key == 15 ? mlx->r.i = 0 : 0;
		key == 15 ? mlx->r.j = 1 : 0;
		key == 15 ? mlx->r.l = 2 : 0;
	}
}

int			keypress(int key, void *param)
{
	t_mlx	*mlx;
	double	per;

	mlx = (t_mlx *)param;
	changefrctandreseet(mlx, key);
	key == 53 ? exit(0) : 0;
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

t_mlx		init(char *ac)
{
	t_mlx	mlx;

	mlx.w.xmin = -2;
	mlx.w.ymin = -2;
	mlx.w.xmax = 2;
	mlx.w.ymax = 2;
	mlx.c = (t_point){0.0, 0.0};
	mlx.bpp = 0;
	mlx.size_line = 0;
	mlx.julia = 0;
	mlx.pause = 0;
	mlx.color = 0;
	mlx.ac = ac;
	mlx.r.i = 0;
	mlx.r.j = 1;
	mlx.r.l = 2;
	return (mlx);
}

void		menu(t_mlx mlx)
{
	mlx.ac[0] == '1' ? mlx_string_put(mlx.ptr, mlx.win_ptr, MAXWIDTH / 2 - 30,
			MAXHEIGHT + 10, 0xffff00, "Mandelbrot") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, MAXWIDTH / 2 - 30,
			MAXHEIGHT + 10, 0xffff00, "Julia") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 150,
			MAXHEIGHT + 150, 0xffff00,
			"Mouse Left Button = stop && start moving julia") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 350,
			MAXHEIGHT + 70, 0xffff00, "Mouse x = ") : 0;
	mlx.ac[0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 350,
			MAXHEIGHT + 90, 0xffff00, "Mouse y = ") : 0;
	mlx.ac[0] == '3' ? mlx_string_put(mlx.ptr, mlx.win_ptr, MAXWIDTH / 2 - 30,
			MAXHEIGHT + 10, 0xffff00, "Burningship") : 0;
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 30, 0xffff00,
			"R           = Reset");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 50, 0xffff00,
			"c           = Color");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 70, 0xffff00,
			"Scroll UP   = Zoom UP");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 90, 0xffff00,
			"Scroll DOWN = Zoom DOWN");
	mlx_string_put(mlx.ptr, mlx.win_ptr, 10, MAXHEIGHT + 110, 0xffff00,
			"Entrer      = Change fractol");
}

int			main(int av, char **ac)
{
	t_mlx	mlx;

	if (av == 2)
		if (ac[1][0] == '1' || ac[1][0] == '2' || ac[1][0] == '3')
		{
			mlx = init(ac[1]);
			mlx.ptr = mlx_init();
			mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT + 200
					, "fractol");
			mlx.img_ptr = mlx_new_image(mlx.ptr, MAXWIDTH, MAXHEIGHT);
			mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
					&mlx.size_line, &mlx.end);
			choice(&mlx);
			mlx_hook(mlx.win_ptr, 6, 0, &mousemove, &mlx);
			mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
			mlx_hook(mlx.win_ptr, 2, 0, &keypress, &mlx);
			mlx_loop(mlx.ptr);
		}
	if (av != 2 || ac[1][0] != '1' || ac[1][0] != '2' || ac[1][0] != '3')
	{
		ft_putendl("Usage: ./fractol \"chose (1 || 2 || 3).\"\n");
		ft_putendl("1 - mandelbrot.\n2 - julia.\n3 - burningship");
	}
	return (0);
}
