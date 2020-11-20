/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yataji <yataji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 11:56:18 by yataji            #+#    #+#             */
/*   Updated: 2020/11/20 02:11:03 by yataji           ###   ########.fr       */
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

typedef struct	s_color
{
	int			i;
	int			j;
	int			l;
}				t_color;

typedef	struct	s_mlx	{
	void		*ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			*dtadd;
	int			color;
	int			bpp;
	double		it;
	int			size_line;
	int			end;
	int			julia;
	int			pause;
	int			itr[4];
	double		tmp[4];
	char		*ac;
	t_point		c;
	t_move		w;
	t_color		r;
}				t_mlx;

typedef struct	s_thread {
	double		x;
	double		y;
	t_point		z;
	t_point		c;
}				t_thread;

void			applyzoom(t_mlx *e, double mouser, double mousei, double zoomfctr);
void			menujulia(t_mlx *mlx, int button, int x, int y);
double			absolu(double calc);
void			dt(t_mlx *mlx, int x, int y, int color);
int				clr(int iter, t_mlx mlx);
void			choice(t_mlx *mlx);
int				ft_exit(t_mlx *mlx);
void			changecolor(t_mlx *mlx);
void			burningship_thread(t_mlx *mlx);
void			mandelbrot_thread(t_mlx *mlx);
void			julia_thread(t_mlx *mlx);
int				mousemove(int mx, int my, void *param);
int				mousepress(int button, int x, int y, void *param);
int				keypress(int key, void *param);
void			set(t_mlx *mlx, t_point *point, int x, int y);

#endif
