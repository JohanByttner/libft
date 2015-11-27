/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:35:52 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:35:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*strstr(const char *haystack, const char *needle)
{
	const char	*start;

	start = 0;
	while (*haystack != '\0')
	{
		if (*needle == *haystack)
			start = start ? start : haystack;
		else
		{
			needle = start;
			start = 0;
		}
		if (*needle == '\0')
			break ;
		needle++;
		haystack++;
	}
	start = *needle ? 0 : start;
	return ((char *)start);
}
