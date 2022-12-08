/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjimenez <cjimenez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:14:48 by cjimenez          #+#    #+#             */
/*   Updated: 2022/02/21 18:01:57 by cjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_params(char flag, va_list arg)
{
	int	r;

	r = 0;
	if (flag == 's')
		r = ft_printf_s(arg);
	else if (flag == 'd')
		r = ft_printf_d(arg);
	va_end(arg);
	return (r);
}
