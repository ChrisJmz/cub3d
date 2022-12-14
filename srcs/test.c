#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#define PI 3.1415926535

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
    int map;
}				t_data;

int mapX= 8; int mapY=8; int mapS=64;
float pdx, pdy, pa;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
  char    *dst;

  dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
  *(unsigned int*)dst = color;
}

void    ft_erase(t_data *img, float x, float y)
{
    float tmpx;
    float tmpy;

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

    tmpx = img->px;
    tmpy = img->py;
    while (tmpx <  x+5)
    {
        while (tmpy < y+5)
        {
            mlx_pixel_put(img->mlx, img->mlx_win, tmpx, tmpy, 0x00FF0000);
            tmpy++;
        }
        tmpy = img->py;
        tmpx++;
    }
    printf("tmpx: %f\ntmpy: %f\n", tmpx, tmpy);
}


void ft_draw_square(t_data *data, int posx, int posy, int color)
{
    int x;
    int y;

    y = -1;
    while (++y < 800 / 7 / 2)
    {
        x = -1;
        while (++x < 800 / 7 / 2)
            mlx_pixel_put(data->mlx, data->mlx_win, posx + x, posy + y, color);
    }
}


int map[]=
{
    1,1,1,1,1,1,1,1,
    1,0,0,0,0,1,0,1,
    1,0,0,0,1,1,0,1,
    1,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,0,0,0,0,1,
    1,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,
};

void ft_minimap(t_data *data)
{
    int x = -1, y = -1, xo, yo;

    while (++y < mapY)
    {
        while (++x < mapX)
        {
            xo = x*mapS;
            yo = y*mapS;
            if (map[y*mapX+x] == 1)
            {
                ft_draw_square(data, xo, yo, 0x0DA70D6);
            }
            else
                ft_draw_square(data, xo, yo, 0x0FFFF00);
        }
        x = -1;
    }
}


void drawLine(t_data *data, float x, float y)
{
    float tmpx;
    float tmpy;
    tmpx = data->px;
    tmpy = data->py;
    while (tmpx < x + 20)
    {
        while (tmpy < y + 2.5)
        {
            mlx_pixel_put(data->mlx, data->mlx_win, tmpx, tmpy, 0x0DA70D6);
            tmpy++;
        }
        tmpy = data->py;
        tmpx++;
    }
}

int key_hook(int keycode, t_data *data)
{
    // (void)keycode;
    printf("keycode: %d, px: %f, py:%f\n", keycode, data->px, data->py);
    if (keycode == 65307)
        exit(0);
    else if (keycode == 122) // Z
    {
        // data->px += pdx;
        // data->py += pdy;
        ft_erase(data, data->px, data->py);
        ft_minimap(data);
        ft_draw(data, data->px+=pdx, data->py+=pdy);
    }
    else if (keycode == 113) // Q
    {
        // pa -= 0.1;
        // if (pa < 0)
        //     pa +=2*PI;
        // pdx = cos(pa) *5;
        // pdy = sin(pa)*5;
        ft_erase(data, data->px, data->py);
        ft_minimap(data);
        ft_draw(data, data->px -= pdx - pdy, data->py -= pdy);
    }
    else if (keycode == 115) // S
    {
        ft_erase(data, data->px, data->py);
        ft_minimap(data);
        ft_draw(data, data->px -= pdx, data->py -= pdy);
    }
    else if (keycode == 100) // D
    {
        ft_erase(data, data->px, data->py);
        ft_minimap(data);
        ft_draw(data, data->px+= +5, data->py);
    }
    else if (keycode == 65361) // left
    {
        pa -= 0.1;
        if (pa < 0)
            pa +=2*PI;
        pdx = cos(pa) *5;
        pdy = sin(pa)*5;
        drawLine(data, pdx, pdy);
    }
    else if (keycode == 65363) // right
    {
        pa += 0.1;
        if (pa > 2*PI)
            pa -=2*PI;
        pdx = cos(pa) * 5;
        pdy = sin(pa) * 5;
        drawLine(data, data->px, data->py);
    }
    return (0);
}

int	main(void)
{
	t_data	img;
	img.mlx = mlx_init();
    img.px = 80;
    img.py = 80;
    pdx = cos(pa) *5;
    pdy = sin(pa) *5;

	img.mlx_win = mlx_new_window(img.mlx, 1200, 800, "cub3d et encore");
    ft_minimap(&img);
    ft_draw(&img, img.px, img.py);
    drawLine(&img, img.px, img.py);
    mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_loop(img.mlx);
    return (0);
}