/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2020/11/06 04:32:27 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int keypress(int key, void *param) 
{
	t_mlx * mlx= (t_mlx *)param;

	if (key == 53)
	{
		//printf(" key %d\t julia %d\t pause %d", key, mlx->julia, mlx->pause);
		exit(0);
	}
	if(key == 124)
		mlx->julia = !mlx->julia ? 1 : 0;
	if(key == 76)
		mlx->color = !mlx->color ? 1 : 0;
	//printf(" key %d\n julia %d", key, mlx->julia);
	return 0;
}

int mousepress(int button, int x, int y, void *param) 
{
	t_mlx	*mlx = (t_mlx *)param;

	x = 0;
	y = 0;
	if (button == 1)
		mlx->pause =  !mlx->pause ? 1 : 0;
	return (0);
}

int colora(int iter)
{
    double per = iter / MAXIT; // lkhd3a kant hna iter / 50 == 0
    int color;
    unsigned char   *ptr = (unsigned char *)&color;

    ptr[3] = 0;
    ptr[1] = 255 * (1.0 - per) *  powf(per, 3) * 9;
    ptr[2] = 255 * powf(1.0 - per, 2) *  powf(per, 2) * 15;
    ptr[0] = 255 * powf(1.0 - per, 3) * per * 8.5;
    return color;
}

int color(int iter)
{
	double per = iter / MAXIT; // lkhd3a kant hna iter / 50 == 0 
	int	color;
	unsigned char	*ptr = (unsigned char *)&color;

	ptr[3] = 0;
	ptr[0] = 255 * (1.0 - per) *  powf(per, 3) * 9;
	ptr[1] = 255 * powf(1.0 - per, 2) *  powf(per, 2) * 15;
	ptr[2] = 255 * powf(1.0 - per, 3) * per * 8.5;
	return color;
}

void revers(t_mlx *fdf, int x, int y, int color)
{
    fdf->dtadd[x + y * (int)MAXWIDTH] = color;
}

int main(int av, char **ac)
{
	t_mlx	mlx;

	if (av == 2)
	{
			mlx.bpp = 0;
			mlx.size_line = 0;
			mlx.julia = 0;
			mlx.pause = 0;
			mlx.color = 0;
			mlx.ptr = mlx_init();
			mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT, "fractall");
			mlx.img_ptr = mlx_new_image(mlx.ptr, MAXWIDTH, MAXHEIGHT);
			mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_line, &mlx.end);
			if (ac[1][0] == '3')
				test(mlx);
			if (ac[1][0] == '2')
			{
				julia(0, 0, &mlx);
				mlx_hook(mlx.win_ptr, 6, 0, &julia, &mlx);
				mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
			}
			if (ac[1][0] == '1')
				mandelbrot(mlx);
			mlx_hook(mlx.win_ptr, 2, 0, &keypress, &mlx);
			mlx_loop(mlx.ptr);
	}
	else
		ft_putendl("Usage: ./fractol chose (1 || 2).\n1 - mandelbrot.\n2 - julia.");
	ac = NULL;
	return 0;
}
