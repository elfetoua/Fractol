/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:48:06 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/08 23:53:32 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

t_win	*new_win(void *con_ptr, char *title, t_i2 size)
{
	t_win	*win;

	if ((win = (t_win*)malloc(sizeof(t_win))) == NULL)
		exit(1);
	win->con_ptr = con_ptr;
	win->win_ptr = mlx_new_window(con_ptr, size.x + 410, size.y, title);
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
		size = (t_i2){WIDTH_JUL, HEIGHT_JUL};
	else
		size = (t_i2){WIDTH_MA, HEIGHT_MA};
	return (size);
}

void	menu(void *con_ptr, void *win_ptr, t_i2 size, t_fractal *fractal)
{
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 50, 100,
			YELLOW, "         --MENU--");
	if (JULIA)
		mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 50, 220,
				WHITE, "-> Space: freez");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 250 + 10,
			ORANGE, "-> G: Reset fractal");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 280 + 10,
			ORANGE, "-> < OR > for more details>");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 310 + 10,
			ORANGE, "-> C: change color Or click");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 340 + 10,
			AQUA, "-> Keyboard arrows for movements");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 370 + 10,
			AQUA, "-> + OR - for zoom");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 400 + 10,
			AQUA, "-> Scroll with mouse for smooth zoom");
	mlx_string_put((void *)con_ptr, (void *)win_ptr, size.x + 30, 450 + 10,
			RED, "-> ESC to EXIT");
}

void	ft_setup(t_fractal *fractal)
{
	t_i2		win_size;
	char		*title;

	win_size = determine_win_size(fractal);
	fractal->env = (t_env*)malloc(sizeof(t_env));
	fractal->env->con_ptr = mlx_init();
	title = NULL;
	if (fractal->env->con_ptr == NULL)
		exit(1);
	if (JULIA)
		title = "Julia";
	if (MANDELBROT)
		title = "Mandelbrot";
	if (TRICORN)
		title = "Tricorn";
	else
		title = "BONUS";
	fractal->env->win = (t_win*)malloc(sizeof(t_win));
	fractal->env->win = new_win(fractal->env->con_ptr, title, win_size);
	fractal->env->img = new_image(fractal->env);
	fractal->env->win->size = win_size;
	if (fractal->env->win->win_ptr == NULL)
		exit(1);
}
