/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:58:24 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 17:48:30 by elfetoua         ###   ########.fr       */
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
# define TRICORN (fractal->type == 4)

# define WIDTH_JUL 1000
# define HEIGHT_JUL 1200
# define WIDTH_MA 900
# define HEIGHT_MA 1000

# define WHITE 0X00FFFFFF
# define PINK 0X00FF00FF
# define ORANGE 0X00FFA500
# define RED 0XFF0000
# define YELLOW 0X00FFFF00
# define AQUA 0X0000FFFF

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

struct		s_img
{
	void	*img_ptr;
	int		*data;
	int		bpp;
	int		sl;
	int		endian;
};

struct		s_win
{
	void	*con_ptr;
	void	*win_ptr;
	t_i2	size;
	char	*title;
};

struct		s_env
{
	void	*con_ptr;
	t_win	*win;
	t_img	img;
};

struct		s_fractal
{
	char	type;
	t_cmplx	z;
	t_cmplx	c;
	int		color;
	int		max_it;
	double	x_range;
	double	y_range;
	t_d2	max;
	t_d2	min;
	t_env	*env;
	int		freez;
};

void		ft_setup(t_fractal *fractal);
void		mandelbrot_set(t_fractal *fractal);
void		set_mandelbrot(t_fractal *fractal);
void		set_julia(t_fractal *fractal);
void		*julia_set1(void *fractal);
void		*julia_set2(void *fractal);
void		*julia_set3(void *fractal);
void		*julia_set4(void *fractal);
int			draw_julia(t_fractal *fractal, int i, int j);
void		thread_julia(t_fractal *fractal);
void		*mandelbrot_set1(void *fractal);
void		*mandelbrot_set2(void *fractal);
void		*mandelbrot_set3(void *fractal);
void		*mandelbrot_set4(void *fractal);
int			draw_mandelbrot(t_fractal *fractal, int i, int j);
int			deal_key(int key, void *fractal);
int			key_press_exit(int key, t_fractal *fractal);
void		zoom_in(t_fractal *fractal);
void		zoom_out(t_fractal *fractal);
void		movement(int key, t_fractal *fractal, double a);
int			mouse_press(int key, int x, int y, void *fractal1);
int			mouse_move(int x, int y, void *fractal1);
void		m_zoom_in(t_fractal *fractal, int mouse_x, int mouse_y);
void		m_zoom_out(t_fractal *fractal, int mouse_x, int mouse_y);
void		thread_mandelbrot(t_fractal *fractal);
int			set_color(int it, int max_it, int c);
int			exit_fractal(void *fractal);
void		mlx_functions(t_fractal *fractal);
void		menu(void *con_ptr, void *win_ptr, t_i2 size, t_fractal *fractal);
void		fill_pixel(int *data, int x, int y, int color);

#endif
