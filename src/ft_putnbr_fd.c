/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 16:19:20 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 21:46:23 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** The string pointer is to prevent a memory leak.
** ft_itoa allocates memory on the heap.
*/

static inline void	ft_itoa_local(int value, char *nbr)
{
	int		magnitude;
	int		digit;
	int		sign;

	digit = value;
	magnitude = 0 + !(value);
	sign = ((value < 0) ? 1 : 0);
	while (digit != 0)
	{
		magnitude++;
		digit /= 10;
	}
	nbr[0] = '-';
	while (magnitude > 0)
	{
		digit = value % 10;
		nbr[--magnitude + sign] = '0' + (digit < 0 ? -digit : digit);
		value = (value - digit) / 10;
	}
}

void				ft_putnbr_fd(int n, int fd)
{
	char	str[sizeof(int) * 4 + 2];

	ft_memset(str, 0, sizeof(int) * 4 + 2);
	ft_itoa_local(n, str);
	ft_putstr_fd(str, fd);
}
