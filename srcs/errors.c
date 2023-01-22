/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:10:53 by skhali            #+#    #+#             */
/*   Updated: 2023/01/18 00:05:12 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	simple_error_handler(char *str, t_game *map)
{
	free(map);
	ft_putstr_fd(str, 2);
	return (1);
}

void	exit_error_handler(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}
