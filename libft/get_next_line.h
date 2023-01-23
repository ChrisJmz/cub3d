/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:08:52 by skhali            #+#    #+#             */
/*   Updated: 2023/01/23 19:08:55 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define  GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define BUFFER_SIZE 1

char	*ft_gnlstrjoin(char *s1, char *s2);
int		ft_gnlstrlen(char *str);
char	*ft_gnlstrdup(char *src);
char	*create_line(char *str);
char	*clean_stock(char *str);
int		test_n(char *str);
char	*get_next_line(int fd);
int		formate_line(char *str);
void	*pmalloc(int size);

#endif