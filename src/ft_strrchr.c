/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:29:26 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/29 00:33:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;

	ptr = 0;
	while (*s != '\0')
	{
		if (*s == c)
			ptr = s;
		s++;
	}
	if (*s == c)
		ptr = s;
	return ((char *)ptr);
}
