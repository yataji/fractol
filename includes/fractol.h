/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:56:18 by yataji            #+#    #+#             */
/*   Updated: 2020/11/06 03:55:48 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "../libft/libft.h"
#include "mlx.h"
#include <math.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MAXIT 50.0
#define MAXWIDTH 700.0
#define MAXHEIGHT 700.0
typedef struct point {
	double x;
	double y;
}		t_point;

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
} t_mlx;

int color(int iter);
int colora(int iter);
int	mousemove(int mx, int my, void * param);
int keypress(int key, void *param);
int mousepress(int button, int x, int y, void *param);
void revers(t_mlx *fdf, int x, int y, int color);
int julia(int mx, int my, void *param);
int mandelbrot(t_mlx param);
int test(t_mlx param);

#endif
