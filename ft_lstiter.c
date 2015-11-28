/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:39:05 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 19:44:44 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** A next pointer is used, in case the function does something desctructive
** with the list (like deleting it).
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		f(lst);
		lst = next;
	}
}
