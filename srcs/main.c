/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:01:17 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/15 20:58:36 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_game *window;
    // int i = -1;

    window = malloc(sizeof(t_game));
    if (ac == 2)
    {
        init_file(window, av[1]);
        // while(window->map[++i])
        //     printf("%s", window->map[i]);
        image_init(window);
	mlx_hook(window->mlx_win, 33, 0, cross, window);
	mlx_hook(window->mlx_win, 2, 3, ft_key_press, window);
	mlx_loop_hook(window->mlx, raycasting, window);
	mlx_hook(window->mlx_win, 3, 3, ft_key_release, window);
        //mlx_hook(window->mlx_win, 3, 1L << 1, ft_key_release, window);
        // printf("\nnorth path found: [%s]\n", window->path.no_path);
        // printf("south path found: [%s]\n", window->path.so_path);
        // printf("west path found: [%s]\n", window->path.we_path);
        // printf("east path found: [%s]\n", window->path.ea_path);
        mlx_loop(window->mlx);
    }
    else 
       return (printf("Usage: ./cub3d <map>\n"), 1);
}