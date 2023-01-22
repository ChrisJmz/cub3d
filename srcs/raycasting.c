/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:00 by skhali            #+#    #+#             */
/*   Updated: 2023/01/22 11:38:01 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
		if (window->map[window->mapx][window->mapy] == '1')
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
	int i;
	int	mid;
	int	color;
	
	mid = -1;
	color = 0x00FF000;
	window->lineheight = (int)(SCREENHEIGHT / window->perpwalldist);
	window->drawstart = -window->lineheight / 2 + SCREENHEIGHT / 2;
	if (window->drawstart < 0)
		window->drawstart = 0;
	window->drawend = window->lineheight / 2 + SCREENHEIGHT / 2;
	if (window->drawend >= SCREENHEIGHT || window->drawend < 0)
		window->drawend = SCREENHEIGHT - 1;
	window->drawend = SCREENHEIGHT - window->drawstart;
	i = window->drawend;
	printf("[%d][%d]\n", window->drawstart, window->drawend);
	while (++mid < window->drawstart)
		window->addr[mid * window->line_length / 4 +
			x] = color;
	if (mid <= window->drawend)
		init_image(window, mid, x);
	mid = i;
	while (++mid < SCREENHEIGHT)
		window->addr[mid * window->line_length / 4 +
			x] = color;
}

void	raycasting_loop(t_game *window)
{
	int	x;

	x = 0;
	while (x < SCREENWIDTH)
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
	/*if (window->mlx_image)
		mlx_destroy_image(window->mlx, window->mlx_image);
	window->mlx_image = mlx_new_image(window->mlx, SCREENWIDTH, SCREENHEIGHT);*/
	if (!window->mlx_image)
	{
		mlx_destroy_window(window->mlx, window->mlx_win);
		mlx_destroy_display(window->mlx);
		exit_error_handler("Not a valid direction\n");
	}
	window->addr = (int *)mlx_get_data_addr(window->mlx_image,
			&window->bits_per_pixel, &window->line_length, &window->endian);
	raycasting_loop(window);
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->mlx_image, 0, 0);
	simple_moves(window);
	rotate_moves(window);
	return (0);
}
