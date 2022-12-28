/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:51:17 by cjimenez          #+#    #+#             */
/*   Updated: 2022/12/28 17:25:58 by cjimenez         ###   ########.fr       */
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
        return (text->f++, 0);
    else if (ft_strncmp(map[i], "C ", 2) == 0)
        return (text->c++, 0);
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
        else if (ft_strncmp(map[i], "1", 1) != 0 && ft_strncmp(map[i], "0", 1) != 0 && ft_strncmp(map[i], "\n", 1) != 0 && ft_strncmp(map[i], " ", 1) != 0){
            printf("{%s}", map[i]);return (1);}
        i++;
    }
    if (text->no != 1)
        return (1);
    return (0);
    
}