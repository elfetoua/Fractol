/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 23:19:55 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 23:20:31 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	thread_f1(t_fractal *fractal)
{
	pthread_t	thread[4];

	if (pthread_create(&thread[0], NULL, f1_set1, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[1], NULL, f1_set2, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[2], NULL, f1_set3, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[3], NULL, f1_set4, (void*)fractal))
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

void	thread_f2(t_fractal *fractal)
{
	pthread_t	thread[4];

	if (pthread_create(&thread[0], NULL, f2_set1, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[1], NULL, f2_set2, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[2], NULL, f2_set3, (void*)fractal))
		perror("pthread_create");
	if (pthread_create(&thread[3], NULL, f2_set4, (void*)fractal))
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