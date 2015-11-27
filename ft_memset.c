/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:10 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:34:11 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	UCHAR	ch;
	UCHAR	*smem;

	i = 0;
	ch = (unsigned char)c;
	smem = (unsigned char*)s;
	while (i < n)
	{
		smem[i] = ch;
	}
	return (s);
}
