/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:58:24 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/07 03:58:07 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTAL_H
# define FRACTAL_H

# include "libft/libft.h"
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define MANDELBROT (fractal->type == 1)
# define JULIA (fractal->type == 2)
# define LATER (fractal->type == 4)

# define WIDTH_JULIA 1000
# define HEIGHT_JULIA 1200
# define WIDTH_MA 900
# define HEIGHT_MA 1000

# define GREEN 0X006400
typedef struct s_cmplx		t_cmplx;
typedef struct s_fractal	t_fractal;
typedef struct s_env	t_env;
typedef struct s_i2		t_i2;
typedef struct s_d2		t_d2;
typedef struct s_win	t_win;
typedef struct s_img	t_img;

struct		s_cmplx
{
	double	re;
	double	img;
};

struct		s_i2
{
	int		x;
	int		y;
};

struct		s_d2
{
	double	x;
	double	y;
};

struct		s_fractal
{
	char	type;
	t_cmplx	z;
	t_cmplx	c;
	int		zoom;
	int		color;
	int		max_it;
	int		x_range;
	int		y_range;
	t_i2	offset;
	t_d2	max;
	t_d2	min;
	t_env	*env;
};

struct		s_win
{
	void	*con_ptr;
	void	*win_ptr;
	t_i2	size;
	char	*title;
};

struct		s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		sl;
	int		endian;
};

struct		s_env
{
	void	*con_ptr;
	t_win	*win;
	t_img	img;
};

void		ft_setup(t_env *env, t_fractal *fractal);
void		mandelbrot_set(t_fractal *fractal);
void		set_mandelbrot(t_fractal *fractal);
void    	*mandelbrot_set1(void *fractal);
void    	*mandelbrot_set2(void *fractal);
void    	*mandelbrot_set3(void *fractal);
void    	*mandelbrot_set4(void *fractal);
int			draw_mandelbrot(t_fractal *fractal, int i, int j);
int			deal_key(int key, void *fractal);
int			mouse_press(int key, int x, int y, void *fractal1);
void		thread_mandelbrot(t_fractal *fractal);
int			exit_fractal(void *fractal);
#endif
