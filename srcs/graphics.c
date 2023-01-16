/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 01:37:45 by skhali            #+#    #+#             */
/*   Updated: 2023/01/16 01:38:27 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_pixel_to_image(t_game *window, int color, int x, int y )
{
	window->addr = (int *)mlx_get_data_addr(window->mlx_image,
			&window->bits_per_pixel, &window->line_length, &window->endian);
	window->addr[y * window->line_length / 4 + x] = color;
}
