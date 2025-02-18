/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:05:00 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/17 13:18:21 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_complex c, int max_iter)
{
	t_complex	z;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i < max_iter)
	{
		if (z.real * z.real + z.imag * z.imag > 4.0)
			return (i);
		z = (t_complex){
			z.real * z.real - z.imag * z.imag + c.real,
			2 * z.real * z.imag + c.imag
		};
		i++;
	}
	return (i);
}

int	julia(t_complex z, t_complex c, int max)
{
	double	tmp;
	int		i;

	i = 0;
	while (i++ < max)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * z.real * z.imag + c.imag;
		z.real = tmp;
	}
	return (i);
}

int	burning_ship(t_complex c, int max)
{
	t_complex	z;
	double		tmp;
	int			i;

	z.real = 0;
	z.imag = 0;
	i = 0;
	while (i++ < max)
	{
		if ((z.real * z.real + z.imag * z.imag) > 4.0)
			break ;
		tmp = z.real * z.real - z.imag * z.imag + c.real;
		z.imag = 2 * fabs(z.real) * fabs(z.imag) + c.imag;
		z.real = fabs(tmp);
	}
	return (i);
}
