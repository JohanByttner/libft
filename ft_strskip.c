/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strskip.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 17:19:20 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/05 17:35:34 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes 
*/

/*
** For reference, breaking out of nested loops is a valid use of goto.
** We should have special permission to use it in case it is necessary
** (just like globals).
*/

char	*ft_strskip(char *str, const char *skip)
{
	const char	it;
	int			goto_10;

	while (*str != '\0')
	{
		it = skip;
		goto_10 = 0;
		while (*it != '\0')
			if (*it++ == *str)
			{
				str++;
				goto_10 = 1;
				break ;
			}
		if (goto_10)
			continue ;
		break ;
	}
	return (str);
}
