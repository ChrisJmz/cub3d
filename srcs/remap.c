/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 15:32:49 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/22 23:54:30 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**alloc_map(char **map, int i)
{
	int		size;
	int		fsize;
	char	**new;

	size = 0;
	fsize = ft_strstrlen(map);
	new = malloc(sizeof(char *) * (fsize - i) + 1);
	if (!new)
		return (NULL);
	while (size < fsize - i - 1)
	{
		new[size] = ft_strdup(map[i + size + 1]);
		size++;
	}
	new[size] = '\0';
	size = -1;
	while (map[++size])
		free(map[size]);
	return (new);
}

char	**remap(char **map)
{
	char	**remap;
	int		i;

	i = 0;
	while (map[i] && check_line(map[i]) == 1)
		i++;
	if (check_line(map[i]) == 0)
		return (remap = alloc_map(map, i), free(map), remap);
	return (NULL);
}
