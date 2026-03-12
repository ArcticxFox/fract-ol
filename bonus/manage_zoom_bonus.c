/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_zoom_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:34:13 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 14:59:31 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	zoom_in_bonus(t_fractol *f, int x, int y)
{
	double	zoom;
	double	mouse_r;
	double	mouse_i;
	double	width;
	double	height;

	zoom = 0.95;
	mouse_r = f->x1 + (double)x / WIDTH * (f->x2 - f->x1);
	mouse_i = f->y1 + (double)y / HEIGHT * (f->y2 - f->y1);
	width = (f->x2 - f->x1) * zoom;
	height = (f->y2 - f->y1) * zoom;
	f->x1 = mouse_r - (mouse_r - f->x1) * zoom;
	f->x2 = mouse_r + (f->x2 - mouse_r) * zoom;
	f->y1 = mouse_i - (mouse_i - f->y1) * zoom;
	f->y2 = mouse_i + (f->y2 - mouse_i) * zoom;
	if (f->max_iterations < 3500)
		f->max_iterations *= 1.05;
	f->i += 1;
}

void	zoom_out_bonus(t_fractol *f, int x, int y)
{
	double	zoom;
	double	mouse_r;
	double	mouse_i;
	double	width;
	double	height;

	zoom = 1.05;
	mouse_r = f->x1 + (double)x / WIDTH * (f->x2 - f->x1);
	mouse_i = f->y1 + (double)y / HEIGHT * (f->y2 - f->y1);
	width = (f->x2 - f->x1) * zoom;
	height = (f->y2 - f->y1) * zoom;
	f->x1 = mouse_r - (mouse_r - f->x1) * zoom;
	f->x2 = mouse_r + (f->x2 - mouse_r) * zoom;
	f->y1 = mouse_i - (mouse_i - f->y1) * zoom;
	f->y2 = mouse_i + (f->y2 - mouse_i) * zoom;
	if (f->max_iterations > 100 && f->i < 30)
		f->max_iterations *= 0.95;
	f->i -= 1;
}
