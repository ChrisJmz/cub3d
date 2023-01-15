/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:00 by skhali            #+#    #+#             */
/*   Updated: 2023/01/15 17:17:57 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int Map2[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,0,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

//si raydirx < 0 le rayon va sur la gauche sinon droite
//calcule de la longueur du rayon du point de depart à la premiere intersection
//on l'incremente ensuite au fur et à mesure en commencat par mapx pus mapy
//qui reprensente le carré sur lequel on est 
//pour avoir la pente d'un  vecteur, je multiplie par le coefficient directeur
//delta (la pente)

static void	get_firstdist(t_game *window)
{
	if (window->rayDirx < 0)
	{
		window->stepx = -1;
		window->sideDistx = (window->rayPosx - window->mapx)
			* window->deltadistx;
	}
	else
	{
		window->stepx = 1;
		window->sideDistx = (window->mapx + 1.0 - window->rayPosx)
			* window->deltadistx;
	}
	if (window->rayDiry < 0)
	{
		window->stepy = -1;
		window->sideDisty = (window->rayPosy - window->mapy)
			* window->deltadisty;
	}
	else
	{
		window->stepy = 1;
		window->sideDisty = (window->mapy + 1.0 - window->rayPosy)
			* window->deltadisty;
	}
}

//on increment  et on agrandit le rayon tant qu'on n'a pas touché de wall
//side pour les ombres
//on corrige l'effet fisheyes
static void	get_dist(t_game *window)
{
	window->hit = 0;
	window->perpwalldist = 0;
	while (window->hit == 0)
	{
		if (window->sideDistx < window->sideDisty)
		{
			window->sideDistx += window->deltadistx;
			window->mapx += window->stepx;
			window->side = 0;
		}
		else
		{
			window->sideDisty += window->deltadisty;
			window->mapy += window->stepy;
			window->side = 1;
		}
		if (Map2[window->mapx][window->mapy] == 1)
			window->hit = 1;
	}
	if (window->side == 0)
		window->perpwalldist = (((double)window->mapx - window->rayPosx
					+ (1 - (double)window->stepx) / 2) / window->rayDirx);
	else
		window->perpwalldist = (((double)window->mapy - window->rayPosy
					+ (1 - (double)window->stepy) / 2) / window->rayDiry);
}

static void	draw_game(t_game *window, int x)
{
	int	j;
	int	color;

	color = 0x00FF000;
	if (window->side == 1)
		color = color / 3;
	window->lineheight = (int)(screenHeight / window->perpwalldist);
	window->drawstart = -window->lineheight / 2 + screenHeight / 2;
	if (window->drawstart < 0)
		window->drawstart = 0;
	window->drawend = window->lineheight / 2 + screenHeight / 2;
	if (window->drawend >= screenHeight || window->drawend < 0)
		window->drawend = screenHeight - 1;
	//int j = -1;
	j = window->drawstart;
	window->drawend = screenHeight - window->drawstart;
	while (++j < window->drawend)
		window->addr[j * window->line_length / 4 + x] = color;
	/*j = window->drawend;
	while (++j < screenHeight)
	{
		window->addr[ j * window->line_length / 4 + x] = color;
	}*/
}

void	raycasting_loop(t_game *window)
{
	int	x;

	x = 0;
	while (x < screenWidth)
	{
		raycasting_init(window, x);
		get_firstdist(window);
		get_dist(window);
		draw_game(window, x);
		x++;
	}
}

int	raycasting(t_game *window)
{
	if (window->mlx_image)
		mlx_destroy_image(window->mlx, window->mlx_image);
	window->mlx_image = mlx_new_image(window->mlx, screenWidth, screenHeight);
	if (!window->mlx_image)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_destroy_display(window->mlx);
		exit_error_handler("Not a valid direction\n", window);
	}
	window->addr = (int *)mlx_get_data_addr(window->mlx_image,
			&window->bits_per_pixel, &window->line_length, &window->endian);
	raycasting_loop(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->mlx_image, 0, 0);
	rotate_moves(window);
	simple_moves(window);
	return (0);
}
