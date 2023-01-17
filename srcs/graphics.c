/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:37:45 by skhali            #+#    #+#             */
/*   Updated: 2023/01/17 12:56:28 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	get_addr(t_texture *t, t_game *w)
{
	t->addr = (int *)mlx_get_data_addr(w->mlx_image,
			&w->bits_per_pixel, &w->line_length, &w->endian);
}

/*static void	destroy_images_p1(t_game *image)
{
	if (image->mlx)
	{
		if (image->wall_aright)
			mlx_destroy_image(image->mlx, image->wall_aright);
		if (image->wall_bright)
			mlx_destroy_image(image->mlx, image->wall_bright);
		if (image->exit)
			mlx_destroy_image(image->mlx, image->exit);
		if (image->item)
			mlx_destroy_image(image->mlx, image->item);
		if (image->wall_right)
			mlx_destroy_image(image->mlx, image->wall_right);
		if (image->wall_left)
			mlx_destroy_image(image->mlx, image->wall_left);
		if (image->wall_up)
			mlx_destroy_image(image->mlx, image->wall_up);
		if (image->wall_down)
			mlx_destroy_image(image->mlx, image->wall_down);
		if (image->player)
			mlx_destroy_image(image->mlx, image->player);
		if (image->ground)
			mlx_destroy_image(image->mlx, image->ground);
		if (image->wall)
			mlx_destroy_image(image->mlx, image->wall);
	}
}

void	destroy_images(t_image *image, t_map *map, char *str)
{
	destroy_images_p1(image);
	mlx_destroy_window(image->mlx, image->mlx_win);
	mlx_destroy_display(image->mlx);
	free(image->mlx);
	exit_error_handler_map(str, map);
}*/

/*static void	load_exit_item(t_image *image, t_map *map, int width, int height)
{
	image->wall_left = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_left.xpm", &width, &height);
	if (!image->wall_left)
		destroy_images(image, map, "Mauvais chargement des images.\n");
	image->wall_right = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_right.xpm", &width, &height);
	if (!image->wall_right)
		destroy_images(image, map, "Mauvais chargement des images.\n");
	image->item = mlx_xpm_file_to_image(image->mlx, "sprites/flower.xpm",
			&width, &height);
	if (!image->item)
		destroy_images(image, map, "Mauvais chargement des images.\n");
	image->exit = mlx_xpm_file_to_image(image->mlx, "sprites/exit.xpm",
			&width, &height);
	if (!image->exit)
		destroy_images(image, map, "Mauvais chargement des images.\n");
	image->wall_bright = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_b_down_right.xpm", &width, &height);
	if (!image->wall_bright)
		destroy_images(image, map, "Mauvais chargement des images.\n");
	image->wall_aright = mlx_xpm_file_to_image(image->mlx,
			"sprites/wall_b_down_leftt.xpm", &width, &height);
	if (!image->wall_aright)
		destroy_images(image, map, "Mauvais chargement des images.\n");
}*/

static void	load_wall(t_game *w, int width, int height)
{
	w->texture_no->image = mlx_xpm_file_to_image(w->mlx, w->path.no_path,
			&w->texture_no->width, &w->texture_no->height);
	//if (!w->texture_no)
	//	destroy_images(w, "Mauvais chargement des images.\n");
	w->texture_so->image = mlx_xpm_file_to_image(w->mlx, w->path.so_path,
			&w->texture_so->width, &w->texture_so->height);
	//if (!w->texture_so)
	//	destroy_images(w, "Mauvais chargement des images.\n");
		w->texture_so->addr = (int *)mlx_get_data_addr(w->texture_so->image,
			&w->texture_so->bits_per_pixel, &w->texture_so->line_length,
			&w->texture_so->endian);
	w->texture_ea->image = mlx_xpm_file_to_image(w->mlx, w->path.ea_path,
			&w->texture_ea->width, &w->texture_ea->height);
	//if (!w->texture_ea)
	//	destroy_images(w, "Mauvais chargement des images.\n");
	w->texture_we->image = mlx_xpm_file_to_image(w->mlx,
			w->path.we_path, &w->texture_we->width, &w->texture_we->height);
	//if (!w->texture_we)
	//	destroy_images(w, "Mauvais chargement des images.\n");
	get_addr(w->texture_no, w);
	get_addr(w->texture_so, w);
	get_addr(w->texture_ea, w);
	get_addr(w->texture_we, w);
}

void	load_images(t_game *w)
{
	int	height;
	int	width;

	height = 0;
	width = 0;
	load_wall(w, width, height);
}

//wallx : coordonnée sur x de la colonne que l'on veut utiliser
//tex : coordonnée sur x dans la texture
void	init_image(t_game *w)
{
	if (w->side == 1)
		w->wallx = w->rayPosx + ((w->mapy - w->rayPosy + (1 - w->stepy)/2)/w->rayDiry)*w->rayDirx;
	else
		w->wallx = w->rayPosy + ((w->mapx - w->rayPosx + (1 - w->stepx)/2)/w->rayDirx)*w->rayDiry;
	w->wallx -= floor(w->wallx);
	/*if (w->side == 0 && w->rayDirx < 0)
	{
		
	}*/
}
