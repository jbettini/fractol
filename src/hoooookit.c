#include "fractol.h"

void    move_w_arrow(t_var *var, int key)
{
    if (key == K_RIGHT)
        var->x1 += (W / var->zoom) / 10;
    if (key == K_LEFT)
        var->x1 -= (W / var->zoom) / 10;
    if (key == K_UP)
        var->y1 -= (H / var->zoom) / 10;
    if (key == K_DOWN)
        var->y1 += (H / var->zoom) / 10;
	if (key == 18 && var->set != 32)
		var->set *= 2;
	else if (key == 18 && var->set == 32)
		var->set = 1;
}

int	key_hook(int key, t_var *var)
{
	if (key == 53)
	{
		mlx_destroy_image(var->mlx, var->img.img);
		mlx_destroy_window(var->mlx, var->window);
		free(var);
		exit(0);
	}
    move_w_arrow(var, key);
	if (key == K_Z)
		zoom(var, 0);
	if (key == K_S && var->zoom > 0.1)
		dezoom(var, 0);
	draw(var);
	return (0);
}

void	zoom(t_var *var, int i)
{
	if (i == 1 && (var->zoom) < FLIMIT)
	{
		var->x1 = (var->mouse.x / var->zoom + var->x1) - (var->mouse.x / (var->zoom * 1.25));
		var->y1 = (var->mouse.y / var->zoom + var->y1) - (var->mouse.y / (var->zoom * 1.25));
		var->zoom *= 1.25;
		if (var->zoom >= 300)
			var->iter_max *= 1.25;
	}
	else if (i == 0 && (var->zoom) < FLIMIT)
	{
		var->x1 = ((W / 2) / var->zoom + var->x1) - ((W / 2) / (var->zoom * 1.25));
		var->y1 = ((H / 2) / var->zoom + var->y1) - ((H / 2) / (var->zoom * 1.25));
		var->zoom *= 1.25;
		if (var->zoom >= 300)
			var->iter_max *= 1.25;
	}
	if (!var->iter_max)
		var->iter_max = 8000;
}

void	dezoom(t_var *var, int i)
{
	if (i == 1 && var->zoom > 0.1)
	{
		var->x1 = (var->mouse.x / var->zoom + var->x1) - (var->mouse.x / (var->zoom / 1.25));
		var->y1 = (var->mouse.y / var->zoom + var->y1) - (var->mouse.y / (var->zoom / 1.25));
		var->zoom /= 1.25;
		if (var->iter_max > 80)
			var->iter_max /= 1.25;
	}
	else if (i == 0 && var->zoom > 0.1)
	{
		var->x1 = ((W / 2) / var->zoom + var->x1) - ((W / 2) / (var->zoom / 1.25));
		var->y1 = ((H / 2) / var->zoom + var->y1) - ((H / 2) / (var->zoom / 1.25));
		var->zoom /= 1.25;
		if (var->iter_max > 80)
			var->iter_max /= 1.25;
	}
	if (var->iter_max <= 0)
		var->iter_max = 8000;
}

int	mouse_hook(int mouse, int x, int y, t_var *var)
{
	mlx_mouse_get_pos(var->window, &(var->mouse.x), &(var->mouse.y));
	x = var->mouse.x;
	y = var->mouse.y;
	if (var->name == 'j')
		julia_move(var, x, y);
	if (mouse == M_LCLICK)
		var = julia_init(var);
	if (mouse == M_RCLICK)
        var = mandel_init(var);
    if (mouse == M_MCLICK)
        var = ship_init(var);
	if (mouse == M_UP)
		zoom(var, 1);
	if (mouse == M_DOWN)
		dezoom(var, 1);
	draw(var);
	return (0);
}
