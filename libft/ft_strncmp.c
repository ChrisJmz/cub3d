/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skhali <skhali@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 18:16:56 by cjimenez          #+#    #+#             */
/*   Updated: 2023/01/23 19:08:17 by skhali           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (n == 0)
		return (0);
	a = 0;
	while (a < n - 1 && s1[a] && s2[a] && (s1[a] == s2[a]))
		a++;
	return ((unsigned char)s1[a] - (unsigned char)s2[a]);
}
