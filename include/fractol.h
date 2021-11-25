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

typedef struct s_img
{
    void    	*img;
	char    	*addr;
	int	    	bits_per_pixel;
	int	    	line_length;
	int	    	endian;
}               t_img;

typedef struct s_var 
{
    void        *mlx;
    void        *window;
    int         *color;
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
    t_img       img;
}               t_var;

t_var	*mandel_init(t_var *var);
t_var	*set_alg(t_var *var, float x, float y);
int	    key_hook(int key, t_var *var);
int	    mandel_alg(t_var *var, float x, float y);
void	mandelbrot(t_var *var);
int	    *color_maker(t_var *var);
int	    mandel_alg(t_var *var, float x, float y);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);

#endif