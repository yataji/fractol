/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 17:29:17 by yataji            #+#    #+#             */
/*   Updated: 2021/02/20 17:56:01 by yataji           ###   ########.fr       */
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
	mlx.ac[1][0] == '1' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Mandelbrot") : 0;
	mlx.ac[1][0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Julia") : 0;
	mlx.ac[1][0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 150, 0xffff00,
			"Mouse Left Button = stop && start") : 0;
	mlx.ac[1][0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 520,
			MAXHEIGHT + 170, 0xffff00, "moving julia") : 0;
	mlx.ac[1][0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 70, 0xffff00, "Mouse x   = ") : 0;
	mlx.ac[1][0] == '2' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 320,
			MAXHEIGHT + 90, 0xffff00, "Mouse y   = ") : 0;
	mlx.ac[1][0] == '3' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Burningship") : 0;
	mlx.ac[1][0] == '4' ? mlx_string_put(mlx.ptr, mlx.win_ptr, 10,
			MAXHEIGHT + 10, 0xffff00, "Treecorns") : 0;
	menu2(mlx);
}
