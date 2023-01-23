/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 19:50:58 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/23 20:54:54 by cjimenez         ###   ########.fr       */
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

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100
# define ESC 65307

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363

# define SCREENWIDTH 600
# define SCREENHEIGHT 450

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

typedef struct s_texture{
	void	*image;

	int		width;
	int		height;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_texture;
//direction du vecteur sur x et y 
//longueur du rayon entre chaque intersection
//longueur du rayon
//Valeurs pour la DDA
//sur quelle case est la caméra
typedef struct s_game
{
	void			*mlx;
	void			*mlx_win;
	void			*mlx_image;

	int				*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;

	double			px;
	double			py;
	char			type;

	double			pdx;
	double			pdy;
	double			pa;

	double			planex;
	double			planey;

	void			*player;
	char			**map;
	int				col;
	int				row;
	char			**file;
	int				bmap;
	char			*line;
	t_path			path;
	int				win_x;
	int				win_y;
	unsigned int	*walls[4];

	double			camerax;
	double			rayposx;
	double			rayposy;
	double			raydirx;
	double			raydiry;

	int				mapx;
	int				mapy;

	double			sidedistx;
	double			sidedisty;

	double			deltadistx;
	double			deltadisty;

	int				stepx;
	int				stepy;

	int				hit;
	int				side;
	double			perpwalldist;

	int				lineheight;
	int				drawstart;
	int				drawend;

	double			speed;
	double			rot;
	int				move;
	double			strafel;
	double			strafer;

	double			cos;
	double			sin;

	t_input			*input;

	t_texture		*texture_we;
	t_texture		*texture_ea;
	t_texture		*texture_no;
	t_texture		*texture_so;
	t_texture		texture[4];

	double			wallx;
	int				tex;
	int				texy;
	double			texpos;
	double			step;

	int				texdir;

	int				cr;
	int				cg;
	int				cb;

	int				fr;
	int				fg;
	int				fb;
}	t_game;

/* PARSING */
int				filecheck(char *file);
int				init_file(t_game *data, char *file);
int				check_content(char **map, int i, int j);
int				check_texture(char **map, t_path *path);
void			ft_error(char *msg, t_game *w);
int				ft_strlenn(char *str);
int				check_line(char *line);
void			textpath(t_game *data);
int				ft_strstrlen(char **str);
char			**remap(char **map);
int				check_first_and_last(char **map, int j, int i);
int				check_in(char **map, int i, int j);
int				check_walls(char **map, int j, int i);
int				checkzero(char a, char b);
int				rgbCheck(t_path *path);

/* ERROR HANDLERS*/
int				simple_error_handler(char *str, t_game *map);
void			exit_error_handler(char *str);
void			ft_error2(char *str, t_game *data);

/* MLX EVENTS */
int				cross(t_game *game);
int				key_press(int keycode, t_game *recup);
int				key_release(int keycode, t_game *recup);

/*	INITIALISATION */
void			check_direction(char **map, t_game *w);
void			init_direction(t_game *w, char direction);
void			init_plane(t_game *w, char direction);
int				image_init(t_game *window);

/* RAYCASTING ALGORITHM*/
int				raycasting(t_game *window);
void			raycasting_init(t_game *window, int x);

/* MOVEMENTS*/
void			rotate_moves(t_game *w);
void			simple_moves(t_game *w);

/* GRAPHICS */
void			load_images(t_game *w);
void			init_image(t_game *w, int mid, int x);

/* FREE */
void			destroy_images(t_game *image, char *str);
void			close_win(t_game *w, char *str);
void			free_split(char	**str);

/* COLORS */
int				char_to_rgb(char *c, char *f, t_game *w);
unsigned long	creatergb(int r, int g, int b);
#endif