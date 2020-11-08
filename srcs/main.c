/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2020/11/08 04:16:53 by root             ###   ########.fr       */
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
	{
		mlx->w.xmax -= 0.1;
		mlx->w.xmin -= 0.1;
	}
	if(key == 76)
		mlx->color = !mlx->color ? 1 : 0;
	if (key == 123)
	{
		mlx->w.xmax += 0.1;
		mlx->w.xmin += 0.1;
	}
	key == 126 ? mlx->w.ymax += 0.1 : 0;
	key == 126 ? mlx->w.ymin += 0.1 : 0;
	/*if(key == 126)
	{
		mlx->w.ymax += 0.1;
		mlx->w.ymin += 0.1;
		choice(mlx);
	}*/
	if(key == 125)
	{
		mlx->w.ymax -= 0.1;
		mlx->w.ymin -= 0.1;
	}
	choice(mlx);
	//printf(" key %d\n",  key);
	return 0;
}

void choice(t_mlx *mlx)
{
	if (*mlx->ac == '3')
		burningship(*mlx);
	if (*mlx->ac == '2')
		julia(mlx);
	if (*mlx->ac == '1')
		mandelbrot(*mlx);

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

int	mousemove(int mx, int my, void *param)
{
	t_mlx *mlx = (t_mlx *)param;

	if (!mlx->pause && *mlx->ac == '2')
	 {
		set(mlx, &mlx->c, mx, my);
		choice(mlx);
	 }
	 return 0;
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

	mlx.w.xmin = -2;
	mlx.w.ymin = -2;
	mlx.w.xmax = 2;
	mlx.w.ymax = 2;
	mlx.mx = 0;
	mlx.my = 0;
	mlx.c = (t_point){0.0, 0.0};
	if (av == 2)
	{
		mlx.bpp = 0;
		mlx.size_line = 0;
		mlx.julia = 0;
		mlx.pause = 0;
		mlx.color = 0;
		mlx.ac = ac[1];
		mlx.ptr = mlx_init();
		mlx.win_ptr = mlx_new_window(mlx.ptr, MAXWIDTH, MAXHEIGHT + 200, "fractall");
		mlx.img_ptr = mlx_new_image(mlx.ptr, MAXWIDTH, MAXHEIGHT);
		mlx.dtadd = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_line, &mlx.end);
		choice(&mlx);
			mlx_hook(mlx.win_ptr, 6, 0, &mousemove, &mlx);
			mlx_hook(mlx.win_ptr, 4, 0, &mousepress, &mlx);
		mlx_hook(mlx.win_ptr, 2, 0, &keypress, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		ft_putendl("Usage: ./fractol chose (1 || 2).\n1 - mandelbrot.\n2 - julia.");
	ac = NULL;
	return 0;
}
