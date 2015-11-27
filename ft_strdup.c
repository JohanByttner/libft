/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:34:53 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 16:53:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	int		length;
	char	*res;
	int		i;

	length = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	while (i <= length)
	{
		res[i] = str[i];
		i++;
	}
	return (res);
}
