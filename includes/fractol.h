/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:56:18 by yataji            #+#    #+#             */
/*   Updated: 2020/11/14 04:45:36 by yataji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "mlx.h"
# include <math.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# define MXIT 100.0
# define MAXWIDTH 700.0
# define MAXHEIGHT 700.0

typedef struct	s_point {
	double		x;
	double		y;
}				t_point;

typedef struct	s_move {
	double		xmin;
	double		xmax;
	double		ymin;
	double		ymax;
}				t_move;

typedef	struct	s_mlx	{
	void		*ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*dtadd;
	int			color;
	int			bpp;
	int			size_line;
	int			end;
	int			julia;
	int			pause;
	int			mx;
	int			my;
	int			iter[4];
	double		tmp[4];
	char		*ac;
	t_point		c;
	t_move		w;
}				t_mlx;
typedef struct	s_thread {
	double		x;
	double		y;
	t_point		z;
	t_point		c;
}				t_thread;

void	julia_thread(t_mlx *mlx);
void	set(t_mlx *mlx, t_point *point, int x, int y);
void	choice(t_mlx *mlx);
int		color(int iter);
int		colora(int iter);
int		mousemove(int mx, int my, void *param);
int		keypress(int key, void *param);
int		mousepress(int button, int x, int y, void *param);
void	revers(t_mlx *fdf, int x, int y, int color);
void	mandelbrot_thread(t_mlx *mlx);
void	burningship_thread(t_mlx *mlx);
double	absolu(double calc);

#endif
