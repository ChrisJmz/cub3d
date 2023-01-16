/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:38:28 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/16 01:41:25 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(char **map, int j, int i)
{
	while (map[j])
	{
		while (map[j][i] && i <= ft_strlenn(map[j]))
		{
			if (map[j][i] == '0' && i > ft_strlenn(map[j - 1]))
				return (1);
			else if (map[j][i] == '0' && i > ft_strlenn(map[j + 1]))
				return (1);
			else if (map[j][i] == '0' && checkzero(map[j][i], map[j - 1][i]))
				return (1);
			else if (map[j][i] == '0' && checkzero(map[j][i], map[j + 1][i]))
				return (1);
			else if (map[j][i] == '0' && checkzero(map[j][i], map[j][i + 1]))
				return (1);
			else if (map[j][i] == '0' && checkzero(map[j][i], map[j][i - 1]))
				return (1);
			i++;
		}
		i = 0;
		j++;
	}
	return (0);
}

int	check_player(char **map, int i, int j)
{
	int	player;

	player = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				player++;
			j++;
		}
		i++;
	}
	return (player);
}

int	check_first_and_last(char **map, int j, int i)
{
	if (!*map)
		exit(0);
	while (map[j][i] && i < ft_strlen(map[j]) - 2)
	{
		if (map[j][i] != '1' && map[j][i] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (map[j])
		j++;
	j -= 1;
	while (map[j][i] && i <= ft_strlenn(map[j]) - 1)
	{
		if (map[j][i] != '1' && map[j][i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_in(char **map, int i, int j)
{
	while (map[i])
	{
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (1);
		i++;
	}
	i = 0;
	while (map[i])
	{
		if (map[i][ft_strlen(map[i]) - 2] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_content(char **map, int i, int j)
{
	if (check_player(map, 0, 0) != 1)
		return (1);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != '0'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != 'W'
					&& map[i][j] != 'E' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
