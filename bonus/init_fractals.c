/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractals.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:11:30 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:17:41 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	init_julia_bonus(t_fractol *f, char **av)
{
	f->x1 = -2.0;
	f->x2 = 2.0;
	f->y1 = -1.5;
	f->y2 = 1.5;
	f->current_x = 0;
	f->var.c_r = ft_atof(av[2]);
	f->var.c_i = ft_atof(av[3]);
	f->max_iterations = 100;
	f->fract_name = julia;
	f->color = GREEN;
}

void	init_mandelbrot_bonus(t_fractol *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->current_x = 0;
	f->max_iterations = 100;
	f->fract_name = mandelbrot;
	f->color = CYAN;
}

void	init_koch(t_fractol *f)
{
	f->fract_name = KOCH;
	f->zoom_x = 1.0;
	f->max_iterations = 100;
}
