/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmerge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 20:03:02 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/03 20:20:53 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmerge(t_list *l1, t_list *l2)
{
	t_list	*tmp;

	if ((tmp = ft_lstlast(l1)))
		tmp->next = l2;
	return (l1);
}