/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:52:07 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/02/15 18:53:48 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	print_usage(void)
{
	write(1, "Usage: ./fractol <fractal>\n", 27);
	write(1, "Available fractals:\n", 20);
	write(1, "mandelbrot\njulia <real> <imag>\nburning_ship\n", 44);
	exit(1);
}

void	parse_args(int argc, char **argv, t_data *data)
{
	if (argc < 2)
		print_usage();
	if (ft_strcmp(argv[1], "mandelbrot") == 0)
		data->type = MANDELBROT;
	else if (ft_strcmp(argv[1], "julia") == 0)
	{
		data->type = JULIA;
		if (argc != 4 || !ft_atod(argv[2], &data->jr)
			|| !ft_atod(argv[3], &data->ji))
			print_usage();
	}
	else if (ft_strcmp(argv[1], "burning_ship") == 0)
		data->type = BURNING_SHIP;
	else
		print_usage();
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	parse_args(argc, argv, &data);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fract'ol");
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	data.addr = mlx_get_data_addr(data.img, &data.bpp, &data.line_l, &data.en);
	mlx_hook(data.win, 2, 1L << 0, handle_key, &data);
	mlx_hook(data.win, 4, 1L << 2, handle_mouse, &data);
	mlx_hook(data.win, 17, 0, handle_close, &data);
	mlx_loop_hook(data.mlx, render, &data);
	mlx_loop(data.mlx);
	return (0);
}
