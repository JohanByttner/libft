/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:22:23 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 21:25:36 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** I still think casting malloc returns is a bad idea ...
*/

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ptr;

	if ((ptr = (t_list *)malloc(sizeof(t_list))))
	{
		if (content && content_size)
			if (!(ptr->content = ft_memalloc(content_size)))
			{
				free(ptr);
				return (0);
			}
		if (content && content_size)
			ft_memcpy(ptr->content, content, content_size);
		else
			ptr->content = 0;
		ptr->content_size = (content && content_size) ? content_size : 0;
		ptr->next = 0;
	}
	return (ptr);
}
