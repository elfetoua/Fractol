/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:54:23 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 21:07:25 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fill_pixel(int *data, int x, int y, int color)
{
	data[x + y * WIDTH_MA] = color;
}

void	*mandelbrot_set1(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = 0;
	while (i < WIDTH_MA / 2)
	{
		j = 0;
		while (j < HEIGHT_MA / 2)
		{
			it = draw_mandelbrot((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel(frac->env->img.data, i, j, 0);
			else
				fill_pixel(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*mandelbrot_set2(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = WIDTH_MA / 2;
	while (i < WIDTH_MA)
	{
		j = 0;
		while (j < HEIGHT_MA / 2)
		{
			it = draw_mandelbrot((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel(frac->env->img.data, i, j, 0);
			else
				fill_pixel(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*mandelbrot_set3(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = 0;
	while (i < WIDTH_MA / 2)
	{
		j = HEIGHT_MA / 2;
		while (j < HEIGHT_MA)
		{
			it = draw_mandelbrot((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel(frac->env->img.data, i, j, 0);
			else
				fill_pixel(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*mandelbrot_set4(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = WIDTH_MA / 2;
	while (i < WIDTH_MA)
	{
		j = HEIGHT_MA / 2;
		while (j < HEIGHT_MA)
		{
			it = draw_mandelbrot((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel(frac->env->img.data, i, j, 0);
			else
				fill_pixel(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}
