/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:10 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/06 02:12:01 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#define MIN_WORDS 4
#if UINT_MAX > 0xffffffff
# define FT_MEMSET_SHIFT_32 32
#else
# define FT_MEMSET_SHIFT_32 0
#endif

void	*ft_memset(void *s, int c, size_t n)
{
	register size_t			i;
	register unsigned int	ch;
	register unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)s;
	if (n < MIN_WORDS * sizeof(unsigned int))
		while (i < n)
			arr[i++] = (unsigned char)c;
	else
	{
		if ((ch = (unsigned char)c) != 0)
		{
			ch = (ch << 8) | ch;
			if ((UINT_MAX > 0xffff && (ch = (ch << 16) | ch)) || 1)
				if (UINT_MAX > 0xffffffff)
					ch = (ch << FT_MEMSET_SHIFT_32) | ch;
		}
		while (i * sizeof(unsigned int) < n)
			((unsigned int *)arr)[i++] = ch;
		i *= sizeof(unsigned int);
		while (i < n)
			arr[i++] += (unsigned char)ch;
	}
	return (s);
}
