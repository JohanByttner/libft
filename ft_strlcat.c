/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:59 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 21:53:30 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_length;
	size_t	i;

	dst_length = ft_strlen(dst);
	i = 0;
	if (size <= dst_length)
		return (size + ft_strlen(src));
	while (i < size - dst_length - 1 && src[i] != '\0')
	{
		dst[dst_length + i] = src[i];
		i++;
	}
	dst[dst_length + i] = '\0';
	return (dst_length + ft_strlen(src));
}
