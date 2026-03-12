/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 12:55:05 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 15:20:43 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_BONUS_H

# define FRACTOL_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

# define M_PI		3.14159265358979323846

# define WIDTH		900
# define HEIGHT		700
# define X_AXIS		0
# define Y_AXIS		0

# define BLACK		0x000000
# define WHITE		0xFFFFFF
# define RED		0xFF0000
# define GREEN		0x00FF00
# define BLUE		0x0000FF
# define YELLOW		0xFFFF00
# define CYAN		0x00FFFF
# define MAGENTA	0xFF00FF
# define RED		0xFF0000

# define ESCAPE		65307
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

enum e_names
{
	mandelbrot,
	julia,
	KOCH
};

typedef struct s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct s_var
{
	int		x;
	int		y;
	double	c_r;
	double	c_i;
	double	z_r;
	double	z_i;
	double	tmp;
}	t_var;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		current_x;
	int		max_iterations;
	int		fract_name;
	int		i;
	int		color;
	double	zoom_x;
	double	zoom_y;
	double	offset_x;
	double	offset_y;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	t_var	var;
}	t_fractol;

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int i);

void	ft_parsing_bonus(int ac, char **av, t_fractol *fractol);

void	init_mandelbrot_bonus(t_fractol *f);
int		render_frame_mandelbrot_bonus(t_fractol *f);

void	init_julia_bonus(t_fractol *f, char **av);
int		render_frame_julia_bonus(t_fractol *f);

int		render_koch_snowflake(t_fractol *f);
void	init_koch(t_fractol *f);

void	zoom_in_bonus(t_fractol *f, int x, int y);
void	zoom_out_bonus(t_fractol *f, int x, int y);

void	move_up(t_fractol *f);
void	move_down(t_fractol *f);
void	move_left(t_fractol *f);
void	move_right(t_fractol *f);

int		handle_keyinput_bonus(int keysym, t_fractol *fractol);
int		mouse_hook_bonus(int mouse, int x, int y, t_fractol *fractol);
int		close_handler_bonus(t_fractol *fractol);

#endif
