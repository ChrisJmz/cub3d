/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:50:58 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/06 18:02:01 by cjimenez         ###   ########.fr       */
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

typedef struct s_text
{
	int		f;
	int		c;
	int		no;
	int		so;
	int		we;
	int		ea;
	char	*f_img;
	char	*c_img;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_text;

typedef struct	s_data
{
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    void	*ptr;
	void	*win;
    void    *player;
    float   px;
    float   py;
	char	**map;
	int		col;
	int		row;
	char	**file;
	int		bmap;
	char	*line;
	struct s_text text;
}	t_data;

int filecheck(char *file);
int init_file(t_data *data, char *file);
int check_content(char **map, int i, int j);
int check_texture(char **map, t_text *text);
void    ft_error(char *msg);
int ft_strlenn(char *str);
int check_line(char *line);
int ft_strstrlen(char   **str);
char    **remap(char **map);
int check_first_and_last(char **map, int j, int i);
int check_in(char **map, int i, int j);

#endif