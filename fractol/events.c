/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:11:03 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/07 04:38:47 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int	exit_fractal(void *fractal1)
{
	t_fractal	*fractal;
	
	fractal = (t_fractal*)fractal1;
	free(fractal->env->win);
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

void	thread_mandelbrot(t_fractal *fractal)
{
	pthread_t	thread[4];
	
	if (pthread_create(&thread[0], NULL, mandelbrot_set1, (void*)fractal))
		perror("pthread_create");

	if (pthread_create(&thread[1], NULL, mandelbrot_set2, (void*)fractal))
		perror("pthread_create");

	if (pthread_create(&thread[2], NULL, mandelbrot_set3, (void*)fractal))
		perror("pthread_create");

	if (pthread_create(&thread[3], NULL, mandelbrot_set4, (void*)fractal))
		perror("pthread_create");

    if (pthread_join(thread[0], NULL))
		perror("pthread_join");
	if (pthread_join(thread[1], NULL))
		perror("pthread_join");
	if (pthread_join(thread[2], NULL))
		perror("pthread_join");
	if (pthread_join(thread[3], NULL))
		perror("pthread_join");
	mlx_put_image_to_window(fractal->env->con_ptr, fractal->env->win->win_ptr, 
	fractal->env->img.img_ptr, 0, 0);
}

int		clear_and_draw(t_fractal *fractal)
{
	mlx_clear_window(fractal->env->con_ptr, fractal->env->win->win_ptr);
    if (MANDELBROT)
        thread_mandelbrot(fractal);
	return (0);
}

void	zoom_in(t_fractal *fractal)
{
    fractal->max.x /= 1.2;
    fractal->max.y /= 1.2;
    fractal->min.x /= 1.2;
    fractal->min.y /= 1.2;
}

void	zoom_out(t_fractal *fractal)
{
    fractal->max.x *= 1.2;
    fractal->max.y *= 1.2;
    fractal->min.x *= 1.2;
    fractal->min.y *= 1.2;
}

void	movement(int key, t_fractal *fractal, int a)
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

int		deal_key(int key, void *fractal1)
{
	static	int		a;
    t_fractal       *fractal;

    fractal = (t_fractal*)fractal1;
	key_press_exit(key, fractal);
	if (key == 69)
		zoom_in(fractal);
	if (key == 78)
		zoom_out(fractal);
	if (key == 8)
		fractal->color += 1;
     (a == 0) ? a = 1 : a;
	 movement(key, fractal, a);
	return (clear_and_draw((t_fractal*)fractal));
}

void	m_zoom_in(t_fractal *fractal, int x, int y)
{
	
    fractal->max.x /= 1.2;
    fractal->max.y /= 1.2;
    fractal->min.x /= 1.2;
    fractal->min.y /= 1.2;
}

void	m_zoom_out(t_fractal *fractal, int x, int y)
{
    fractal->max.x *= 1.2;
    fractal->max.y *= 1.2;
    fractal->min.x *= 1.2;
    fractal->min.y *= 1.2;
	
}

int		mouse_press(int key, int x, int y, void *fractal1)
{
    t_fractal       *fractal;

    fractal = (t_fractal*)fractal1;
	if (key == 4)
		m_zoom_in(fractal,x ,y);
	if (key == 5)
		m_zoom_out(fractal, x, y);
	if (key == 1 || key == 2)
		fractal->color += 1;
	
	return (clear_and_draw((t_fractal*)fractal));
}


