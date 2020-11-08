/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:56:18 by yataji            #+#    #+#             */
/*   Updated: 2020/11/08 05:19:09 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <stdio.h>

#include "../libft/libft.h"
#include "../minilibx/mlx.h"
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#define MAXIT 50.0
#define MAXWIDTH 700.0
#define MAXHEIGHT 700.0
typedef struct point {
	double x;
	double y;
}		t_point;


typedef struct	move {
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
} t_move;


typedef struct	mlx {
	void *ptr;
	void *win_ptr;
	void *img_ptr;
 	int *dtadd;
	int color;
	int bpp;
	int size_line;
	int end;
	int	julia;
	int	pause;
	int	mx;
	int	my;
	char	*ac;
	t_point	c;
	t_move	w;
} t_mlx;
void julia_thread(t_mlx *mlx);
void set(t_mlx *mlx, t_point *point, int x, int y);
void choice(t_mlx *mlx);
int color(int iter);
int colora(int iter);
int	mousemove(int mx, int my, void * param);
int keypress(int key, void *param);
int mousepress(int button, int x, int y, void *param);
void revers(t_mlx *fdf, int x, int y, int color);
void *julia(void *param);
int mandelbrot(t_mlx param);
int burningship(t_mlx param);

#endif
