/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:38:55 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/18 16:04:51 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 53)
		handle_close(data);
	else if (keycode == 123)
		data->ox -= 0.3 / data->zoom;
	else if (keycode == 124)
		data->ox += 0.3 / data->zoom;
	else if (keycode == 125)
		data->oy += 0.3 / data->zoom;
	else if (keycode == 126)
		data->oy -= 0.3 / data->zoom;
	else if (keycode == 8)
		data->clr_shift = (data->clr_shift + 100) % 256;
	else if (keycode == 24)
		data->max_iter += 10;
	else if (keycode == 27)
		data->max_iter -= 10;
	else if (data->max_iter <= 0)
		data->max_iter = 1;
	else if (keycode == 30)
		data->zoom *= 1.1;
	else if (keycode == 33)
		data->zoom /= 1.1;
	printf("Key pressed: %d\n", keycode);
	render(data);
	return (0);
}

int	handle_mouse(int button, int x, int y, t_data *data)
{
	double	m_re;
	double	m_im;

	m_re = (x - WIDTH / 2.0) * (4.0 / (data->zoom * WIDTH)) + data->ox;
	m_im = (y - HEIGHT / 2.0) * (4.0 / (data->zoom * HEIGHT)) + data->oy;
	if (button == 4)
		data->zoom *= 1.1;
	else if (button == 5)
		data->zoom /= 1.1;
	data->ox = m_re - (x - WIDTH / 2.0) * (4.0 / (data->zoom * WIDTH));
	data->oy = m_im - (y - HEIGHT / 2.0) * (4.0 / (data->zoom * HEIGHT));
	render(data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
