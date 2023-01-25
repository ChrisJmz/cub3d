# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 11:10:56 by cmsjus            #+#    #+#              #
#    Updated: 2023/01/25 00:26:30 by cjimenez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS =	ft_atoi.c 				\
		ft_isdigit.c			\
		ft_itoa.c 				\
		ft_putchar.c 			\
		ft_putstr.c				\
		ft_strchr.c				\
		ft_split.c				\
		ft_strdup.c 			\
		ft_strlen.c 			\
		ft_strncpy.c 			\
		ft_swap.c				\
		get_next_line.c			\
		get_next_line_utils.c	\
		ft_printf.c				\
		ft_printf_s.c			\
		ft_printf_d.c			\
		ft_params.c				\
		ft_strncmp.c			\
		ft_strlcpy.c			\
		ft_substr.c				\
		ft_putstr_fd.c			\
		ft_memset.c				\

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re
