/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:58:16 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:17:41 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol.h"

static void	destroy_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(1);
}

int	handle_keyinput(int keysym, t_fractol *fractol)
{
	printf("\rThe %d key has been pressed", keysym);
	fractol->current_x = 0;
	if (keysym == ESCAPE || keysym == 0)
		destroy_window(fractol);
	return (0);
}

int	close_handler(t_fractol *fractol)
{
	printf("\rThe key (CROSS) has been pressed");
	destroy_window(fractol);
	return (1);
}

int	mouse_hook(int mouse, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	fractol->current_x = 0;
	if (mouse == 4)
		zoom_in(fractol);
	if (mouse == 5)
		zoom_out(fractol);
	if (fractol->fract_name == mandelbrot)
		render_frame_mandelbrot(fractol);
	if (fractol->fract_name == julia)
		render_frame_julia(fractol);
	return (0);
}
