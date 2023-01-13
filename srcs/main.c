/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:53:16 by skhali            #+#    #+#             */
/*   Updated: 2023/01/13 14:42:56 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(void)
{
	t_game	*window;

	window = malloc(sizeof(t_game));
	image_init(window);
	mlx_hook(window->mlx_win, 33, 0, cross, window);
	mlx_hook(window->mlx_win, KeyPress, KeyPressMask, player_moves, window);
	mlx_loop_hook(window->mlx, raycasting, window);
	//mlx_hook(window->mlx_win, 3, 1L << 1, ft_key_release, window);
	mlx_loop(window->mlx);
	return (1);
}
