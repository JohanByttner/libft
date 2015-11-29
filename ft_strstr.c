/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:35:52 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/28 21:17:32 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	len;

	if (*needle != '\0')
	{
		len = ft_strlen(needle);
		while (ft_strncmp(haystack, needle, len) != 0)
		{
			if (*haystack == '\0')
				return (0);
			haystack++;
		}
	}
	return ((char *)haystack);
}
