#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
    void    *player;
    float   px;
    float   py;
}				t_data;

void    ft_erase(t_data *img, float x, float y)
{
    float tmpx;
    float tmpy;

    x = img->px;
    y = img->py;
    tmpx = img->px;
    tmpy = img->py;
    while (tmpx <  x + 5)
    {
        while (tmpy < y + 5)
        {
            mlx_pixel_put(img->mlx, img->mlx_win, tmpx, tmpy, 0x00000000);
            tmpy++;
        }
        tmpy = img->py;
        tmpx++;
    }
}

void    ft_draw(t_data *img, float x, float y)
{
    float tmpx;
    float tmpy;

    x = img->px;
    y = img->py;
    tmpx = img->px;
    tmpy = img->py;
    while (tmpx <  x + 5)
    {
        while (tmpy < y + 5)
        {
            mlx_pixel_put(img->mlx, img->mlx_win, tmpx, tmpy, 0x00FF0000);
            tmpy++;
        }
        tmpy = img->py;
        tmpx++;
    }
    printf("tmpx: %f\ntmpy: %f\n", tmpx, tmpy);
}

int key_hook(int keycode, t_data *data)
{
    // (void)keycode;
    printf("keycode: %d, px: %f, py:%f\n", keycode, data->px, data->py);
    if (keycode == 65307)
        exit(0);
    else if (keycode == 122) // Z
    {
        ft_erase(data, data->px, data->py);
        ft_draw(data, data->px, data->py -= 5);
    }
    else if (keycode == 113) // Q
    {
        ft_erase(data, data->px, data->py);
        ft_draw(data, data->px -= 5, data->py);
    }
    else if (keycode == 115) // S
    {
        ft_erase(data, data->px, data->py);
        ft_draw(data, data->px, data->py += 5);
    }
    else if (keycode == 100) // D
    {
        ft_erase(data, data->px, data->py);
        ft_draw(data, data->px += 5, data->py);
    }
    return (0);
}


int	main(void)
{
	t_data	img;
	img.mlx = mlx_init();
    img.px = 50;
    img.py = 50;
	img.mlx_win = mlx_new_window(img.mlx, 1024, 512, "Hello world!");
    // drawMap2D(&img);
	// img.img = mlx_new_image(img.mlx, 1024, 512);
    ft_draw(&img, 0, 0);
	// mlx_put_image_to_window(img.mlx, img.mlx_win, img.player, img.px, img.py);
    mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
}