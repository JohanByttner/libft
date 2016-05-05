/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memadjust.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:06:38 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 13:26:08 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Takes a malloc-allocated pointer and copies its content into a new
** pointer of desired length, then frees it and sets its value
** to the newly created pointer. Any bytes beyond new_length
** in mem will be lost. If malloc fails, the function returns 0
** and the original memory is not affected.
** Calling with mem pointing to a numm ptr is valid. In that case
** the function will act as Malloc and old_length will be ignored.
** Returns a pointer to tmp upon success
** This function is intended as a quick-and-dirty alternative to realloc.
*/

#include <stdlib.h>
#include "libft.h"

void	*ft_memadjust(void **mem, size_t old_length, size_t new_length)
{
	unsigned char	*tmp;

	if (!(mem))
		return (0);
	if (!(tmp = ft_memalloc(sizeof(unsigned char) * new_length)))
		return (0);
	if (*mem)
	{
		if (old_length > new_length)
			old_length = new_length;
		ft_memcpy(tmp, *mem, old_length);
		free(*mem);
	}
	*mem = tmp;
	return ((void *)tmp);
}
