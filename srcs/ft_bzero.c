/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:32:19 by jbyttner          #+#    #+#             */
/*   Updated: 2016/05/06 01:40:21 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MIN_WORDS 4

void	ft_bzero(void *s, size_t n)
{
	register size_t			i;
	register unsigned int	ch;
	register unsigned char	*arr;

	i = 0;
	arr = (unsigned char *)s;
	ch = 0;
	if (n < MIN_WORDS * sizeof(unsigned int))
		while (i < n)
			arr[i++] = (unsigned char)ch;
	else
	{
		while (i * sizeof(unsigned int) < n)
			((unsigned int *)arr)[i++] = ch;
		i *= sizeof(unsigned int);
		while (i < n)
			arr[i++] += (unsigned char)ch;
	}
}
