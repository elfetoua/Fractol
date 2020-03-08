/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 23:32:38 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 20:52:35 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	fill_pixel1(int *data, int x, int y, int color)
{
	data[x + y * WIDTH_JUL] = color;
}

void	*julia_set1(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = 0;
	while (i < WIDTH_JUL / 2)
	{
		j = 0;
		while (j < HEIGHT_JUL / 2)
		{
			it = draw_julia((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel1(frac->env->img.data, i, j, 0);
			else
				fill_pixel1(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*julia_set2(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = WIDTH_JUL / 2;
	while (i < WIDTH_JUL)
	{
		j = 0;
		while (j < HEIGHT_JUL / 2)
		{
			it = draw_julia((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel1(frac->env->img.data, i, j, 0);
			else
				fill_pixel1(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*julia_set3(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = 0;
	while (i < WIDTH_JUL / 2)
	{
		j = HEIGHT_JUL / 2;
		while (j < HEIGHT_JUL)
		{
			it = draw_julia((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel1(frac->env->img.data, i, j, 0);
			else
				fill_pixel1(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void	*julia_set4(void *fractal)
{
	register	int	i;
	register	int	j;
	int				it;
	t_fractal		*frac;

	frac = (t_fractal*)fractal;
	i = WIDTH_JUL / 2;
	while (i < WIDTH_JUL)
	{
		j = HEIGHT_JUL / 2;
		while (j < HEIGHT_JUL)
		{
			it = draw_julia((t_fractal*)fractal, i, j);
			if (it == frac->max_it)
				fill_pixel1(frac->env->img.data, i, j, 0);
			else
				fill_pixel1(frac->env->img.data, i, j, set_color(it + 5,
				frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}
