#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>

# define WIDTH 800
# define HEIGHT 800
# define MAX_ITER 100

typedef struct s_complex {
	double	real;
	double	imag;
}	t_complex;

typedef enum e_fractal {
	MANDELBROT,
	JULIA,
	BURNING_SHIP
}	t_fractal;

typedef struct s_data {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			line_l;
	int			en;
	t_fractal	type;
	double		zoom;
	double		ox;
	double		oy;
	double		jr;
	double		ji;
	int			clr_shift;
	int			max_iter;
}	t_data;

void	init_data(t_data *data);
int		render(t_data *data);
int		handle_key(int keycode, t_data *data);
int		handle_mouse(int button, int x, int y, t_data *data);
int		handle_close(t_data *data);
int		mandelbrot(t_complex c, int max_iter);
int		julia(t_complex z, t_complex c, int max_iter);
int		burning_ship(t_complex c, int max_iter);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		get_color(int iter, int max_iter, int color_shift);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_atod(const char *str, double *result);

#endif