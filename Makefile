SRCS =	srcs/main.c \
		srcs/errors.c \
		srcs/events.c \
		srcs/init.c \
		srcs/mouvement.c \
		srcs/graphics.c \
		srcs/raycasting.c \

OBJS =	objs/main.o \
		objs/errors.o \
		objs/events.o \
		objs/init.o \
		objs/mouvement.o \
		objs/graphics.o \
		objs/raycasting.o \

NAME = cub3D

CC = gcc

INC = include/

RM = rm -rf

CFLAGS = #-Wall -Werror -Wextra #-g3 -fsanitize=address

MLXFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFLAGS = -L libft -lft

all : ${NAME}

objs/%.o : srcs/%.c
	mkdir -p ./objs
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@


%.o : %.c
	$(CC) $(CFLAGS) -I${INC} -c $< -o $@

${NAME} : ${OBJS} $(LIB)
	make -C ./libft
	make -C ./mlx_linux
	$(CC) $(CFLAGS) ${OBJS} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME}

${NAME_BONUS} : ${OBJS_B}
	make -C ./libft
	make -C ./mlx_linux
	$(CC) $(CFLAGS) ${OBJS_B} -D LINUX ${MLXFLAGS} ${LIBFLAGS} -o ${NAME_BONUS}


clean:
		$(RM) ${OBJS} $(OBJ_B)
		$(RM) ./objs
		make clean -C ./mlx_linux
		make clean -C ./libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		$(RM) ./mlx_linux/libmlx_Linux.a
		$(RM) ./mlx_linux/libmlx.a
		$(RM) ./libft/libft.a

malloc_test:	$(OBJS) ./libft/libft.a ./mlx_linux/libmlx_Linux.a
				$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} $(MLXFLAGS) ./libft/libft.a ./mlx_linux/libmlx_Linux.a -L. -lmallocator

re:	fclean all

.PHONY:        all clean fclean re