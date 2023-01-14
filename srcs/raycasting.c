/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:52:00 by skhali            #+#    #+#             */
/*   Updated: 2023/01/14 17:01:54 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char Map2[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,1,0,0,0,1,0,0,0,1},
  {1,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,1,0,0,1,1,0,1,1,0,0,0,0,1,0,1,0,1,0,0,0,1},
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

//Eviter la division par 0 : la division par zéro tend vers l'infini
//On donne un tres grand nombre à delta
//Il faut faire une equation à 2 inconnue
//taux d'accroissement (f(x2) - f(x1))/(x1 - x2)
//si dx = 1 alors dy = m
//donc x2 - x1 = 1 -> x2 = x1 + 1
//f2 - f1 = dy/dx
//dy = (f2 - f1)/dx
//gradient/coeff directeur : m = dy/dx; m = newdy / newdx
//dy/dx = newdy/newdx 
//si dx = 1 : dy = newdy/newdx
//si je divise d'un coté je divise de l'autre
//Pythagore : sqrt(a^2 + b^2) -> a = 1; b = dy/dx
void	raycasting_init(t_game *window, int x)
{
	window->camerax = 2 * x / (double)screenWidth - 1;
	window->rayDirx = window->pdx + window->planex * window->camerax;
	window->rayDiry = window->pdy + window->planey * window->camerax;
	window->rayPosx = (double)window->px + 0.5 ;
	window->rayPosy = (double)window->py + 0.5;
	window->mapx = (int)window->rayPosx;
	window->mapy = (int)window->rayPosy;
	if (window->rayDirx == 0)
		window->deltadistx = 1e30;
	else
		window->deltadistx = sqrt (1 + (window->rayDiry * window->rayDiry)
				/ (window->rayDirx * window->rayDirx));
	if (window->rayDiry == 0)
		window->deltadisty = 1e30;
	else
		window->deltadisty = sqrt(1 + (window->rayDirx * window->rayDirx)
				/ (window->rayDiry * window->rayDiry));
}

//si raydirx < 0 le rayon va sur la gauche sinon droite
//calcule de la longueur du rayon du point de depart à la premiere intersection
//on l'incremente ensuite au fur et à mesure en commencat par mapx pus mapy
//qui reprensente le carré sur lequel on est 
//pour avoir la pente d'un  vecteur, je multiplie par le coefficient directeur delta (la pente)
void	get_firstdist(t_game *window)
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
void	get_dist(t_game *window)
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
		if (window->map[window->mapy][window->mapx] == '1')
			window->hit = 1;
		// if (Map2[window->mapx][window->mapy] == 1)
	}
	
	if (window->side == 0)
		window->perpwalldist = (((double)window->mapx - window->rayPosx
					+ (1 - (double)window->stepx) / 2) / window->rayDirx);
	else
		window->perpwalldist = (((double)window->mapy - window->rayPosy
					+ (1 - (double)window->stepy) / 2) / window->rayDiry);
}

void	draw_game(t_game *window, int x)
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

int	raycasting(t_game *window)
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
	mlx_put_image_to_window(window->mlx, window->mlx_win,
		window->mlx_image, 0, 0);
	return (0);
}
