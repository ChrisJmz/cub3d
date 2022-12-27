/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 17:51:17 by cjimenez          #+#    #+#             */
/*   Updated: 2022/12/26 18:23:05 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int init_textures(t_data *data, int nb_data, int i, int index)
{
    while (data->file[i++] && nb_data < 6)
    {
        index = 0;
        data->line = data->file[i];
        if (ft_strncmp(&data->))
    }
}

int check_texture(t_data *data)
{
    int nb_data;
    int fd;
    
    nb_data = 0;
    data->bmap = init_textures(data, nb_data, -1, 0);
}