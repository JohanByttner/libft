/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:01 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 20:02:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest_c;
	unsigned char	*src_c;

	dest_c = (unsigned char *)dest;
	src_c = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_c[i] = src_c[i];
		i++;
	}
	return (dest);
}
