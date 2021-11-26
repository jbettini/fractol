#include "fractol.h"

int	key_hook(int key, t_var *var)
{
	if (key == 53)
	{
		mlx_destroy_image(var->mlx, var->img.img);
		mlx_destroy_window(var->mlx, var->window);
		free(var);
		exit(0);
	}
	if (key == 124) // droite
	{
		var->x1 += 0.05;
		var->x2 += 0.05;
	}
	if (key == 123) // gauche
	{
		var->x1 -= 0.05;
		var->x2 -= 0.05;
	}
	if (key == 126) //haut
	{
		var->y1 -= 0.05;
		var->y2 -= 0.05;
	}
	if (key == 125) //bas
	{
		var->y1 += 0.05;
		var->y2 += 0.05;
	}
	
	if (key == 13)
	{
		var->x1 *= 0.9;
		var->x2 /= 0.9;
		var->y1 *= 0.9;
		var->y2 /= 0.9;
		var->zoom *= 1.25;
		var->iter_max *= 1.5;
	}
		draw(var);
	//printf("key = %d\n",key);
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
	while (++y < 800)
	{
		x = -1;
		while (++x < 1000)
		{
			if (alg(var, x, y))
				my_mlx_pixel_put(&(var->img), x, y, 0x00000000);
			else
				my_mlx_pixel_put(&(var->img), x, y, var->color[var->iter]);
		}
	}

    free(var->color);
	mlx_put_image_to_window(var->mlx, var->window, var->img.img, 0, 0);
	mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Mandelbrot");
}
void	domandel(t_var *var)
{
	var = mandel_init(var);
	var->mlx = mlx_init();
	var->window = mlx_new_window(var->mlx, 1000, 800, "Mandelbrot");	
	var->img.img = mlx_new_image(var->mlx, 1000, 800); 
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),\
										 &(var->img.line_length), &(var->img.endian));
	draw(var);
	mlx_key_hook(var->window, key_hook, var);
	mlx_loop(var->mlx);	
}

void	dojulia(t_var *var)
{
	var = julia_init(var);
	var->mlx = mlx_init();
	var->window = mlx_new_window(var->mlx, 1000, 800, "Mandelbrot");	
	var->img.img = mlx_new_image(var->mlx, 1000, 800); 
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),\
										 &(var->img.line_length), &(var->img.endian));
	draw(var);
	mlx_key_hook(var->window, key_hook, var);
	mlx_loop(var->mlx);
}
int main(int ac, char **av)
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if (!var)
		return (1);
	if (!ft_strcmp(av[1], "mandelbrot"))
		domandel(var);
	else if (!ft_strcmp(av[1], "julia"))
		dojulia(var);
	else
		printf("ERROR Fractal available : mandelbrot julia\n");
}