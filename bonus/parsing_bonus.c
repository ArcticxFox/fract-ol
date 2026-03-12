/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 16:50:07 by ejones            #+#    #+#             */
/*   Updated: 2026/03/09 17:07:41 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fractol_bonus.h"

void	print_format(int type)
{
	if (type == -1)
		ft_printf("mlx failed, try again");
	if (type == 1)
		ft_printf("For julia --> ./fractol <julia> <conts Re> <const Im>\n");
	if (type == 2)
		ft_printf("default precision is 100, put between 50-2000");
	else
	{
		ft_printf("Available fractols : mandelbrot || julia\n");
		ft_printf("For Mandeldelbrot --> ./fractol_bonus ");
		ft_printf("<mandelbrot> <precision>\n");
		ft_printf("For julia --> ./fractol <julia> <conts Re>");
		ft_printf(" <const Im> <precision>\n");
		ft_printf("For Koch --> ./fractol koch\n");
	}
	exit(1);
}

static int	check_parameter_is_float(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+' || ft_isdigit(str[i]) == 1)
		i++;
	else
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '.')
		i++;
	while (ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	check_is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			print_format(2);
		i++;
	}
	return (1);
}

static void	init_struct(int ac, char **av, t_fractol *f)
{
	ft_bzero(f, sizeof(t_fractol));
	if ((ac == 2 || ac == 3) && ft_strncmp(av[1], "mandelbrot", 11) == 0)
		init_mandelbrot_bonus(f);
	else if ((ac == 4 || ac == 5) && ft_strncmp(av[1], "julia", 5) == 0)
		init_julia_bonus(f, av);
	else if (ac == 2 && ft_strncmp(av[1], "koch", 5) == 0)
		init_koch(f);
	else
		print_format(0);
	if ((ac == 3 && f->fract_name == mandelbrot)
		|| (ac == 5 && f->fract_name == julia))
		if (check_is_int(av[ac - 1]))
			f->max_iterations = ft_atoi(av[ac - 1]);
	if (f->max_iterations < 50 || f->max_iterations > 2000)
		print_format(2);
	f->mlx = mlx_init();
	if (!f->mlx)
		print_format(-1);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	f->addr = mlx_get_data_addr(f->img, &f->bpp,
			&f->line_length, &f->endian);
}

void	ft_parsing_bonus(int ac, char **av, t_fractol *fractol)
{
	size_t	i;

	i = 0;
	if (ac > 6 || ac == 1)
		print_format(1);
	while (av[1][i])
	{
		if (ft_isalpha(av[1][i]) == 0)
			print_format(0);
		i++;
	}
	if (ac == 4 || ac == 5)
	{
		if (check_parameter_is_float(&av[2][0]) == 0)
			print_format(1);
		if (check_parameter_is_float(&av[3][0]) == 0)
			print_format(1);
	}
	init_struct(ac, av, fractol);
}
