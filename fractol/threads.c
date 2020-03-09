/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 19:45:43 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 15:56:21 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

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

void	thread_julia(t_fractal *fractal)
{
	pthread_t	thread[4];

	if (pthread_create(&thread[0], NULL, julia_set1, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[1], NULL, julia_set2, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[2], NULL, julia_set3, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[3], NULL, julia_set4, (void*)fractal))
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
