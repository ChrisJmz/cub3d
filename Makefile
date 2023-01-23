# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: skhali <skhali@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2023/01/23 19:10:34 by skhali           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
NAME2D = cub2d

FLAGS = -Werror -Wextra -Wall -I/usr/include -Imlx_linux 
SANITIZE = -g3 -fsanitize=address

SRC =	srcs/main.c	\
		srcs/filecheck.c	\
		srcs/parsing.c		\
		srcs/texture.c		\
		srcs/ft_error.c		\
		srcs/utils.c		\
		srcs/remap.c		\
		srcs/init.c			\
		srcs/init_texture.c	\
		srcs/errors.c		\
		srcs/events.c		\
		srcs/graphics.c		\
		srcs/mouvement.c	\
		srcs/raycasting.c	\
		srcs/colors.c		\
		
OBJS = $(SRC:.c=.o)

CC = gcc

RM = rm -rf

INC =   include

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFTFLAGS = -L ./libft -lft 

.c.o:
	$(CC) $(FLAGS) -I$(INC) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	make -C libft
	make -C mlx_linux
	$(CC) $(FLAGS) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

s: $(OBJS)
	make -C libft
	make -C mlx_linux
	$(CC) $(FLAGS) $(SANITIZE) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME)

clean:
	make -C libft clean
	make -C mlx_linux clean
	$(RM) $(OBJS)
	$(RM) $(OBJS2D)
	

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)
	$(RM) $(NAME2D)

re: fclean all

.PHONY: all clean fclean re