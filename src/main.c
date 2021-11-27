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
	//move_w_arrow(key);
	if (key == K_Z)
		zoom(var, 0);
	if (key == K_S && var->zoom > 0.1)
		dezoom(var, 0);
	//printf("%d\n", key);
	draw(var);
	return (0);
}
void	zoom(t_var *var, int i)
{
	if (i == 1)
	{
		var->x1 = (var->mouse.x / var->zoom + var->x1) - (var->mouse.x / (var->zoom * 1.25));
		var->y1 = (var->mouse.y / var->zoom + var->y1) - (var->mouse.y / (var->zoom * 1.25));
		var->zoom *= 1.25;
		var->iter_max *= 1.5;
	}
	else if (i == 0)
	{
		var->x1 = ((W / 2) / var->zoom + var->x1) - ((W / 2) / (var->zoom * 1.25));
		var->y1 = ((H / 2) / var->zoom + var->y1) - ((H / 2) / (var->zoom * 1.25));
		var->zoom *= 1.25;
		var->iter_max += var->zoom / 6 - var->iter_max;
	}
}
void	dezoom(t_var *var, int i)
{
	if (i == 1 && var->zoom > 0.1)
	{
		var->x1 = (var->mouse.x / var->zoom + var->x1) - (var->mouse.x / (var->zoom / 1.25));
		var->y1 = (var->mouse.y / var->zoom + var->y1) - (var->mouse.y / (var->zoom / 1.25));
		var->zoom /= 1.25;
		var->iter_max /= 1.25;
	}
	else if (i == 0 && var->zoom > 0.1)
	{
		var->x1 = ((W / 2) / var->zoom + var->x1) - ((W / 2) / (var->zoom / 1.25));
		var->y1 = ((H / 2) / var->zoom + var->y1) - ((H / 2) / (var->zoom / 1.25));
		var->zoom -= 1.25;
		var->iter_max -= 1.25;
	}
}
void	print_name(t_var *var)
{
	if (var->name == 'm')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Mandelbrot");
	if (var->name == 'j')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Julia");
	if (var->name == 's')
		mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Burning Ship");
}
int	mouse_hook(int mouse, int x, int y, t_var *var)
{
	mlx_mouse_get_pos(var->window, &(var->mouse.x), &(var->mouse.y));
	x = var->mouse.x;
	y = var->mouse.y;
	
	//if (mouse == M_LCLICK)
	//if (mouse == M_RCLICK)

	if (mouse == M_UP)
		zoom(var, 1);
	if (mouse == M_DOWN)
		dezoom(var, 1);
	draw(var);
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
				my_mlx_pixel_put(&(var->img), x, y, var->color[var->iter] * var->set);
		}
	}
    free(var->color);
	mlx_put_image_to_window(var->mlx, var->window, var->img.img, 0, 0);
	print_name(var);
}

void	domandel(t_var *var)
{
	var = mandel_init(var);
	var->mlx = mlx_init();
	var->window = mlx_new_window(var->mlx, W, H, "Mandelbrot");	
	var->img.img = mlx_new_image(var->mlx, W, H); 
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),\
										 &(var->img.line_length), &(var->img.endian));
	draw(var);
	mlx_key_hook(var->window, key_hook, var);
	mlx_mouse_hook(var->window, mouse_hook, var);
	mlx_string_put(var->mlx, var->window, 15, 15, 0x00000000, "Mandelbrot");
	mlx_loop(var->mlx);	
}

void	dojulia(t_var *var)
{
	var = julia_init(var);
	var->mlx = mlx_init();
	var->window = mlx_new_window(var->mlx, W, H, "Julia");	
	var->img.img = mlx_new_image(var->mlx, W, H); 
	var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),\
										 &(var->img.line_length), &(var->img.endian));
	draw(var);
	mlx_key_hook(var->window, key_hook, var);
	mlx_mouse_hook(var->window, mouse_hook, var);
	mlx_string_put(var->mlx, var->window, 15, 15, 0x0000000, "Julia");
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
	/*else if (!ft_strcmp(av[1], "burningship"))
		doship(var);
	else
		printf("ERROR fractol -h for help/nFractal available : mandelbrot julia\n");*/
}