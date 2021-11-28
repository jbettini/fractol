#include "fractol.h"

void    domandel(t_var *var)
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

void    dojulia(t_var *var)
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
    t_var    *var;

    var = malloc(sizeof(t_var));
    if (!var)
        return (1);
    if (ac == 2)
    {
        if (!ft_strcmp(av[1], "mandelbrot"))
            domandel(var);
        else if (!ft_strcmp(av[1], "julia"))
            dojulia(var);
        /*else if (!ft_strcmp(av[1], "burningship"))
            doship(var);
        else
            printf("ERROR fractol -h for help");*/
    }
    else
        printf("Argument Error, please retry\nfractol -h for help\n");
}
