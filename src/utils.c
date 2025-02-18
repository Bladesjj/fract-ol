/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:58:43 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/18 16:21:11 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_atod(const char *str, double *result)
{
	double	sign;
	double	fraction;

	sign = 1.0;
	*result = 0.0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		fraction = 0.1;
		while (*str >= '0' && *str <= '9')
		{
			*result += (*str - '0') * fraction;
			fraction *= 0.1;
			str++;
		}
	}
	return (*result *= sign, *str == '\0');
}

void	init_data(t_data *data)
{
	data->mlx = NULL;
	data->win = NULL;
	data->img = NULL;
	data->addr = NULL;
	data->type = MANDELBROT;
	data->max_iter = 100;
	data->zoom = 1.0;
	data->ox = 0.0;
	data->oy = 0.0;
	data->jr = -0.4;
	data->ji = 0.6;
	data->clr_shift = 0;
}
