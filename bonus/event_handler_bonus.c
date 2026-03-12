/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 17:58:16 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 14:56:31 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

static void	destroy_window(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->img);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
	exit(1);
}

int	handle_keyinput_bonus(int keysym, t_fractol *fractol)
{
	printf("\rThe %d key has been pressed", keysym);
	fractol->current_x = 0;
	if (keysym == ESCAPE || keysym == 0)
		destroy_window(fractol);
	if (keysym == UP)
		move_up(fractol);
	if (keysym == DOWN)
		move_down(fractol);
	if (keysym == LEFT)
		move_left(fractol);
	if (keysym == RIGHT)
		move_right(fractol);
	return (0);
}

int	close_handler_bonus(t_fractol *fractol)
{
	printf("\rThe key (CROSS) has been pressed");
	destroy_window(fractol);
	return (1);
}

void	zoom_koch(int mouse, int x, int y, t_fractol *f)
{
	double	zoom_factor;
	double	mx_ratio;
	double	my_ratio;

	if (f->fract_name != KOCH)
		return ;
	if (mouse == 4)
		zoom_factor = 1.2;
	else if (mouse == 5)
		zoom_factor = 0.8;
	else
		zoom_factor = 1.0;
	if (zoom_factor == 1.0)
		return ;
	mx_ratio = (x - WIDTH / 2.0);
	my_ratio = (y - HEIGHT / 2.0);
	f->zoom_x *= zoom_factor;
	f->offset_x -= mx_ratio * (zoom_factor - 1);
	f->offset_y -= my_ratio * (zoom_factor - 1);
}

int	mouse_hook_bonus(int mouse, int x, int y, t_fractol *fractol)
{
	(void)x;
	(void)y;
	if (fractol->fract_name == KOCH)
	{
		zoom_koch(mouse, x, y, fractol);
		return (0);
	}
	fractol->current_x = 0;
	if (mouse == 4)
		zoom_in_bonus(fractol, x, y);
	else if (mouse == 5)
		zoom_out_bonus(fractol, x, y);
	return (0);
}
