/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:10:54 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/07 04:21:12 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		set_color(int it, int max_it, int c)
{
	int		color;
	char	*ptr;
	double		per;

	ptr = (char *)&color;
	per = (double)it / max_it;
	if (c % 5 == 0)
	{
		ptr[2] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[1] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[0] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
	if (c % 5 == 1)
	{
		ptr[2] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[1] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[0] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
	if (c % 5 == 2)
	{
		ptr[2] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
		ptr[1] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[0] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
	}
	if (c % 5 == 3)
	{
		ptr[2] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[1] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
		ptr[0] = (char)(9 * (1 - per) * per * per * per * 255);
	}
	if (c % 5 == 4)
	{
		ptr[2] = (char)(9.7 * (1 - per) * per * per * per * 255);
		ptr[1] = (char)(15.3 * (1 - per) * (1 - per) * per * per * 255);
		ptr[0] = (char)(6.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
	ptr[3] = (char)0;
	return (color);
}
void	fill_pixel(int	*data, int x, int y, int color)
{
	data[x + y * WIDTH_MA] = color;
}

void	set_mandelbrot(t_fractal *fractal)
{
	fractal->zoom = 20;
	fractal->max_it = 30;
	fractal->max = (t_d2){2, 2};
	fractal->min = (t_d2){-2, -2};
	fractal->color = 0;
}

int		draw_mandelbrot(t_fractal *frac, int i, int j)
{
	double			temp;
	register int	it;
	t_cmplx			z;
	t_cmplx			c;
	
	frac->x_range = frac->max.x - frac->min.x;
	frac->y_range = frac->max.y - frac->min.y;
	c.re = frac->min.x + ((double)i / WIDTH_MA) * (frac->x_range);
	c.img = frac->min.y + ((double)j / HEIGHT_MA) * (frac->y_range);
	z = c;
	it = 0;
	while (it < frac->max_it && (pow(z.re, 2) + pow(z.img, 2)) < 4)
	{
		temp = z.re;
		z.re = pow(z.re, 2) -  pow(z.img, 2) + c.re;
		z.img = 2 * temp * z.img + c.img;
		it++;
	}
	return (it);
}

void    *mandelbrot_set1(void *fractal)
{
    register int	i;
	register int	j;
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
			fill_pixel(frac->env->img.data, i, j,  set_color(it, frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void    *mandelbrot_set2(void *fractal)
{
    register int	i;
	register int	j;
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
			fill_pixel(frac->env->img.data, i, j,  set_color(it, frac->max_it, frac->color));
			j++;
		}
		i++;
	}
	return (NULL);
}

void    *mandelbrot_set3(void *fractal)
{
    register int	i;
	register int	j;
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
			fill_pixel(frac->env->img.data, i, j,  set_color(it, frac->max_it, frac->color));			
			j++;
		}
		i++;
	}
	return (NULL);
}

void    *mandelbrot_set4(void *fractal)
{
    register int	i;
	register int	j;
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
			fill_pixel(frac->env->img.data, i, j,  set_color(it, frac->max_it, frac->color));		
			j++;
		}
		i++;
	}
	return (NULL);
}