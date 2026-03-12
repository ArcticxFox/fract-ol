/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 15:48:10 by ejones            #+#    #+#             */
/*   Updated: 2026/03/04 15:48:37 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/../header/libft.h"

static int	get_sign_integer(const char *str, int *sign, int *i)
{
	float	result;

	result = 0;
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
			*sign = -1;
		*i = *i + 1;
	}
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10.0f + (str[*i] - '0');
		*i = *i + 1;
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		i;
	int		sign;
	float	result;
	float	decimal;

	i = 0;
	sign = 1;
	result = 0.0f;
	decimal = 0.1f;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	result = get_sign_integer(&str[i], &sign, &i);
	if (str[i] == '.')
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			result += (str[i] - '0') * decimal;
			decimal *= 0.1f;
			i++;
		}
	}
	return (result * sign);
}
