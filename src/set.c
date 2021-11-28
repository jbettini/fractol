#include "fractol.h"

t_var    *set_alg(t_var *var, float x, float y)
{
    if (var->name == 'j')
    {
        var->iter = 0;
        var->z.re = x / var->zoom + var->x1;
        var->z.im = y / var->zoom + var->y1;
        var->c.re = 0.285;
        var->c.im = 0.013;
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
        var->c.re = 0.285;
        var->c.im = 0.01;
    }
    return (var);
}

t_var    *julia_init(t_var *var)
{
    var->name = 'j';
    var->x1 = -1.5;
    var->x2 = 1.5;
    var->y1 = -1.5;
    var->y2 = 1.5;
    var->iter_max = 200;
    var->zoom = 300;
    var->mouse.x = W / 2;
    var->mouse.y = H / 2;
    var->color = NULL;
    var->set = 1;
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
    var->mouse.x = W / 2;
    var->mouse.y = H / 2;
    var->color = NULL;
    var->set = 1;
    return (var);
}

t_var    *ship_init(t_var *var)
{
    var->name = 's';
    var->x1 = -2.1;
    var->x2 = 0.6;
    var->y1 = -1.2;
    var->y2 = 1.2;
    var->iter_max = 50;
    var->zoom = 300;
    var->mouse.x = W / 2;
    var->mouse.y = H / 2;
    var->color = NULL;
    var->set = 1;
    return (var);
}
