/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 23:53:21 by skhali            #+#    #+#             */
/*   Updated: 2023/01/13 19:53:59 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include "/usr/include/X11/X.h"
#include <math.h>

# define UP 122
# define DOWN 115
# define LEFT 113
# define RIGHT 100
# define ESC 65307

#define ROTATE_LEFT 65361
#define ROTATE_RIGHT 65363

#define mapWidth 24
#define mapHeight 24
#define screenWidth 1920
#define screenHeight 1080
#define cubeWidth screenWidth/24
#define cubeHeight  screenHeight/24
#define ANGLE 0.60
#define PI 3.1414926535

typedef struct s_game{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_image;

	int		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	
	int			px;
	int			py;

	double			pdx;
	double			pdy;
	double			pa;

	double			planex;
	double			planey;

	double			camerax;
	double		rayPosx;
	double		rayPosy;
	double			rayDirx;
	double			rayDiry;
	//Valeurs pour la DDA
	//sur quelle case est la caméra
	int			mapx;
	int			mapy;
	//longueur du rayon
	double		sideDistx;
	double		sideDisty;
	//longueur du rayon entre chaque intersection
	double			deltadistx;
	double			deltadisty;
	//direction du vecteur sur x et y 
	int			stepx;
	int			stepy;

	int			hit;
	int			side;
	double			perpwalldist;

	int			lineheight;
	int			drawstart;
	int			drawend;

	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;

	int			speed;
}				t_game;

int	player_moves(int key, t_game *window);
//error handlers

int	simple_error_handler(char *str, t_game *map);

//events

int	cross(t_game *game);
int	player_moves(int keycode, t_game *window);

//display graphics

void    put_pixel_to_image(t_game *window, int color, int x, int y );
void	draw_player(int px, int py, t_game *window, int color, int width, int height);
void	draw_map(t_game *window);

//init values
void init_direction(t_game *w, char direction);
void init_plane(t_game *w, char direction);
int image_init(t_game *window);

int raycasting(t_game *window);
#endif