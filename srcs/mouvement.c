/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouvement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:41:27 by skhali            #+#    #+#             */
/*   Updated: 2023/01/16 01:18:12 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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

int	check_wall(int x, int y, t_game *window)
{
	if (window->map[x][y] != '1')
		return (1);
	else
		return (0);
}

void	simple_moves(t_game *w)
{
	if (w->input->forward == 1)
	{
		if (check_wall(w->rayPosx + (w->pdx * w->speed), w->rayPosy, w))
			w->rayPosx += w->pdx * w->speed;
		if (check_wall(w->rayPosx, w->rayPosy + (w->pdy * w->speed), w))
			w->rayPosy += w->pdy * w->speed;
	}
	if (w->input->back == 1)
	{
		if (check_wall(w->rayPosx - w->pdx * (w->speed), w->rayPosy, w))
			w->rayPosx -= w->pdx * w->speed;
		if (check_wall(w->rayPosx, w->rayPosy - w->pdy * (w->speed), w))
			w->rayPosy -= w->pdy * w->speed;
	}
	if (w->input->left == 1)
	{
		if (check_wall(w->rayPosx - w->pdy * (w->speed), w->rayPosy, w))
			w->rayPosx -= w->pdy * w->speed;
		if (check_wall(w->rayPosx, w->rayPosy + w->pdx * (w->speed), w))
			w->rayPosy += w->pdx * w->speed;
	}
}

void	rotate(t_game *w, int sens)
{
	double	oldplanx;
	double	olddirx;

	oldplanx = w->planex;
	olddirx = w->pdx;
	w->pdx = w->pdx * cos(sens * w->rot / 2)
		- w->pdy * sin(sens * w->rot / 2);
	w->pdy = olddirx * sin(sens * w->rot / 2)
		+ w->pdy * cos(sens * w->rot / 2);
	w->planex = w->planex * cos(sens * w->rot / 2)
		- w->planey * sin(sens * w->rot / 2);
	w->planey = oldplanx * sin(sens * w->rot / 2)
		+ w->planey * cos(sens * w->rot / 2);
}

void	rotate_moves(t_game *w)
{
	if (w->input->right == 1)
	{
		if (check_wall(w->rayPosx + w->pdy * (w->speed), w->rayPosy, w))
			w->rayPosx += w->pdy * w->speed;
		if (check_wall(w->rayPosx, w->rayPosy - w->pdx * (w->speed), w))
			w->rayPosy -= w->pdx * w->speed;
	}
	if (w->input->rotate_right == 1)
		rotate(w, -1);
	if (w->input->rotate_left == 1)
		rotate(w, 1);
}
