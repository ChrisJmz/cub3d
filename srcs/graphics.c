/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:37:45 by skhali            #+#    #+#             */
/*   Updated: 2023/01/23 18:13:14 by skhali           ###   ########.fr       */
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

void	destroy_images(t_game *image, char *str)
{
	destroy_images_p1(image);
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
	if (image->mlx_win)
		mlx_destroy_window(image->mlx, image->mlx_win);
	if (image->mlx_image)
		mlx_destroy_image(image->mlx, image->mlx_image);
	if (image->mlx)
	{
		mlx_destroy_display(image->mlx);
		free(image->mlx);
	}
	simple_error_handler(str, image);
}

static int	load_wall(t_game *w)
{
	w->texture_no->image = mlx_xpm_file_to_image(w->mlx, w->path.no_path,
			&(w->texture_no->width), &(w->texture_no->height));
	if (!w->texture_no->image)
		return (close_win(w, "Mauvais chargement de la tnord.\n"), exit(1), 1);
	w->texture_so->image = mlx_xpm_file_to_image(w->mlx, w->path.so_path,
			&(w->texture_so->width), &(w->texture_so->height));
	if (!w->texture_so->image)
		return (close_win(w, "Mauvais chargement de la tsud.\n"), exit(1), 1);
	w->texture_ea->image = mlx_xpm_file_to_image(w->mlx, w->path.ea_path,
			&(w->texture_ea->width), &(w->texture_ea->height));
	if (!w->texture_ea->image)
		return (close_win(w, "Mauvais chargement de la test.\n"), exit(1), 1);
	w->texture_we->image = mlx_xpm_file_to_image(w->mlx,
			w->path.we_path, &(w->texture_we->width), &(w->texture_we->height));
	if (!w->texture_we->image)
		return (close_win(w, "Mauvais chargement de la touest.\n"), exit(1), 1);
	get_addr(w->texture_no);
	get_addr(w->texture_so);
	get_addr(w->texture_ea);
	get_addr(w->texture_we);
	return (0);
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
