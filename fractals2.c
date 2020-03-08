/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 23:22:12 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 23:30:20 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		draw_f1(t_fractal *frac, int i, int j)
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
		z.re = z.re * z.re * z.re - 3 * z.re * z.img * z.img + c.re;
		z.img = -z.img * z.img * z.img + 3 * temp * temp * z.img + c.img;
		it++;
	}
	return (it);
}

int		draw_f2(t_fractal *frac, int i, int j)
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
		z.re = z.re * z.re - z.img * z.img + c.re;
		z.img = 2 * temp * z.img + c.img;
		it++;
	}
	return (it);
}