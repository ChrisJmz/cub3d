/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:01:44 by skhali            #+#    #+#             */
/*   Updated: 2023/01/16 01:43:34 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	cross(t_game *game)
{
	(void)game;
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
