/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:30:42 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/14 02:31:58 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_strlenn(char *str)
{
    int i;

    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    return (i);
}

int ft_strstrlen(char   **str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char check_direction(char **map)
{
    int i;
    int j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while(map[i][j])
        {
            if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
                return (map[i][j]);
            j++;
        }
        i++;
    }
    return (0);
}

int checkzero(char a, char b)
{
	if (b == 'N' || b == 'W' || b == 'E' || b == 'S')
		return (0);
	else if (a == 'N' || a == 'W' || a == 'E' || a == 'S')
		return (0);
	else if (a - b == 0 || a - b == -1)
		return (0);
	return (1);
}
