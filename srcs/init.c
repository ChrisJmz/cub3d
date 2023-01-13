#include "../include/cub3d.h"

void init_direction(t_game *w, char direction)
{
    if ( direction == 'N')
    {
        w->pdx = -1.0;
        w->pdy = 0.0;
    }
    else if ( direction == 'S')
    {
        w->pdx = 0;
        w->pdy = -1;
    }
    else if ( direction == 'E')
    {
        w->pdx = 1;
        w->pdy = 0;
    }
    else if ( direction == 'W')
    {
        w->pdx = -1;
        w->pdy = 0;
    }
    else
        write(2, "Not a valid direction.\n", 23);
}

void init_plane(t_game *w, char direction)
{
    if ( direction == 'N')
    {
        w->planex = 0.0;
        w->planey = 0.66;
    }
    else if ( direction == 'S')
    {
        w->planex = -1;
        w->planey = 0;
    }
    else if ( direction == 'E')
    {
        w->planex = 0;
        w->planey = -1;
    }
    else if ( direction == 'W')
    {
        w->planex = 0;
        w->planey = 1;
    }
    else
        write(2, "Not a valid direction.\n", 23);
}

int image_init(t_game *window)
{
	window->mlx = mlx_init();
    if(!window->mlx)
        return (simple_error_handler("Error in the initialisation of the mlx.\n", window));
    window->mlx_image = mlx_new_image(window->mlx, screenWidth, screenHeight);
    window->addr = (int *)mlx_get_data_addr(window->mlx_image, &window->bits_per_pixel, &window->line_length, &window->endian);
    window->mlx_win = mlx_new_window(window->mlx, screenWidth, screenHeight,  "Cub3D");
    if(!window->mlx_win)
    {
        mlx_destroy_display(window->mlx);
        return(simple_error_handler("Error in the creation of the window.\n", window));
    }
    window->px = 14;
    window->py = 5;
    window->pa = 0;
    init_direction(window, 'N');
    init_plane(window, 'N');
    return (1);
}