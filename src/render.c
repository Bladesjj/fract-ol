/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:11:54 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/19 18:42:09 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	render(t_data *d)
{
	t_complex	c;
	int			x;
	int			y;
	int			i;
	int			color;

	y = 0;
	while (++y < HEIGHT)
	{
		x = 0;
		while (++x < WIDTH)
		{
			c.real = (x - WIDTH / 2.0) * (4.0 / (d->zoom * WIDTH)) + d->ox;
			c.imag = (y - HEIGHT / 2.0) * (4.0 / (d->zoom * HEIGHT)) + d->oy;
			if (d->type == MANDELBROT)
				i = mandelbrot(c, d->max_iter);
			else if (d->type == JULIA)
				i = julia(c, (t_complex){d->jr, d->ji}, d->max_iter);
			else
				i = burning_ship(c, d->max_iter);
			color = get_color(i, d->max_iter, d->clr_shift);
			my_mlx_pixel_put(d, x, y, color);
		}
	}
	return (mlx_put_image_to_window(d->mlx, d->win, d->img, 0, 0), 0);
}
