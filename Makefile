# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/12/27 21:19:01 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
NAME2D = cub2d

LIBFT = libft/libft.a

FLAGS = -Werror -Wextra -Wall -I/usr/include -Imlx_linux 
SANITIZE = -g3 -fsanitize=address

SRC =	srcs/main.c	\
		srcs/filecheck.c	\
		srcs/parsing.c		\
		
SRC2D = 2D/test.c	\

OBJS = $(SRC:.c=.o)
OBJS2D = $(SRC2D:.c=.o)

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

2D: $(NAME2D)

$(NAME2D):	$(OBJS2D)
	make -C libft
	make -C mlx_linux
	$(CC) $(FLAGS) $(OBJS2D) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME2D)

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