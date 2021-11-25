#include "fractol.h"

int	*color_maker(t_var *var)
{
	int i;

	i = 0;
	var->color = malloc(sizeof(int) * var->iter_max);
	if(var->color)
	{
		while (i < var->iter_max)
		{
			if (i < var->iter_max)
				var->color[i++] = 0xF09E6C;
			if (i < var->iter_max)
				var->color[i++] = 0xFAF378;
			if (i < var->iter_max)
				var->color[i++] = 0x71E3A3; 
			if (i < var->iter_max)
				var->color[i++] = 0x708FFA; 
			if (i < var->iter_max)
				var->color[i++] = 0xE653C5;
		}
		return(var->color);
	}
	return(NULL);
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
	var->zoom = 350;
	var->xmax = (var->x2 - var->x1) * var->zoom;
	var->ymax = (var->y2 - var->y1) * var->zoom;
	var->color = NULL;
	return (var);
}