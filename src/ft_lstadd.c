/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 19:36:59 by jbyttner          #+#    #+#             */
/*   Updated: 2016/01/02 01:10:25 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Added (new == 0) protection (so calls can be chained)
*/

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new)
	{
		new->next = (*alst);
		*alst = new;
	}
}
