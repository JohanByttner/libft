/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:05 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 20:52:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*src_c;
	size_t			i;

	if (!(temp = malloc(sizeof(unsigned char *) * n)))
		return (0);
	i = 0;
	src_c = (unsigned char *)src;
	while (i < n)
	{
		temp[i] = src_c[i];
		i++;
	}
	i = 0;
	src_c = (unsigned char *)dest;
	while (i < n)
	{
		src_c[i] = temp[i];
		i++;
	}
	free(temp);
	return (dest);
}
