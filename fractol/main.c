/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 02:40:16 by yataji            #+#    #+#             */
/*   Updated: 2020/10/12 23:04:05 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define  MAXIT 50.0
#define  MAXWIDTH 500.0
#define  MAXHEIGHT 500.0
typedef struct t_point {
	double x;
	double y;
}		point;

typedef struct	mlx {
	void *init;
	void *win;
	int	julia;
	int	pause;
} t_mlx;

int color(int iter);
int	mousemove(int mx, int my, void * param);


int keypress(int key, void *param) 
{
	t_mlx * mlx= (t_mlx *)param;

	if (key == 53)
		exit(0);
	if(key == 69)
		mlx->julia = !mlx->julia ? 1 : 0;
	printf(" key %d\n", key);
	return 0;
}

int mousepress(int button, int x, int y, void *param) 
{
	t_mlx	*mlx = (t_mlx *)param;

	if (button == 1)
		mlx->pause =  mlx->pause ? 0 : 1;
	return (0);
}

int	mousemove(int mx, int my, void * param)
{
	t_mlx *mlx = (t_mlx *)param;
	double x, y;
	point	c;
	point	z;
	int	iter;

	if (!mlx->pause) 
	{
		mlx_clear_window(mlx->init, mlx->win);
		c.x = 4 * mx / MAXWIDTH - 2;
		c.y = 4 * my / MAXHEIGHT - 2;
		x=-1;
		while (++x < MAXWIDTH)
		{
			y = -1;
			while (++y < MAXHEIGHT)
			{
				z.x = mlx->julia ? 4 * x / MAXWIDTH - 2 : 0;
				z.y = mlx->julia ? 4 * y / MAXHEIGHT - 2 : 0;
				!mlx->julia ? c.x =  4 * x / MAXWIDTH - 2 : 0;
				!mlx->julia ? c.y = 4 * y / MAXHEIGHT - 2 : 0;
				//c.y = 0.088;
				//c.x = -0.46;
				iter = 1;
				while (powf(z.x, 2) + powf(z.y, 2) < 4 && iter < MAXIT)
				{
					double tmp = z.x;
					z.x = (powf(z.x, 2) - powf(z.y, 2) + c.x);
					z.y = (2 * tmp * z.y + c.y);
					iter++;
				}
				mlx_pixel_put(mlx->init, mlx->win, x, y, iter  == MAXIT ? 0:color(iter));
			}
		}
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

int main(int av, char **ac)
{
	double	x;
	double	y;
	int	iter;
	point	c = {1, 0};
	point	z;
	t_mlx	mlx;

	if (av != 2 && av != 3)
		ft_putendl("Usage error!!");
	else
	{
		mlx.pause = 0;
		mlx.julia = 0;
		mlx.init = mlx_init();
		mlx.win = mlx_new_window(mlx.init, MAXWIDTH, MAXHEIGHT, "fractall");
		mlx_hook(mlx.win, 2, 0, &keypress, &mlx);
		mlx_hook(mlx.win, 6, 0, &mousemove, &mlx);
		mlx_hook(mlx.win, 4, 0, &mousepress, &mlx);
		mlx_loop(mlx.init);
	}
	return 0;
}
