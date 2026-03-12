/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:26:48 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:17:31 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

int	get_pixel(t_fractol *f)
{
	int	i;

	i = 0;
	while (f->var.z_r * f->var.z_r + f->var.z_i * f->var.z_i < 4
		&& i < f->max_iterations)
	{
		f->var.tmp = f->var.z_r;
		f->var.z_r = f->var.z_r * f->var.z_r - f->var.z_i * f->var.z_i
			+ f->var.c_r;
		f->var.z_i = 2 * f->var.z_i * f->var.tmp + f->var.c_i;
		i++;
	}
	return (i);
}

void	draw_mandelbrot(t_fractol *f)
{
	int	i;

	i = 0;
	if (f->current_x >= WIDTH)
		return ;
	f->var.x = f->current_x;
	f->var.y = 0;
	while (f->var.y < HEIGHT)
	{
		f->var.c_r = f->x1 + f->var.x * (f->x2 - f->x1) / WIDTH;
		f->var.c_i = f->y1 + f->var.y * (f->y2 - f->y1) / HEIGHT;
		f->var.z_r = 0;
		f->var.z_i = 0;
		i = get_pixel(f);
		my_mlx_pixel_put(f, f->var.x, f->var.y, i);
		f->var.y++;
	}
	f->current_x++;
}

void	init_mandelbrot(t_fractol *f)
{
	f->x1 = -2.1;
	f->x2 = 0.6;
	f->y1 = -1.2;
	f->y2 = 1.2;
	f->current_x = 0;
	f->max_iterations = 100;
	f->fract_name = mandelbrot;
}

int	render_frame_mandelbrot(t_fractol *f)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		f->current_x = i;
		draw_mandelbrot(f);
		i++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
