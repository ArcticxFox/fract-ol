/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 15:16:10 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 16:56:30 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <sys/time.h>
# include <stdio.h>

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
	julia
};

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
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
	int			current_x;
	int			max_iterations;
	int			fract_name;
	int			i;
	double		zoom_x;
	double		zoom_y;
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	t_var		var;
}	t_fractol;

void	print_format(int type);
void	ft_parsing(int ac, char **av, t_fractol *fractol);

void	init_mandelbrot(t_fractol *f);
int		render_frame_mandelbrot(t_fractol *f);

void	init_julia(t_fractol *f, char **av);
int		render_frame_julia(t_fractol *f);

void	zoom_in(t_fractol *f);
void	zoom_out(t_fractol *f);

int		handle_keyinput(int keysym, t_fractol *fractol);
int		mouse_hook(int mouse, int x, int y, t_fractol *fractol);
int		close_handler(t_fractol *fractol);

void	my_mlx_pixel_put(t_fractol *data, int x, int y, int i);

#endif
