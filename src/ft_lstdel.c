/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:30:07 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 21:57:28 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function fails if (*alst)->next at some point is not a valid
** list pointer. It will probably generate a segmentation fault.
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*next;

	if (alst)
		while (*alst)
		{
			next = (*alst)->next;
			ft_lstdelone(alst, del);
			*alst = next;
		}
}
