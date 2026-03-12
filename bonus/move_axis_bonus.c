/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_axis_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:31:11 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 12:56:31 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	move_up(t_fractol *f)
{
	double	h;

	h = (f->y2 - f->y1) * 0.05;
	f->y1 += h;
	f->y2 += h;
}

void	move_down(t_fractol *f)
{
	double	h;

	h = (f->y2 - f->y1) * 0.05;
	f->y1 -= h;
	f->y2 -= h;
}

void	move_left(t_fractol *f)
{
	double	h;

	h = (f->x2 - f->x1) * 0.05;
	f->x1 -= h;
	f->x2 -= h;
}

void	move_right(t_fractol *f)
{
	double	h;

	h = (f->x2 - f->x1) * 0.05;
	f->x1 += h;
	f->x2 += h;
}
