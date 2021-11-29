#include "fractol.h"

t_var    *set_alg(t_var *var, float x, float y)
{
    if (var->name == 'j')
    {
        var->iter = 0;
        var->z.re = x / var->zoom + var->x1;
        var->z.im = y / var->zoom + var->y1;
    }
    else if (var->name == 'm')
    {
        var->iter = 0;
        var->c.re = x / var->zoom + var->x1;
        var->c.im = y / var->zoom + var->y1;
        var->z.re = 0;
        var->z.im = 0;
    }
    else if (var->name == 's')
    {
        var->iter = 0;
        var->z.re = x / var->zoom + var->x1;
        var->z.im = y / var->zoom + var->y1;
        var->c.re = 0;
        var->c.im = 0;
    }
    return (var);
}

t_var    *julia_init(t_var *var)
{
    var->name = 'j';
    var->x1 = -2.5;
    var->x2 = 1.5;
    var->y1 = -2;
    var->y2 = 1.5;
    var->c.re = -0.8;
    var->c.im = 0.156;
    var->iter_max = 150;
    var->zoom = 200;
    var->mouse.x = -1;
    var->mouse.y = -1;
    var->color = 0x606060;
    var->set = 32;
    var->move = 1;
    return (var);
}

t_var    *mandel_init(t_var *var)
{
    var->name = 'm';
    var->x1 = -2.1;
    var->x2 = 0.6;
    var->y1 = -1.2;
    var->y2 = 1.2;
    var->iter_max = 80;
    var->zoom = 300;
    var->mouse.x = -1;
    var->mouse.y = -1;
    var->color = 0x606060;
    var->set = 32;
    return (var);
}

t_var    *ship_init(t_var *var)
{
    var->name = 's';
    var->x1 = -1.2;
    var->x2 = 1;
    var->y1 = -2;
    var->y2 = 1;
    var->iter_max = 80;
    var->zoom = 300;
    var->mouse.x = -1;
    var->mouse.y = -1;
    var->color = 0x606060;
    var->set = 32;
    return (var);
}

int	ft_control(t_var *var)
{
	mlx_key_hook(var->window, key_hook, var);
    mlx_mouse_hook(var->window, mouse_hook, var);
	if (var->name == 'j' && var->move == 1)
		julia_move(var);
	draw(var);
	return (0);
}