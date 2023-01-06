/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:51:17 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/06 15:44:08 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void init_null(t_text *text)
{
    text->c = 0;
    text->f = 0;
    text->no = 0;
    text->so = 0;
    text->we = 0;
    text->ea = 0;
}

char    *get_colors(char **map, char c)
{
    int i;
    int j;
    
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

int get_path(char **map, t_text *text, int i)
{
    if (ft_strncmp(map[i], "NO ", 3) == 0)
        return (text->no_path = ft_strdup(map[i] + 3), text->no++, 0);
    else if (ft_strncmp(map[i], "SO ", 3) == 0)
        return (text->so_path = ft_strdup(map[i] + 3), text->so++, 0);
    else if (ft_strncmp(map[i], "EA ", 3) == 0)
        return (text->ea_path = ft_strdup(map[i] + 3), text->ea++, 0);
    else if (ft_strncmp(map[i], "WE ", 3) == 0)
        return (text->we_path = ft_strdup(map[i] + 3), text->we++, 0);
    else if (ft_strncmp(map[i], "F ", 2) == 0)
        return (text->f_img = get_colors(map, 'F'),text->f++, 0);
    else if (ft_strncmp(map[i], "C ", 2) == 0)
        return (text->c_img = get_colors(map, 'C'),text->c++, 0);
    return (1);
}

int check_texture(char **map, t_text *text)
{
    int i;

    i = 0;
    init_null(text);
    while (map[i] && text->no < 2)
    {
        if (get_path(map, text, i) == 0)
            ;
        else if (ft_strncmp(map[i], "1", 1) != 0 && ft_strncmp(map[i], "0", 1) != 0 && ft_strncmp(map[i], "\n", 1) != 0 && ft_strncmp(map[i], " ", 1) != 0)
            return (1);
        i++;
    }
    if (text->no != 1 || text->so != 1 || text->we != 1 || text->ea != 1 || text->f != 1 || text->c != 1)
        return (1);
    return (0);
    
}