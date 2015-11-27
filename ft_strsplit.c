/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:42:31 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 15:00:06 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_substrings(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 1;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (count);
}

char			**ft_strsplit(const char *s, char c)
{
	char	**result;
	size_t	i;
	size_t	j;
	size_t	n_splits;

	i = 0;
	j = 0;
	n_splits = num_substrings(s, c);
	result = (char **)ft_memalloc(sizeof(char *) * n_splits);
	while (j < n_splits)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		result[j++] = ft_strsub(s, i, (size_t)(ft_strchr(s + i, c) - i));
	}
	return (result);
}
