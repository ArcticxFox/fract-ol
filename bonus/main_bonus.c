/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 19:25:56 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:17:41 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int i)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	if (i == data->max_iterations)
		*(unsigned long int *)dst = data->color;
	else
		*(unsigned long int *)dst = i * (data->color / data->max_iterations);
}

int	render_fractol_bonus(t_fractol *f)
{
	if (f->fract_name == mandelbrot)
		render_frame_mandelbrot_bonus(f);
	if (f->fract_name == julia)
		render_frame_julia_bonus(f);
	if (f->fract_name == KOCH)
		render_koch_snowflake(f);
	return (1);
}

int	main(int ac, char **av)
{
	t_fractol	fractol;

	ft_parsing_bonus(ac, av, &fractol);
	mlx_put_image_to_window(fractol.mlx, fractol.win, fractol.img, 0, 0);
	mlx_key_hook(fractol.win, handle_keyinput_bonus, &fractol);
	mlx_hook(fractol.win, 4, 1L << 2, mouse_hook_bonus, &fractol);
	mlx_hook(fractol.win, 17, 0, close_handler_bonus, &fractol);
	mlx_loop_hook(fractol.mlx, render_fractol_bonus, &fractol);
	mlx_loop(fractol.mlx);
}
