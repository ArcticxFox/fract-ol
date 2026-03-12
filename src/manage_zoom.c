/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_zoom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:34:13 by ejones            #+#    #+#             */
/*   Updated: 2026/03/06 17:40:59 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

void	zoom_in(t_fractol *f)
{
	double	zoom;
	double	center_x;
	double	center_y;
	double	width;
	double	height;

	zoom = 0.9;
	f->current_x = 0;
	center_x = (f->x1 + f->x2) / 2;
	center_y = (f->y1 + f->y2) / 2;
	width = (f->x2 - f->x1) * zoom;
	height = (f->y2 - f->y1) * zoom;
	f->x1 = center_x - width / 2;
	f->x2 = center_x + width / 2;
	f->y1 = center_y - height / 2;
	f->y2 = center_y + height / 2;
	if (f->max_iterations < 3000)
		f->max_iterations *= 1.05;
}

void	zoom_out(t_fractol *f)
{
	double	zoom;
	double	center_x;
	double	center_y;
	double	width;
	double	height;

	zoom = 1.1;
	center_x = (f->x1 + f->x2) / 2;
	center_y = (f->y1 + f->y2) / 2;
	width = (f->x2 - f->x1) * zoom;
	height = (f->y2 - f->y1) * zoom;
	f->x1 = center_x - width / 2;
	f->x2 = center_x + width / 2;
	f->y1 = center_y - height / 2;
	f->y2 = center_y + height / 2;
	if (f->max_iterations > 100)
		f->max_iterations *= 0.95;
}
