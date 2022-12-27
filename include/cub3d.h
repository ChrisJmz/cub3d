/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:50:58 by cjimenez          #+#    #+#             */
/*   Updated: 2022/12/27 22:01:14 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <math.h>
#include "../libft/libft.h"
#include "../mlx_linux/mlx.h"
#define PI 3.1415926535

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*mlx;
	void	*mlx_win;
    void    *player;
    float   px;
    float   py;
    // int map;
	char	**map;
	int		col;
	int		row;
	char	**file;
	int		bmap;
	char	*line;
}				t_data;

int filecheck(char *file);
int init_file(t_data *data, char *file);
int check_content(char **map, int i, int j);

#endif