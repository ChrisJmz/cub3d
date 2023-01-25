/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:01:17 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/24 23:23:40 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	*window;

	window = malloc(sizeof(t_game));
	if (!window)
		return (printf("Malloc error.\n"), 1);
	if (ac == 2)
	{
		init_file(window, av[1]);
		image_init(window);
		mlx_hook(window->mlx_win, 33, 0, cross, window);
		mlx_hook(window->mlx_win, 2, 3, key_press, window);
		mlx_loop_hook(window->mlx, raycasting, window);
		mlx_hook(window->mlx_win, 3, 3, key_release, window);
		mlx_loop(window->mlx);
	}
	else
	{
		free(window);
		return (printf("Usage: ./cub3d <map>\n"), 1);
	}
}
