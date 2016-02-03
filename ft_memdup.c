/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 22:45:19 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/03 12:45:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memdup(void *ptr, size_t length)
{
	unsigned char	*copy;

	if (!(copy = (unsigned char *)malloc(length)))
		return (0);
	ft_memcpy(copy, ptr, length);
	return (copy);
}
