/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 19:49:12 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 16:34:09 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*copy;
	size_t	length;

	if (!(s1 && s2))
		return (0);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(copy = (char *)malloc(sizeof(char) * length)))
		return (0);
	ft_strcpy(copy, s1);
	ft_strcat(copy, s2);
	return (copy);
}
