/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:52:00 by skhali            #+#    #+#             */
/*   Updated: 2023/01/22 21:27:22 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	init_direction(t_game *w, char direction)
{
	if (direction == 'N')
	{
		w->pdx = -1;
		w->pdy = 0;
	}
	else if (direction == 'S')
	{
		w->pdx = 1;
		w->pdy = 0;
	}
	else if (direction == 'E')
	{
		w->pdx = 0;
		w->pdy = 1;
	}
	else if (direction == 'W')
	{
		w->pdx = 0;
		w->pdy = -1;
	}
}

void	init_plane(t_game *w, char direction)
{
	if (direction == 'N')
	{
		w->planex = 0;
		w->planey = 0.66;
	}
	else if (direction == 'S')
	{
		w->planex = 0;
		w->planey = -0.66;
	}
	else if (direction == 'E')
	{
		w->planex = 0.66;
		w->planey = 0;
	}
	else if (direction == 'W')
	{
		w->planex = -0.66;
		w->planey = 0;
	}
}

void	init_start(t_game *window)
{
	check_direction(window->map, window);
	init_direction(window, window->type);
	init_plane(window, window->type);
	window->input = malloc(sizeof(t_input));
	window->rayposx = window->px + 0.5;
	window->rayposy = window->py + 0.5;
	window->speed = 0.0666f;
	window->rot = 0.0785f;
}

int	image_init(t_game *window)
{
	window->mlx = mlx_init();
	if (!window->mlx)
		return (simple_error_handler("Error in the initialisation of the mlx.\n",
				window));
	load_images(window);
	window->mlx_win = mlx_new_window(window->mlx, SCREENWIDTH, SCREENHEIGHT,
			"Cub3D");
	if (!window->mlx_win)
	{
		mlx_destroy_display(window->mlx);
		return (simple_error_handler("Error in the creation of the window.\n",
				window));
	}
	window->mlx_image = mlx_new_image(window->mlx, SCREENWIDTH, SCREENHEIGHT);
	init_start(window);
	return (1);
}

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
	window->camerax = 2 * x / (double)SCREENWIDTH - 1;
	window->raydirx = window->pdx + window->planex * window->camerax;
	window->raydiry = window->pdy + window->planey * window->camerax;
	window->mapx = (int)window->rayposx;
	window->mapy = (int)window->rayposy;
	if (window->raydirx == 0)
		window->deltadistx = 1e30;
	else
		window->deltadistx = sqrt (1 + (window->raydiry * window->raydiry)
				/ (window->raydirx * window->raydirx));
	if (window->raydiry == 0)
		window->deltadisty = 1e30;
	else
		window->deltadisty = sqrt(1 + (window->raydirx * window->raydirx)
				/ (window->raydiry * window->raydiry));
}
