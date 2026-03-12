/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snowflake_koch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 13:18:03 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:03:00 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

static void	my_mlx_pixel_(t_fractol *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	draw_line(t_fractol *f, t_point a, t_point b, int i)
{
	double	dx;
	double	dy;
	double	steps;
	double	x;
	double	y;

	dx = b.x - a.x;
	dy = b.y - a.y;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	dx /= steps;
	dy /= steps;
	x = a.x;
	y = a.y;
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_(f, (int)x, (int)y, CYAN);
		x += dx;
		y += dy;
		i++;
	}
}

static void	koch(t_fractol *f, t_point a, t_point b, int depth)
{
	t_point	p;
	t_point	q;
	t_point	r;
	double	angle;

	if (depth == 0)
	{
		draw_line(f, a, b, 0);
		return ;
	}
	p.x = a.x + (b.x - a.x) / 3;
	p.y = a.y + (b.y - a.y) / 3;
	q.x = a.x + 2 * (b.x - a.x) / 3;
	q.y = a.y + 2 * (b.y - a.y) / 3;
	angle = M_PI / 3;
	r.x = p.x + cos(angle) * (q.x - p.x) - sin(angle) * (q.y - p.y);
	r.y = p.y + sin(angle) * (q.x - p.x) + cos(angle) * (q.y - p.y);
	koch(f, a, p, depth - 1);
	koch(f, p, r, depth - 1);
	koch(f, r, q, depth - 1);
	koch(f, q, b, depth - 1);
}

static void	draw_koch_snowflake(t_fractol *f, int depth)
{
	t_point	a;
	t_point	b;
	t_point	c;
	double	size;

	size = 400 * f->zoom_x;
	a.x = WIDTH / 2 - size / 2 + f->offset_x;
	a.y = HEIGHT * 0.65 + f->offset_y;
	b.x = WIDTH / 2 + size / 2 + f->offset_x;
	b.y = HEIGHT * 0.65 + f->offset_y;
	c.x = WIDTH / 2 + f->offset_x;
	c.y = HEIGHT * 0.65 - size * 0.75 + f->offset_y;
	koch(f, a, b, depth);
	koch(f, b, c, depth);
	koch(f, c, a, depth);
}

int	render_koch_snowflake(t_fractol *f)
{
	ft_bzero(f->addr, WIDTH * HEIGHT * (f->bpp / 8));
	draw_koch_snowflake(f, 5);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	return (0);
}
