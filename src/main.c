#include "fractol.h"

void    fract_init(t_var *var, char c)
{
    if (c == 'j')
        var = julia_init(var);
    else if (c == 'm')
        var = mandel_init(var);
    else if (c == 's')
        var = ship_init(var);
}

long double	conv_res(int pos, int rtmp)
{
	long double res;

	res = pos * rtmp;
	return (res);
}

void    print_help(void)
{
    printf("Arg available : Julia, Mandelbrot, Burningship\n Command list :\n\
            - Use keyboard arrows for move on the program\n\
            - Z for zoom\n\
            - S for zoom out\n\
            - A for stop julia variation\n\
            - 1 for change color palette\n\
            - 2, 3, 4, for more color\n\
            - Right Click for initialising Julia\n\
            - Middle Click for initialising Burning Ship\n\
            - Left Click for initialising Mandelbrot\n\
            - Mouse Wheel for zoom or zoom out\n");
}

void    dofractol(t_var *var, char c)
{
    fract_init(var, c);
    var->mlx = mlx_init();
    var->window = mlx_new_window(var->mlx, W, H, "Fractol");
    var->img.img = mlx_new_image(var->mlx, W, H);
    var->img.addr = mlx_get_data_addr(var->img.img, &(var->img.bits_per_pixel),\
                                         &(var->img.line_length), &(var->img.endian));
    draw(var);
    mlx_loop_hook(var->mlx, ft_control, var);
    print_name(var);
    mlx_loop(var->mlx);
}

int main(int ac, char **av)
{
    t_var    *var;

    var = malloc(sizeof(t_var));
    if (!var)
        return (printf("Malloc Error"));
    if (ac >= 2)
    {
        if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "Mandelbrot"))
            dofractol(var, 'm');
        else if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "Julia"))
            dofractol(var, 'j');
        else if (!ft_strcmp(av[1], "burningship") || !ft_strcmp(av[1], "Burningship"))
            dofractol(var, 's');
        else if (!ft_strcmp(av[1], "-h"))
            print_help();
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
