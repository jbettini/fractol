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
				var->color[i++] = 0xE05219;//E653C5;
			if (i < var->iter_max)
				var->color[i++] = 0xA80202;// 0xF09E6C;
			if (i < var->iter_max)
				var->color[i++] = 0x9732A7;//FAF378;
			if (i < var->iter_max)
				var->color[i++] = 0x3A4BA8;//71E3A3; 
			if (i < var->iter_max)
				var->color[i++] = 0x00A5AB;//708FFA; 
		}
		return(var->color);
	}
	return(NULL);
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
	else
		return (0);
}

t_var	*set_alg(t_var *var, float x, float y)
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
	return (var);
}

t_var	*julia_init(t_var *var)
{
	var->name = 'j';
	var->x1 = -1.5;
	var->x2 = 1.5;
	var->y1 = -1.5;
	var->y2 = 1.5;
	var->iter_max = 150;
	var->zoom = 300;
	var->xmax = (var->x2 - var->x1) * var->zoom;
	var->ymax = (var->y2 - var->y1) * var->zoom;
	var->color = NULL;
	return (var);
}

t_var	*mandel_init(t_var *var)
{
	var->name = 'm';
	var->x1 = -2.5;
	var->x2 = 0.6;
	var->y1 = -1.2;
	var->y2 = 1.2;
	var->iter_max = 50;
	var->zoom = 300;
	var->xmax = (var->x2 - var->x1) * var->zoom;
	var->ymax = (var->y2 - var->y1) * var->zoom;
	var->color = NULL;
	return (var);
}