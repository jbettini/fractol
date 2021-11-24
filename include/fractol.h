#ifndef FRACTOL_H
# define FRACTOL_H


# include "stdio.h"
# include "stdlib.h"
# include "mlx.h"
# include "libft.h"

#define MLX var->mlx
#define WIN var->window

typedef struct s_complexe
{
    float   re;
    float   im;
}              t_complexe;

typedef struct s_var 
{
    void    *mlx;
    void    *window;
    float       x1;
    float       x2;
    float       y1;
    float       y2;
    int         iter_max;
    int         iter;
    float       zoom;
    float       xmax;
    float       ymax;
    t_complexe  z;
    t_complexe  c;
}               t_var;

t_var	*mandel_init(t_var *var);
t_var	*set_alg(t_var *var, float x, float y);
int	key_hook(int key, t_var *var);
int	mandel_alg(t_var *var, float x, float y);



#endif