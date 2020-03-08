/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_manipulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:50:07 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 21:12:48 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

double	interpolate(double start, double end, double interpolation)
{
	return (start + ((end - start) * interpolation));
}

void	m_zoom_in(t_fractal *fractal, int x, int y)
{
	double	zoom;
	double	interpolation;
	double	mouse_x;
	double	mouse_y;

	zoom = 2.01;
	interpolation = 1.0 / zoom;
	mouse_x = fractal->min.x + ((double)x / WIDTH_MA) * (fractal->x_range);
	mouse_y = fractal->min.y + ((double)y / HEIGHT_MA) * (fractal->y_range);
	fractal->max.x = interpolate(mouse_x, fractal->max.x, interpolation);
	fractal->max.y = interpolate(mouse_y, fractal->max.y, interpolation);
	fractal->min.x = interpolate(mouse_x, fractal->min.x, interpolation);
	fractal->min.y = interpolate(mouse_y, fractal->min.y, interpolation);
	fractal->x_range = fractal->max.x - fractal->min.x;
	fractal->y_range = fractal->max.y - fractal->min.y;
}

void	m_zoom_out(t_fractal *fractal, int x, int y)
{
	double	zoom;
	double	interpolation;
	double	mouse_x;
	double	mouse_y;

	zoom = 2.01;
	interpolation = 1.0 * zoom;
	mouse_x = fractal->min.x + ((double)x / WIDTH_MA) * (fractal->x_range);
	mouse_y = fractal->min.y + ((double)y / HEIGHT_MA) * (fractal->y_range);
	fractal->max.x = interpolate(mouse_x, fractal->max.x, interpolation);
	fractal->max.y = interpolate(mouse_y, fractal->max.y, interpolation);
	fractal->min.x = interpolate(mouse_x, fractal->min.x, interpolation);
	fractal->min.y = interpolate(mouse_y, fractal->min.y, interpolation);
	fractal->x_range = fractal->max.x - fractal->min.x;
	fractal->y_range = fractal->max.y - fractal->min.y;
}
