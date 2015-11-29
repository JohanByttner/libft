/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:42:31 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/29 18:33:58 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_substrings(const char *s, char c)
{
	size_t	count;
	size_t	i;
	int		splitting;

	count = 1;
	i = 0;
	splitting = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			splitting = 1;
		else if (splitting)
		{
			count++;
			splitting = 0;
		}
		i++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	len;

	result = (char **)ft_memalloc(sizeof(char *) * num_substrings(s, c));
	i = 0;
	while (*s != '\0')
	{
		if (*s == c)
			s++;
		else
		{
			if ((len = (size_t)ft_strchr(s, c)))
			{
				result[i++] = ft_strsub(s, 0, len - (size_t)s);
				s = (const char *)len;
			}
			else
			{
				result[i++] = ft_strsub(s, 0, ft_strlen(s));
				break ;
			}
		}
	}
	return (result);
}
