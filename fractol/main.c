/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:52:02 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/07 04:02:00 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			is_on(char c, char n)
{
	return ((c & (1 << n)) ? 1 : 0);
}

void		usage(void)
{
	ft_putendl("Usage : ./fractol Name_from_list");
	ft_putendl("List:");
	ft_putendl("\t Mandelbrot");
	ft_putendl("\t Julia");
	ft_putendl("\t later");
}

char		wich_fractal(char *a, char *argv)
{
	if (ft_strequ(argv, "Mandelbrot"))
		return (*a | 1);
	if (ft_strequ(argv, "Julia"))
		return (*a | (1 << 1));
	if (ft_strequ(argv, "later"))
		return (*a | (1 << 2));
	return (0);
}

int			main(int ac, char *argv[])
{
	t_fractal	*fractal;
	t_env		env;

	if (ac == 2)
	{
		if ((fractal = (t_fractal*)malloc(sizeof(t_fractal))) == NULL)
			exit(0);
		fractal->type = 0;
		fractal->type = wich_fractal((&fractal->type), argv[1]);
		if (fractal->type != 0)
		{
			ft_setup(&env, fractal);
		/*	if (JULIA)
				draw_julia(&env, fractal);*/
			if (MANDELBROT)
				{
					set_mandelbrot(fractal);
					thread_mandelbrot(fractal);
				}
			mlx_hook(env.win->win_ptr, 2, 0, deal_key, (void*)fractal);
			mlx_hook(env.win->win_ptr, 4, 0, mouse_press, (void*)fractal);
			mlx_hook(env.win->win_ptr, 17, 1L << 17 , exit_fractal, 
			(void*)fractal);
			mlx_loop(env.con_ptr);
		}
		else
			usage();
	}
	else
		usage();
	return (0);
}
