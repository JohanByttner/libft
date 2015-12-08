/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:06:38 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/08 13:08:55 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes a malloc-allocated pointer and copies its content into a new
** pointer of desired length, then frees it and sets its value
** to the newly created pointer. Any bytes beyond new_length
** in mem will be lost. If malloc fails, the function returns 0
** and the original memory is not affected.
** Returns a pointer to tmp upon success
** This function is intended as a quick-and-dirty alternative to realloc.
*/

#include <stdlib.h>
#include "libft.h"

void	*ft_memadjust(const void **mem, size_t new_length)
{
	unsigned char	*tmp;

	tmp = ft_memalloc(sizeof(unsigned char) * new_length);
	if (!(tmp))
		return (0);
	ft_memcpy(tmp, mem, new_length);
	free(*mem);
	*mem = tmp;
	return ((void *)tmp);
}
