/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:51:17 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/16 01:36:48 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	textpath(t_game *data)
{
	data->path.no_path = ft_substr(data->path.no_path, 0,
			ft_strlen(data->path.no_path) - 1);
	data->path.so_path = ft_substr(data->path.so_path, 0,
			ft_strlen(data->path.so_path) - 1);
	data->path.we_path = ft_substr(data->path.we_path, 0,
			ft_strlen(data->path.we_path) - 1);
	data->path.ea_path = ft_substr(data->path.ea_path, 0,
			ft_strlen(data->path.ea_path) - 1);
}

void	init_null(t_path *path)
{
	path->c = 0;
	path->f = 0;
	path->no = 0;
	path->so = 0;
	path->we = 0;
	path->ea = 0;
}

char	*get_colors(char **map, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		if (map[i][j] == c)
			return (ft_strdup(map[i] + 2));
		i++;
	}
	return (NULL);
}

int	get_path(char **map, t_path *path, int i)
{
	if (ft_strncmp(map[i], "NO ", 3) == 0)
		return (path->no_path = ft_strdup(map[i] + 3), path->no++, 0);
	else if (ft_strncmp(map[i], "SO ", 3) == 0)
		return (path->so_path = ft_strdup(map[i] + 3), path->so++, 0);
	else if (ft_strncmp(map[i], "EA ", 3) == 0)
		return (path->ea_path = ft_strdup(map[i] + 3), path->ea++, 0);
	else if (ft_strncmp(map[i], "WE ", 3) == 0)
		return (path->we_path = ft_strdup(map[i] + 3), path->we++, 0);
	else if (ft_strncmp(map[i], "F ", 2) == 0)
		return (path->f_path = get_colors(map, 'F'), path->f++, 0);
	else if (ft_strncmp(map[i], "C ", 2) == 0)
		return (path->c_path = get_colors(map, 'C'), path->c++, 0);
	return (1);
}

int	check_texture(char **map, t_path *path)
{
	int	i;

	i = 0;
	init_null(path);
	while (map[i] && path->no < 2)
	{
		if (get_path(map, path, i) == 0)
			;
		else if (ft_strncmp(map[i], "1", 1) != 0 && ft_strncmp(map[i], "0", 1)
			!= 0 && ft_strncmp(map[i], "\n", 1) != 0
			&& ft_strncmp(map[i], " ", 1) != 0)
			return (1);
		i++;
	}
	if (path->no != 1 || path->so != 1 || path->we != 1 || path->ea != 1
		|| path->f != 1 || path->c != 1)
		return (1);
	return (0);
}
