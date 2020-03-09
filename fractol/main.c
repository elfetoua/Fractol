/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 21:52:02 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 15:48:34 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int			is_on(char c, char n)
{
	return ((c & (1 << n)) ? 1 : 0);
}

void		fractals(t_fractal *fractal)
{
	if (JULIA)
	{
		set_julia(fractal);
		thread_julia(fractal);
		mlx_hook(fractal->env->win->win_ptr, 6, 0, mouse_move, (void*)fractal);
	}
	else
	{
		set_mandelbrot(fractal);
		thread_mandelbrot(fractal);
	}
	menu(fractal->env->con_ptr, fractal->env->win->win_ptr,
	fractal->env->win->size, fractal);
}

void		usage(void)
{
	ft_putendl("Usage : ./fractol Name_from_list");
	ft_putendl("List:");
	ft_putendl("\t Mandelbrot");
	ft_putendl("\t Julia");
	ft_putendl("\t Tricorn");
	ft_putendl("\t Burningship");
	ft_putendl("\t F1");
}

char		wich_fractal(char *a, char *argv)
{
	if (ft_strequ(argv, "Mandelbrot"))
		return (*a | 1);
	if (ft_strequ(argv, "Julia"))
		return (*a | (1 << 1));
	if (ft_strequ(argv, "Tricorn"))
		return (*a | (1 << 2));
	if (ft_strequ(argv, "Burningship"))
		return (*a | (1 << 3));
	if (ft_strequ(argv, "F1"))
		return (*a | (1 << 4));
	return (0);
}

int			main(int ac, char *argv[])
{
	t_fractal	*fractal;

	if (ac == 2)
	{
		if ((fractal = (t_fractal*)malloc(sizeof(t_fractal))) == NULL)
			exit(0);
		fractal->type = 0;
		fractal->type = wich_fractal((&fractal->type), argv[1]);
		if (fractal->type != 0)
		{
			ft_setup(fractal);
			fractals(fractal);
			mlx_functions(fractal);
		}
		else
			usage();
	}
	else
		usage();
	return (0);
}
