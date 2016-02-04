/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:05 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 16:20:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_c;
	unsigned char	*src_c;
	size_t			diff;
	size_t			i;

	src_c = (unsigned char *)src;
	dest_c = (unsigned char *)dest;
	if (dest_c == src_c)
		return (dest);
	else if (dest_c < src_c)
		return (ft_memcpy(dest, src, n));
	diff = (size_t)(dest - src);
	diff = (diff > n ? n : diff);
	i = n;
	while (i > diff)
	{
		i -= diff;
		ft_memcpy(dest_c + i, src_c + i, diff);
	}
	if (i > 0)
		ft_memcpy(dest_c, src_c, i);
	return (dest);
}
