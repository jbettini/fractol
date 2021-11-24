#include "fractol.h"

int	key_hook(int key, t_var *var)
{
	if (key == 53)
	{
		mlx_destroy_window(var->mlx, var->window);
		free(var);
		exit(0);
	}
	if (key == 13)
	{
		var->zoom += 20;
	//	var->iter_max += 20;
	//	var->xmax += 100;
	//	printf("itermax = %d \n", var->iter_max);
	}
//	printf("key = %d\n",key);
	return (0);
}
void	*mandelbrot(int *color, t_var *var)
{
	float	x;
	float	y;
	
	y = -1;
	while (++y < var->ymax)
	{
		x = -1;
		while (++x < var->xmax)
		{
			if (mandel_alg(var, x, y))
				mlx_pixel_put(var->mlx, var->window, x, y, 0x00000000);
			else
				mlx_pixel_put(var->mlx, var->window, x, y, color[var->iter]);
		}
	}
	mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Ensemble de Mandelbrot");
	//mlx_string_put(var->mlx, var->window, 10, 10, 0x00000000, ft_itoa(var->iter));
}

int	mandel_alg(t_var *var, float x, float y)
{
	float	tmp;

	var = set_alg(var, x, y);
	while (var->z.re * var->z.re - var->z.im * var->z.im < 4 && var->iter < var->iter_max)
	{
		tmp = var->z.re;
		var->z.re = var->z.re * var->z.re - var->z.im * var->z.im + var->c.re;
		var->z.im = 2 * var->z.im * tmp + var->c.im;
		var->iter += 1;
	}
	if (var->iter == var->iter_max)
		return (1);
	else
		return (0);
}

t_var	*set_alg(t_var *var, float x, float y)
{
	var->iter = 0;
	var->z.re = 0;
	var->z.im = 0;
	var->c.re = x / var->zoom + var->x1;
	var->c.im = y / var->zoom + var->y1;
	return (var);
}

t_var	*mandel_init(t_var *var)
{
	var->x1 = -2.1;
	var->x2 = 0.6;
	var->y1 = -1.2;
	var->y2 = 1.2;
	var->iter_max = 50;
	var->zoom = 450;
	var->xmax = (var->x2 - var->x1) * var->zoom;
	var->ymax = (var->y2 - var->y1) * var->zoom;
	return (var);
}
t_var	*alloc_struct(t_var *var)
{
	var = malloc(sizeof(t_var));
	if(!var)
		return (NULL); 
	else 
		return (var);
}
int main(int ac, char **av)
{
	int		color[50] = {
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5,
		0xF09E6C, 0xFAF378, 0x71E3A3, 0x708FFA, 0xE653C5
	};
	t_var	*var;

	var = alloc_struct(var);
	if (!var)
		return (1);
	if (av[1])
	{
		var = mandel_init(var);
		var->mlx = mlx_init();
		var->window = mlx_new_window(var->mlx, var->xmax, var->ymax, "Mandelbrot");	
		mandelbrot(color, var);
		mlx_key_hook(var->window, key_hook, &var);
		mlx_loop(var->mlx);
	}
}