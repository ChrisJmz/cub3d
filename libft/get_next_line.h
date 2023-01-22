/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 00:31:20 by skhali            #+#    #+#             */
/*   Updated: 2023/01/23 00:31:21 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

#define BUFFER_SIZE 1
char	*get_next_line(int fd);
char	*ft_strgrab(char *str, char *buf);
char	*get_str(char *buf, char *str, int fd);
void	ft_remove_line(char *buf);
int		already_contain_next_line(char *buf);
int		ft_no_return(char *str);
#endif
