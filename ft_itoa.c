/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:07:40 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 22:34:34 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Returns a null pointer on memory failure
*/

char	*ft_itoa(int value)
{
	int		magnitude;
	int		digit;
	char	*nbr;
	int		sign;

	if (!value)
		return ("0");
	digit = value;
	magnitude = 0;
	sign = ((value < 0) ? 1 : 0);
	while (digit != 0)
	{
		magnitude++;
		digit /= 10;
	}
	if (!(nbr = (char*)ft_memalloc(sizeof(char) * (magnitude + 1 + sign))))
		return (0);
	nbr[0] = '-';
	while (magnitude >= 0 + sign)
	{
		digit = value % 10;
		nbr[--magnitude + sign] = '0' + (digit < 0 ? -digit : digit);
		value = (value - digit) / 10;
	}
	return (nbr);
}
