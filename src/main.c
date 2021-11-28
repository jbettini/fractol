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

void    doship(t_var *var)
{
    var = ship_init(var);
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
    if (!var) (printf("Malloc Error"));
        return ;
    if (ac >= 2)
    {
        if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "Mandelbrot"))
            domandel(var);
        else if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "Julia"))
            dojulia(var);
        else if (!ft_strcmp(av[1], "burningship") || !ft_strcmp(av[1], "Burningship"))
            doship(var);
        else
            printf("ERROR \nArg available :\nJulia\nMandelbrot\nBurningship\nfractol -h for help");
        return (0);
    }
    else
    {
        free(var);
        return (printf("Argument Error, please retry\nfractol -h for help\n"));
    }
}
