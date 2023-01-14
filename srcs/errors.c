#include "../include/cub3d.h"

int	simple_error_handler(char *str, t_game *map)
{
	free(map);
	ft_putstr_fd(str, 2);
	return (1);
}