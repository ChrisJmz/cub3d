/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:07:46 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/22 21:58:49 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	tex_loop(t_game *w, int mid, int x, t_texture *t)
{
	w->step = 1.0 * w->texture_no->height / w->lineheight;
	w->texpos = (w->drawstart - SCREENHEIGHT / 2 + w->lineheight / 2) * w->step;
	while (mid <= w->drawend)
	{
		w->texy = (int)w->texpos &(t->height - 1);
		w->texpos += w->step;
		if (mid < SCREENHEIGHT && x < SCREENWIDTH)
			w->addr[mid * w->line_length / 4 + x] = t->addr[w->texy
				* t->line_length / 4 + w->tex];
		mid += 1;
	}
}

//wallx : coordonnée sur x de la colonne que l'on veut utiliser
//tex : coordonnée sur x dans la texture
void	init_imagep1(t_game *w)
{
	if (w->side == 1)
		w->wallx = w->rayposx + ((w->mapy - w->rayposy + (1 - w->stepy) / 2)
				/ w->raydiry) * w->raydirx;
	else
		w->wallx = w->rayposy + ((w->mapx - w->rayposx + (1 - w->stepx) / 2)
				/w->raydirx) * w->raydiry;
	w->wallx -= floor(w->wallx);
}

void	init_image(t_game *w, int mid, int x)
{
	init_imagep1(w);
	if (w->side == 0 && w->raydirx >= 0)
	{
		w->tex = (int)(w->wallx * w->texture_so->width);
		w->tex = w->texture_so->width - w->tex - 1;
		tex_loop(w, mid, x, w->texture_so);
	}
	else if (w->side == 0 && w->raydirx < 0)
	{
		w->tex = (int)(w->wallx * w->texture_no->width);
		w->tex = w->texture_no->width - w->tex - 1;
		tex_loop(w, mid, x, w->texture_no);
	}
	else if (w->side == 1 && w->raydiry < 0)
	{
		w->tex = (int)(w->wallx * w->texture_we->width);
		tex_loop(w, mid, x, w->texture_we);
	}
	else if (w->side == 1 && w->raydiry >= 0)
	{
		w->tex = (int)(w->wallx * w->texture_ea->width);
		tex_loop(w, mid, x, w->texture_ea);
	}
}
