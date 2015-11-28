/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:44:51 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 19:55:36 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** I have done my best to secure against destructive function calls
** on lst. Theoretically, f(lst) can destroy lst and the function
** will still work (try this at your own risk).
** If f returns a null pointer, it will cause a memory leak.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*copy;
	t_list	*copy_next;
	t_list	*next;
	t_list	*first;

	first = 0;
	copy = 0;
	while (lst)
	{
		next = lst->next;
		copy_next = f(lst);
		if (copy)
			copy->next = copy_next;
		copy = copy->next;
		first = first ? first : copy;
		lst = next;
	}
	return (first);
}
