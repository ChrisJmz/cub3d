/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 14:10:53 by skhali            #+#    #+#             */
/*   Updated: 2023/01/23 18:12:20 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	simple_error_handler(char *str, t_game *map)
{
	(void)map;
	ft_putstr_fd(str, 2);
	return (1);
}

void	exit_error_handler(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

void	ft_error2(char *str, t_game *w)
{
	free_split(w->map);
	free(w->path.c_path);
	free(w->path.f_path);
	free(w->path.no_path);
	free(w->path.so_path);
	free(w->path.we_path);
	free(w->path.ea_path);
	ft_error(str, w);
}
