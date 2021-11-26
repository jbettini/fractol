#ifndef FRACTOL_H
# define FRACTOL_H


# include "stdio.h"
# include "stdlib.h"
# include "mlx.h"
# include "libft.h"

#define W 1000
#define H 800

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

typedef struct s_mouse
{
    int x;
    int y;
}              t_mouse;

typedef struct s_var 
{
    char        name;
    void        *mlx;
    void        *window;
    int         *color;
    float       x1;
    float       x2;
    float       y1;
    float       y2;
    int       iter_max;
    int         iter;
    float       zoom;
    float       xmax;
    float       ymax;
    t_complexe  z;
    t_complexe  c;
    t_img       img;
    t_mouse     mouse;
}               t_var;


int	    mouse_hook(int mouse, int x, int y, t_var *var);
void	reset_cplx(t_var * var);
void	dojulia(t_var *var);
void	domandel(t_var *var);
void	draw(t_var *var);
int	    alg(t_var *var, float x, float y);
t_var	*set_alg(t_var *var, float x, float y);
t_var	*julia_init(t_var *var);
t_var	*mandel_init(t_var *var);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int 	key_hook(int key, t_var *var);
int	    *color_maker(t_var *var);



#endif