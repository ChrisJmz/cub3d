/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 15:52:56 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/11 16:17:21 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void    init_player(t_data *data)
// {
    
// }

void init_mlx(t_data *data)
{
    data->ptr = mlx_init();
    if (!data->ptr)
        return ;
    
}