/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 16:41:51 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/02 14:48:49 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** I register my official denouncement of casting void pointers
** that are returned from functions, as it is unsafe and can cause
** memory losses or segmentation faults if the wrong cast is used.
** This causes difficult to diagnose and dangerous bugs in seemingly
** unrelated functions much later in the program's execution.
** Casting void pointers also hides inclusion omissions.
** It is a dangerous and despicable practice and should be stopped
** for the sanity of people who one day have to use the code written
** by students from Ecole 42. It does us all a great disservice.
** Void pointers are *meant* to be uncasted.
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	if (size == 0)
		return (0);
	if (!(ptr = (unsigned char *)malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
