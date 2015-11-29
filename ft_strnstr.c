/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:35:34 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/29 00:22:52 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;

	if (*little != '\0')
	{
		little_len = ft_strlen(little);
		while (*big != '\0' && len >= little_len)
		{
			if (ft_strncmp(big, little, little_len) == 0)
				return ((char *)big);
			big++;
			len--;
		}
		return (0);
	}
	return ((char *)big);
}
