/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_manipulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:49:20 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 17:42:04 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		exit_fractal(void *fractal1)
{
	t_fractal	*fractal;

	fractal = (t_fractal*)fractal1;
	free(fractal->env->win);
	free(fractal->env);
	free(fractal);
	exit(1);
}

int		key_press_exit(int key, t_fractal *fractal)
{
	if (key == 53)
	{
		mlx_destroy_window(fractal->env->con_ptr, fractal->env->win->win_ptr);
		exit_fractal((t_fractal*)fractal);
	}
	return (0);
}

void	zoom_in(t_fractal *fractal)
{
	fractal->x_range = (fractal->max.x - fractal->min.x) / 1.2;
	fractal->y_range = (fractal->max.y - fractal->min.y) / 1.2;
	fractal->max.x /= 1.2;
	fractal->max.y /= 1.2;
	fractal->min.x /= 1.2;
	fractal->min.y /= 1.2;
}

void	zoom_out(t_fractal *fractal)
{
	fractal->x_range = (fractal->max.x - fractal->min.x) * 1.2;
	fractal->y_range = (fractal->max.y - fractal->min.y) * 1.2;
	fractal->max.x *= 1.2;
	fractal->max.y *= 1.2;
	fractal->min.x *= 1.2;
	fractal->min.y *= 1.2;
}

void	movement(int key, t_fractal *fractal, double a)
{
	if (key == 123 || key == 124)
	{
		fractal->max.x += (key == 124) ? -(a) : (a);
		fractal->min.x += (key == 124) ? -(a) : (a);
	}
	if (key == 126 || key == 125)
	{
		fractal->max.y += (key == 125) ? -(a) : (a);
		fractal->min.y += (key == 125) ? -(a) : (a);
	}
}
