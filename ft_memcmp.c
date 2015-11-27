/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:33:56 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:33:57 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;
	UCHAR	*s1_c;
	UCHAR	*s2_c;

	if (n == 0)
		return (0);
	s1_c = (UCHAR *)s1;
	s2_c = (UCHAR *)s2;
	i = 0;
	while (i < n && s1_c[i] == s2_c[i])
		i++;
	return (s1_c[i] - s2_c[i]);
}
