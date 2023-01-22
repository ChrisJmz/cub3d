/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:01:44 by skhali            #+#    #+#             */
/*   Updated: 2023/01/23 00:24:34 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_split(char	**str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

int	cross(t_game *game)
{
	destroy_images(game, "");
	free_split(game->map);
	free(game->path.c_path);
	free(game->path.f_path);
	free(game->path.no_path);
	free(game->path.so_path);
	free(game->path.we_path);
	free(game->path.ea_path);
	free(game);
	exit(0);
	return (0);
}

int	key_press(int keycode, t_game *w)
{
	if (keycode == UP)
		w->input->forward = 1;
	else if (keycode == DOWN)
		w->input->back = 1;
	else if (keycode == LEFT)
		w->input->left = 1;
	else if (keycode == RIGHT)
		w->input->right = 1;
	else if (keycode == ROTATE_LEFT)
		w->input->rotate_left = 1;
	else if (keycode == ROTATE_RIGHT)
		w->input->rotate_right = 1;
	return (1);
}

int	key_release(int keycode, t_game *w)
{
	if (keycode == UP)
		w->input->forward = 0;
	else if (keycode == DOWN)
		w->input->back = 0;
	else if (keycode == LEFT)
		w->input->left = 0;
	else if (keycode == RIGHT)
		w->input->right = 0;
	else if (keycode == ROTATE_LEFT)
		w->input->rotate_left = 0;
	else if (keycode == ROTATE_RIGHT)
		w->input->rotate_right = 0;
	return (1);
}
