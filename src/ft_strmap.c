/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 17:07:57 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 16:23:15 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	if (!(s))
		return (0);
	if (!(ptr = ft_strnew(ft_strlen(s))))
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
