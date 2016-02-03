/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 16:24:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 11:42:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	int		sign;
	int		res;

	if (!nptr)
		return (0);
	sign = 1;
	res = 0;
	while (*nptr == ' ' || *nptr == '\t' || *nptr == '\n'
			|| *nptr == '\r' || *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		sign = 44 - *nptr++;
	while (*nptr == '0')
		nptr++;
	while ('0' <= *nptr && *nptr <= '9')
	{
		res *= 10;
		res += (*nptr++ - '0') * sign;
	}
	return (res);
}
