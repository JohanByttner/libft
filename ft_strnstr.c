/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:35:34 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:37:18 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*start;

	start = 0;
	while (*big != '\0' && len-- > 0)
	{
		if (*little == *big || little == '\0')
			start = start ? start : big;
		else
		{
			little = start;
			start = 0;
		}
		if (*little == '\0')
			break ;
		little++;
		big++;
	}
	start = *little ? 0 : start;
	return ((char *)start);
}
