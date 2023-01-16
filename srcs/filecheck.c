/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filecheck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:06:15 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/16 01:42:56 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] && i < ft_strlen(line) - 2)
	{
		if (line[i] != '1' && line[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	count_line(char *file)
{
	int		fd;
	int		nb_line;
	char	*tmp;

	nb_line = 0;
	fd = open(file, O_RDONLY);
	tmp = get_next_line(fd);
	nb_line++;
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		nb_line++;
	}
	free(tmp);
	return (nb_line);
}

int	filecheck(char *file)
{
	int	i;

	i = ft_strlen(file);
	if (file[i - 4] != '.' || file[i - 3] != 'c'
		|| file[i - 2] != 'u' || file[i - 1] != 'b')
		return (1);
	return (0);
}

char	**size_map(char *file)
{
	char	**map;
	int		i;
	int		size;
	int		fd;

	i = 0;
	fd = open(file, O_RDONLY);
	size = count_line(file);
	map = malloc(sizeof(char *) * size + 1);
	if (!map)
		return (NULL);
	while (i < size - 1)
	{
		map[i] = get_next_line(fd);
		i++;
	}
	map[i] = '\0';
	close (fd);
	return (map);
}

int	init_file(t_game *data, char *file)
{
	if (filecheck(file))
		return (printf(".cub file supported only\n"), 1);
	data->map = size_map(file);
	if (check_texture(data->map, &data->path) == 1)
		ft_error("Error in texture");
	textpath(data);
	data->map = remap(data->map);
	if (check_first_and_last(data->map, 0, 0) == 1)
		ft_error("Error in first or last line");
	if (check_in(data->map, 0, 0) == 1)
		ft_error("Error inside");
	if (check_content(data->map, 0, 0) == 1)
		ft_error("Error in content");
	if (check_walls(data->map, 1, 0) == 1)
		ft_error("Error with walls");
	return (0);
}
