/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:05 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/02 14:39:33 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*ptr;
	size_t			i;

	if (!(temp = malloc(sizeof(unsigned char) * n)))
		return (0);
	i = 0;
	ptr = (unsigned char *)src;
	while (i < n)
	{
		temp[i] = ptr[i];
		i++;
	}
	i = 0;
	ptr = (unsigned char *)dest;
	while (i < n)
	{
		ptr[i] = temp[i];
		i++;
	}
	free(temp);
	return ((void *)ptr);
}
