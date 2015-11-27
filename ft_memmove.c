/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:05 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:34:07 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	UCHAR	*temp;
	UCHAR	*src_c;
	size_t	i;

	temp = malloc(sizeof(UCHAR *) * n);
	i = 0;
	src_c = (UCHAR *)src;
	while (i < n)
	{
		temp[i] = src_c[i];
		i++;
	}
	src_c = (UCHAR *)dest;
	while (--i > 0)
		src_c[i] = temp[i];
	free(temp);
	return (dest);
}
