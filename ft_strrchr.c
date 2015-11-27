/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:29:26 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/25 15:35:48 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	if ((char)c == '\0')
		return (ft_strchr(s, '\0'));
	while (ft_strchr(s, c))
		s = ft_strchr(s, c);
	return ((char *)s);
}
