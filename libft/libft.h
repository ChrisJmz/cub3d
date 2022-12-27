/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 11:07:57 by cmsjus            #+#    #+#             */
/*   Updated: 2022/12/27 21:13:53 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stddef.h>
# include <stdarg.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_itoa(int n);
void	ft_putchar(char c);
void	ft_putstr(const char *str);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
int     ft_strlen(const char *s);
char	*ft_strncpy(char *str, int nb);
char	*get_next_line(int fd);
char	*get_next_line2(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	ft_swap(char *s1, char *s2);
int		ft_content_pos_x(char **map, char c);
int		ft_content_pos_y(char **map, char c);
int		ft_printf(const char *str, ...);
int		ft_printf_s(va_list arg);
int		ft_printf_d(va_list arg);
int		ft_params(char flag, va_list arg);
size_t  ft_strlcpy(char *dest, const char *src, size_t dstsize);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
