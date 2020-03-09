/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elfetoua <elfetoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 20:46:35 by elfetoua          #+#    #+#             */
/*   Updated: 2020/03/09 17:53:59 by elfetoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	mlx_functions(t_fractal *fractal)
{
	mlx_hook(fractal->env->win->win_ptr, 4, 0, mouse_press, (void*)fractal);
	mlx_hook(fractal->env->win->win_ptr, 2, 0, deal_key, (void*)fractal);
	mlx_hook(fractal->env->win->win_ptr, 17, 1L << 17, exit_fractal,
			(void*)fractal);
	mlx_loop(fractal->env->con_ptr);
}

void	set_part2(char *ptr, double per, int c)
{
	if (c % 5 == 2)
	{
		ptr[2] = (char)(4.5 * (1 - per) * (per) * (1 - per) * per * 255);
		ptr[1] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[0] = (char)(10.5 * (1 - per) * (1 - per) * per * per * 255);
	}
	if (c % 5 == 3)
	{
		ptr[2] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[1] = (char)(6.5 * (1 - per) * (per) * (1 - per) * per * 255);
		ptr[0] = (char)(9.1 * (1 - per) * per * per * per * 255);
	}
	if (c % 5 == 4)
	{
		ptr[2] = (char)(9.7 * (1 - per) * per * per * per * 255);
		ptr[1] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[0] = (char)(6.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
}

int		set_color(int it, int max_it, int c)
{
	int		color;
	char	*ptr;
	double	per;

	ptr = (char *)&color;
	per = (double)it / max_it;
	if (c % 5 == 0)
	{
		ptr[2] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[1] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[0] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
	if (c % 5 == 1)
	{
		ptr[2] = (char)(15 * (1 - per) * (1 - per) * per * per * 255);
		ptr[1] = (char)(9 * (1 - per) * per * per * per * 255);
		ptr[0] = (char)(8.5 * (1 - per) * (1 - per) * (1 - per) * per * 255);
	}
	set_part2(ptr, per, c);
	ptr[3] = (char)0;
	return (color);
}
