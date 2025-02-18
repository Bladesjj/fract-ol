/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 22:48:16 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/18 16:23:48 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	get_color(int iter, int max_iter, int color_shift)
{
	int	r;

	if (iter == max_iter)
		return (0x000000);
	r = (iter * 100 + color_shift) % 256;
	return ((r << 16));
}
