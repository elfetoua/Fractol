/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:11:03 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 17:39:59 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		clear_and_draw(t_fractal *fractal)
{
	mlx_clear_window(fractal->env->con_ptr, fractal->env->win->win_ptr);
	if (JULIA)
		thread_julia(fractal);
	else
		thread_mandelbrot(fractal);
	menu(fractal->env->con_ptr, fractal->env->win->win_ptr,
			fractal->env->win->size, fractal);
	return (0);
}

void	reset(t_fractal *fractal)
{
	if (JULIA)
		set_julia(fractal);
	else
		set_mandelbrot(fractal);
}

int		deal_key(int key, void *fractal1)
{
	static	double	a;
	t_fractal		*fractal;

	fractal = (t_fractal*)fractal1;
	key_press_exit(key, fractal);
	if (key == 69)
		zoom_in(fractal);
	if (key == 78)
		zoom_out(fractal);
	if (key == 47)
		fractal->max_it += 10;
	if (key == 43)
		fractal->max_it -= 10;
	if (key == 5)
		reset(fractal);
	if (key == 49)
		fractal->freez += 1;
	if (key == 8)
		fractal->color += 1;
	(a == 0) ? a = fractal->x_range * 3.6 / 100 : a;
	movement(key, fractal, a);
	return (clear_and_draw((t_fractal*)fractal));
}

int		mouse_press(int key, int x, int y, void *fractal1)
{
	t_fractal		*fractal;

	fractal = (t_fractal*)fractal1;
	if (key == 5)
		m_zoom_in(fractal, x, y);
	if (key == 4)
		m_zoom_out(fractal, x, y);
	if (key == 1 || key == 2)
		fractal->color += (key == 1) ? 1 : 4;
	return (clear_and_draw((t_fractal*)fractal));
}

int		mouse_move(int x, int y, void *fractal1)
{
	t_fractal		*fractal;

	fractal = (t_fractal*)fractal1;
	if (JULIA)
	{
		if (fractal->freez % 2 == 0)
		{
			fractal->c.re = fractal->min.x + ((double)x / WIDTH_JUL) *
				(fractal->x_range);
			fractal->c.img = fractal->min.y + ((double)y / HEIGHT_JUL) *
				(fractal->y_range);
			clear_and_draw((t_fractal*)fractal);
		}
	}
	return (0);
}
