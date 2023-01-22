/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:37:45 by skhali            #+#    #+#             */
/*   Updated: 2023/01/22 12:18:18 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_addr(t_texture *t)
{
	t->addr = (int *)mlx_get_data_addr(t->image,
			&t->bits_per_pixel, &(t->line_length), &(t->endian));
}

static void	destroy_images_p1(t_game *image)
{
	if (image->mlx)
	{
		if (image->texture_ea)
			if (image->texture_ea->image)
				mlx_destroy_image(image->mlx, image->texture_ea->image);
		if (image->texture_we)
			if (image->texture_we->image)
				mlx_destroy_image(image->mlx, image->texture_we->image);
		if (image->texture_no)
			if (image->texture_no->image)
				mlx_destroy_image(image->mlx, image->texture_no->image);
		if (image->texture_so)
			if (image->texture_so->image)
				mlx_destroy_image(image->mlx, image->texture_so->image);
	}
}

void	destroy_images(t_game *image, char *str)
{
	destroy_images_p1(image);
	if (image->mlx_win)
		mlx_destroy_window(image->mlx, image->mlx_win);
	if (image->mlx_image)
	{
		mlx_destroy_image(image->mlx, image->mlx_image);
		free(image->mlx);
	}
	if (image->mlx)
	{
		mlx_destroy_display(image->mlx);
		free(image->mlx);
	}
	if (image->texture_no)
		free(image->texture_no);
	if (image->texture_so)
		free(image->texture_so);
	if (image->texture_we)
		free(image->texture_we);
	if (image->texture_ea)
		free(image->texture_ea);
	if (image->input)
		free(image->input);
	free(image);
	exit_error_handler(str);
}

static void	load_wall(t_game *w)
{
	w->texture_no->image = mlx_xpm_file_to_image(w->mlx, w->path.no_path,
			&(w->texture_no->width), &(w->texture_no->height));
	if (!w->texture_no->image)
		destroy_images(w, "Mauvais chargement des images.\n");
	w->texture_so->image = mlx_xpm_file_to_image(w->mlx, w->path.so_path,
			&(w->texture_so->width), &(w->texture_so->height));
	if (!w->texture_so->image)
		destroy_images(w, "Mauvais chargement des images.\n");
	w->texture_ea->image = mlx_xpm_file_to_image(w->mlx, w->path.ea_path,
			&(w->texture_ea->width), &(w->texture_ea->height));
	if (!w->texture_ea->image)
		destroy_images(w, "Mauvais chargement des images.\n");
	w->texture_we->image = mlx_xpm_file_to_image(w->mlx,
			w->path.we_path, &(w->texture_we->width), &(w->texture_we->height));
	if (!w->texture_we->image)
		destroy_images(w, "Mauvais chargement des images.\n");
	get_addr(w->texture_no);
	get_addr(w->texture_so);
	get_addr(w->texture_ea);
	get_addr(w->texture_we);
}

void	load_images(t_game *w)
{
	w->texture_no = malloc(sizeof(t_texture));
	w->texture_no->image = NULL;
	w->texture_so = malloc(sizeof(t_texture));
	w->texture_so->image = NULL;
	w->texture_ea = malloc(sizeof(t_texture));
	w->texture_ea->image = NULL;
	w->texture_we = malloc(sizeof(t_texture));
	w->texture_we->image = NULL;
	load_wall(w);
}

void	tex_loop(t_game *w, int mid, int x, t_texture *t)
{
	w->step = 1.0 * w->texture_no->height / w->lineheight;
	w->texpos = (w->drawstart - SCREENHEIGHT / 2 +
			w->lineheight / 2) * w->step;
	printf("step [%f] texpos [%f] texx [%d]\n", w->step, w->texpos, w->tex);
	while (mid <= w->drawend)
	{
		w->texy = (int)w->texpos &(t->height - 1);
		w->texpos += w->step;
		if (mid < SCREENHEIGHT && x < SCREENWIDTH)
			w->addr[mid * w->line_length / 4 + x] = t->addr[w->texy * t->line_length / 4 + w->tex];
		mid += 1;
	}
}
//wallx : coordonnée sur x de la colonne que l'on veut utiliser
//tex : coordonnée sur x dans la texture
void	init_image(t_game *w, int mid, int x)
{
	if (w->side == 1)
		w->wallx = w->rayPosx + ((w->mapy - w->rayPosy + (1 - w->stepy)/2)/w->rayDiry)*w->rayDirx;
	else
		w->wallx = w->rayPosy + ((w->mapx - w->rayPosx + (1 - w->stepx)/2)/w->rayDirx)*w->rayDiry;
	w->wallx -= floor(w->wallx);
	if (w->side == 0 && w->rayDirx >= 0)
	{
		w->tex = (int)(w->wallx * w->texture_so->width);
		w->tex = w->texture_so->width - w->tex - 1;
		printf("wallx [%f] tex [%d]\n", w->wallx, w->tex);
		tex_loop(w, mid, x, w->texture_so);
	}
	else if (w->side == 0 && w->rayDirx < 0)
	{
		w->tex = (int)(w->wallx * w->texture_no->width);
		w->tex = w->texture_no->width - w->tex - 1;
		printf("wallx [%f] tex [%d]\n", w->wallx, w->tex);
		tex_loop(w, mid, x, w->texture_no);
	}
	else if (w->side == 1 && w->rayDiry < 0)
	{
		w->tex = (int)(w->wallx * w->texture_we->width);
		printf("wallx [%f] tex [%d]\n", w->wallx, w->tex);
		tex_loop(w, mid, x, w->texture_we);
	}
	else if (w->side == 1 && w->rayDiry >= 0)
	{
		w->tex = (int)(w->wallx * w->texture_ea->width);
		printf("wallx [%f] tex [%d]\n", w->wallx, w->tex);
		tex_loop(w, mid, x, w->texture_ea);
	}
}