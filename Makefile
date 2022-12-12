# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/12/12 14:43:57 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft/libft.a

FLAGS = -Werror -Wextra -Wall -g -I/usr/include -Imlx_linux

SRC =	srcs/test.c	\

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

clean:
	make -C libft clean
	make -C mlx_linux clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIBFT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re