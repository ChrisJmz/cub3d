/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:01:17 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/11 16:18:15 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_data data;
    int i =0;

    if (ac == 2)
    {
        init_file(&data, av[1]);
        while(data.map[i])
            printf("%s", data.map[i++]);
        // init_mlx(&data);
        
        printf("\nnorth : [%s]\n", data.text.no_path);
        printf("south : [%s]\n", data.text.so_path);
        printf("west : [%s]\n", data.text.we_path);
        printf("east : [%s]\n", data.text.ea_path);
    }
    else 
       return (printf("Usage: ./cub3d <map>\n"), 1);
}