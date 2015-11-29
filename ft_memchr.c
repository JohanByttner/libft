/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:33:47 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 20:46:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*result;

	i = 0;
	result = (unsigned char *)s;
	while (i < n)
	{
		if (result[i] == (unsigned char)c)
			return ((void *)&result[i]);
		i++;
	}
	return (0);
}
