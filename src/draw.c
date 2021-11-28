#include "fractol.h"

void	print_name(t_var *var)
{
	char	*itermax;
	char	*zoom;

	itermax = ft_strjoinf("Iteration : ", ft_itoa(var->iter_max));
	zoom = ft_strjoinf("Zoom : ", ft_ftoa(var->zoom));
	if (var->name == 'm')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Mandelbrot");
	if (var->name == 'j')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Julia");
	if (var->name == 's')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Burning Ship");
	mlx_string_put(var->mlx, var->window, 15, 30, 0x00000000, itermax);
	mlx_string_put(var->mlx, var->window, 15, 45, 0x00000000, zoom);
	free(zoom);
	free(itermax);
}

int	alg(t_var *var, float x, float y)
{
	float	tmp;

	var = set_alg(var, x, y);
	while (((var->z.re) * (var->z.re)) + ((var->z.im) * (var->z.im)) < 4 && (var->iter) < (var->iter_max))
	{
		tmp = (var->z.re);
		(var->z.re) = ((var->z.re) * (var->z.re)) - ((var->z.im) * (var->z.im)) + (var->c.re);
		(var->z.im) = (2 * (var->z.im) * tmp) + var->c.im;
		(var->iter) += 1;
	}
	if (var->iter == var->iter_max)
		return (1);
	return (0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char		*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void	draw(t_var *var)
{
	float	x;
	float	y;
	
	y = -1;
	var->color = color_maker(var);
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			if (alg(var, x, y))
				my_mlx_pixel_put(&(var->img), x, y, 0x00000000);
			else
				my_mlx_pixel_put(&(var->img), x, y, var->color[var->iter]);
		}
	}
    free(var->color);
	mlx_put_image_to_window(var->mlx, var->window, var->img.img, 0, 0);
	print_name(var);
}

int	*color_maker(t_var *var)
{
	int i;

	i = 0;
	var->color = malloc(sizeof(unsigned int) * var->iter_max);
	if(var->color)
	{
		while (i < var->iter_max)
		{

			if (i < var->iter_max)
				var->color[i++] = 0xE653C5;
			if (i < var->iter_max)
				var->color[i++] = 0xF09E6C;
			if (i < var->iter_max)
				var->color[i++] = 0xFAF378;
			if (i < var->iter_max)
				var->color[i++] = 0x71E3A3; 
			if (i < var->iter_max)
				var->color[i++] = 0x708FFA; 
		}
		return(var->color);
	}
	return(NULL);
}
