/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:50:58 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/16 00:46:36 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"

# define UP 122
# define DOWN 115
# define LEFT 113
# define RIGHT 100
# define ESC 65307

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363

# define screenWidth 1200	
# define screenHeight 600
# define ANGLE 0.60
# define PI 3.1414926535

typedef struct s_path
{
	int		f;
	int		c;
	int		no;
	int		so;
	int		we;
	int		ea;
	char	*f_path;
	char	*c_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
}	t_path;

typedef struct s_input{
	int			forward;
	int			back;
	int			left;
	int			right;
	int			rotate_left;
	int			rotate_right;
}	t_input;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_win;
	void	*mlx_image;

	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

	double	px;
	double	py;
	char	type;

	double	pdx;
	double	pdy;
	double	pa;

	double	planex;
	double	planey;
	
    void    *player;
	char	**map;
	int		col;
	int		row;
	char	**file;
	int		bmap;
	char	*line;
	struct s_path path;
	int		win_x;
	int		win_y;
	unsigned int	*walls[4];

	void	*texture_we;
	void	*texture_ea;
	void	*texture_no;
	void	*texture_so;


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

	int		hit;
	int		side;
	double	perpwalldist;

	int		lineheight;
	int		drawstart;
	int		drawend;

	double	speed;
	double	rot;
	int		move;
	double	strafel;
	double	strafer;

	double	cos;
	double	sin;

	t_input	*input;
}	t_game;

int filecheck(char *file);
int init_file(t_game *data, char *file);
int check_content(char **map, int i, int j);
int check_texture(char **map, t_path *path);
void    ft_error(char *msg);
int ft_strlenn(char *str);
int check_line(char *line);
void textpath(t_game *data);
int ft_strstrlen(char   **str);
char    **remap(char **map);
int check_first_and_last(char **map, int j, int i);
int check_in(char **map, int i, int j);
int check_walls(char **map, int j, int i);
int checkzero(char a, char b);
void	init_mlx(t_game *data);

void	check_direction(char **map, t_game *w);
int		ft_get_col(char **map);


//error handlers

int		simple_error_handler(char *str, t_game *map);
void	exit_error_handler(char *str, t_game *map);

//events

int		cross(t_game *game);
int		player_moves(int keycode, t_game *window);

//display graphics

void	put_pixel_to_image(t_game *window, int color, int x, int y );
void	draw_map(t_game *window);

//init values
void	init_direction(t_game *w, char direction);
void	init_plane(t_game *w, char direction);
int		image_init(t_game *window);

int		raycasting(t_game *window);
int		ft_key_press(int keycode, t_game *recup);
int		ft_key_release(int keycode, t_game *recup);
void	raycasting_init(t_game *window, int x);
void	rotate_moves(t_game *w);
void	simple_moves(t_game *w);
#endif