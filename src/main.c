/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:25:56 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 16:58:22 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int i)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	if (i == data->max_iterations)
		*(unsigned long int *)dst = GREEN;
	else
		*(unsigned long int *)dst = i * (GREEN / data->max_iterations);
}

int	render_fractol(t_fractol *f)
{
	if (f->fract_name == mandelbrot)
		render_frame_mandelbrot(f);
	if (f->fract_name == julia)
		render_frame_julia(f);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (ac == 1 || ac > 6)
		print_format(0);
	ft_parsing(ac, av, &fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, handle_keyinput, &fractol);
	mlx_hook(fractol.win, 4, 1L << 2, mouse_hook, &fractol);
	mlx_hook(fractol.win, 17, 0, close_handler, &fractol);
	mlx_loop_hook(fractol.mlx, render_fractol, &fractol);
	mlx_loop(fractol.mlx);
}
