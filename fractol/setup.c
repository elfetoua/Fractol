/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:48:06 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/07 03:32:50 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_win	*new_win(void *con_ptr, char *title, t_i2 size)
{
	t_win	*win;

	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		exit(1);
	win->con_ptr = con_ptr;
	win->win_ptr = mlx_new_window(con_ptr, size.x, size.y, title);
	win->size = size;
	win->title = title;
	return (win);
}

t_img	new_image(t_env *env)
{
	t_img	new;

	new.img_ptr = mlx_new_image(env->con_ptr, env->win->size.x,
	 env->win->size.y);
	new.data = (int*)mlx_get_data_addr(new.img_ptr, &new.bpp,
	 &new.sl, &new.endian);
	return (new);	
}

t_i2	determine_win_size(t_fractal *fractal)
{
	t_i2	size;
	
	if (JULIA)
		size = (t_i2){WIDTH_JULIA, HEIGHT_JULIA};
	if (MANDELBROT)
		size = (t_i2){WIDTH_MA, HEIGHT_MA};
	return (size);
}

void	ft_setup(t_env *env, t_fractal *fractal)
{
	t_i2		win_size;
	char		*title;

	win_size = determine_win_size(fractal);
	env->con_ptr = mlx_init();
	title = NULL;
	if (env->con_ptr == NULL)
	{
		ft_putendl("grahic server error");
		exit(1);
	}
	//env->win = new_win(env->con_ptr, "Mandelbrot", win_size);

	/*if (JULIA)
		title = "Mandelbrot";*/
	if (MANDELBROT)
		title = "Mandelbrot";
	env->win = new_win(env->con_ptr, title, win_size);
	env->img = new_image(env);
	if (env->win->win_ptr == NULL)
	{
		ft_putendl("window error");
		exit(1);
	}
	fractal->env = env;
}
