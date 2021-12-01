#ifndef FRACTOL_H
# define FRACTOL_H


# include <stdio.h>
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include <math.h>

# define W          1000
# define H          800
# define K_RIGHT    124
# define K_LEFT     123
# define K_UP       126

# define FLIMIT     5000000000000000000
# define K_S        1
# define K_Z        13
# define K_A        12


# define K_DOWN     125
# define M_DOWN     4
# define M_UP       5
# define M_RCLICK   1
# define M_MCLICK   6
# define M_LCLICK   2

typedef struct s_complexe
{
    long double   re;
    long double   im;
}              t_complexe;

typedef struct s_img
{
    void        *img;
    char        *addr;
    int            bits_per_pixel;
    int            line_length;
    int            endian;
}               t_img;

typedef struct s_mouse
{
    int x;
    int y;
    int tmpx;
    int tmpy;
}              t_mouse;

typedef struct s_var
{
    char        name;
    void        *mlx;
    void        *window;
    long double       x1;
    long double       x2;
    long double      y1;
    long double       y2;
    long double      zoom;
    int         set;
    int         move;
    ull         color;
    ull         iter;
    ull         iter_max;
    t_complexe  z;
    t_complexe  c;
    t_img       img;
    t_mouse     mouse;
}               t_var;

int     key_hook(int key, t_var *var);
int     mouse_hook(int mouse, int x, int y, t_var *var);
int     alg(t_var *var, float x, float y);
int     ft_control(t_var *var);
int     julia_move(t_var *var);
void    print_name(t_var *var);
void    print_help(void);
void    dofractol(t_var *var, char c);
void    draw(t_var *var);
void    my_mlx_pixel_put(t_img *img, int x, int y, int color);
void    zoom(t_var *var, int i);
void    dezoom(t_var *var, int i);
void    fract_init(t_var *var, char c);
void    move_w_arrow(t_var *var, int key);
char    *ft_strjoinf(char *s1, char *s2);
char    *ft_ftoa(float n);
char    *ft_ulltoa(ull n);
long double	conv_res(int pos, int rtmp);
t_var   *set_alg(t_var *var, float x, float y);
t_var   *julia_init(t_var *var);
t_var   *mandel_init(t_var *var);
t_var   *ship_init(t_var *var);


#endif
