/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 01:10:54 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 17:39:33 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	set_mandelbrot(t_fractal *fractal)
{
	fractal->max_it = 30;
	fractal->max = (t_d2){2, 2};
	fractal->min = (t_d2){-2, -2};
	fractal->color = 0;
	fractal->x_range = fractal->max.x - fractal->min.x;
	fractal->y_range = fractal->max.y - fractal->min.y;
	fractal->freez = 0;
}

void	mandelbrot_2(t_fractal *frac, t_cmplx *c, t_cmplx *z, double temp)
{
	if (frac->type == 1 || frac->type == 4)
		z->re = z->re * z->re - z->img * z->img + c->re;
	if (frac->type == 8)
		z->re = fabs(z->re * z->re - z->img * z->img + c->re);
	if (frac->type == 1)
		z->img = 2 * temp * z->img + c->img;
	if (frac->type == 4)
		z->img = -2 * temp * z->img + c->img;
	if (frac->type == 8)
		z->img = fabs(2 * temp * z->img + c->img);
}

int		draw_mandelbrot(t_fractal *frac, int i, int j)
{
	double			temp;
	register int	it;
	t_cmplx			z;
	t_cmplx			c;

	c.re = frac->min.x + ((double)i / WIDTH_MA) * (frac->x_range);
	c.img = frac->min.y + ((double)j / HEIGHT_MA) * (frac->y_range);
	z = c;
	it = 0;
	while (it < frac->max_it && (z.re * z.re + z.img * z.img) < 4)
	{
		temp = z.re;
		if (frac->type == 16)
		{
			z.re = z.re * z.re * z.re - 3 * z.re * z.img * z.img + c.re;
			z.img = -z.img * z.img * z.img + 3 * temp * temp * z.img + c.img;
		}
		mandelbrot_2(frac, &c, &z, temp);
		it++;
	}
	return (it);
}

void	set_julia(t_fractal *fractal)
{
	fractal->max_it = 30;
	fractal->max = (t_d2){2, 2};
	fractal->min = (t_d2){-2, -2};
	fractal->color = 0;
	fractal->x_range = fractal->max.x - fractal->min.x;
	fractal->y_range = fractal->max.y - fractal->min.y;
	fractal->c.re = -0.038088;
	fractal->c.img = 0.9754633;
	fractal->freez = 0;
}

int		draw_julia(t_fractal *frac, int i, int j)
{
	double			temp;
	register	int	it;
	t_cmplx			z;

	z.re = frac->min.x + ((double)i / WIDTH_MA) * (frac->x_range);
	z.img = frac->min.y + ((double)j / HEIGHT_MA) * (frac->y_range);
	it = 0;
	while (it < frac->max_it && z.re * z.re + z.img * z.img < 4)
	{
		temp = z.re;
		z.re = z.re * z.re - z.img * z.img + frac->c.re;
		z.img = 2 * temp * z.img + frac->c.img;
		it++;
	}
	return (it);
}
