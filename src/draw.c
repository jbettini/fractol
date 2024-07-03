#include "fractol.h"

void	print_name(t_var *var)
{
	char	*itermax;
	char	*zoom;

	itermax = ft_strjoinf("Iteration : ", ft_ulltoa(var->iter_max));
	zoom = ft_strjoinf("Zoom : ", ft_ftoa(var->zoom));
	if (var->name == 'm')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00FFFFFF, "Mandelbrot");
	if (var->name == 'j')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00FFFFFF, "Julia");
	if (var->name == 's')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00FFFFFF, "Burning Ship");
	mlx_string_put(var->mlx, var->window, 15, 30, 0x00FFFFFF, itermax);
	mlx_string_put(var->mlx, var->window, 15, 45, 0x00FFFFFF, zoom);
	free(zoom);
	free(itermax);
}

int	alg(t_var *var, float x, float y)
{
	float	tmp;

	var = set_alg(var, x, y);
	if (var->name != 's')
		while (((var->z.re) * (var->z.re)) + ((var->z.im) * (var->z.im)) < 4 && (var->iter) < (var->iter_max))
		{
			tmp = (var->z.re);
			(var->z.re) = ((var->z.re) * (var->z.re)) - ((var->z.im) * (var->z.im)) + (var->c.re);
			(var->z.im) = (2 * (var->z.im) * tmp) + var->c.im;
			(var->iter)++;
		}
	else
		while (((var->c.re) * (var->c.re)) + ((var->c.im) * (var->c.im)) < 4 && (var->iter) < (var->iter_max))
		{
			tmp = (var->c.re) * (var->c.re) - (var->c.im) * (var->c.im) + var->z.re;
			(var->c.re) = fabsl(2 * (var->c.re) * (var->c.im)) + var->z.im;
			(var->c.im) = tmp;
			(var->iter)++;
		}
	if (var->iter == 0)
		var->iter++;
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
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			if (alg(var, x, y))
				my_mlx_pixel_put(&(var->img), x, y, 0x00000000);
			else
				my_mlx_pixel_put(&(var->img), x, y, (var->color * var->iter) / var->set);
		}
	}
	mlx_put_image_to_window(var->mlx, var->window, var->img.img, 0, 0);
	print_name(var);
}

int julia_move(t_var *var)
{
	if (var->name == 'j' && var->move == 1)
	{
		mlx_mouse_get_pos(var->window, &(var->mouse.tmpx), &(var->mouse.tmpy));
		if (var->mouse.tmpx >= 0 && var->mouse.tmpx <= W && var->mouse.tmpy >= 0 && var->mouse.tmpy <= H)
		{
			var->c.re = (float)((conv_res(var->mouse.tmpx, 2) / W) - 1);
			var->c.im = (float)((conv_res(var->mouse.tmpy, 2) / H) - 1);
		}
	}
	return (0);
}
