/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 16:04:46 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:17:41 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static int	get_pixel(t_fractol *f)
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

void	draw_julia(t_fractol *f)
{
	int	i;

	i = 0;
	if (f->current_x >= WIDTH + 25)
		return ;
	f->var.x = f->current_x + 25;
	f->var.y = 25;
	while (f->var.y < HEIGHT + 25)
	{
		f->var.z_r = f->x1 + f->var.x * (f->x2 - f->x1) / WIDTH;
		f->var.z_i = f->y1 + f->var.y * (f->y2 - f->y1) / HEIGHT;
		i = get_pixel(f);
		my_mlx_pixel_put(f, f->var.x, f->var.y, i);
		f->var.y++;
	}
	f->current_x++;
}

void	init_julia(t_fractol *f, char **av)
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
}

int	render_frame_julia(t_fractol *f)
{
	int	i;

	i = 0;
	while (f->current_x < WIDTH)
	{
		f->current_x = i;
		draw_julia(f);
		i++;
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
