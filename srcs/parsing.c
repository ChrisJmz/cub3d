/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:38:28 by cjimenez          #+#    #+#             */
/*   Updated: 2022/12/28 17:29:57 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_content(char **map, int i, int j)
{
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] != '1' && map[i][j] && '0' && map[i][j] != 'N' && map[i][j] != '\n' && map[i][j] != 'S' && map[i][j] != 'E' && map[i][j] != 'W')
                {printf("[%s]", map[i]);return (1);}
            j++;
        }
        i++;
    }
    return (0);
}
