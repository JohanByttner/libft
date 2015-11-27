/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:47:52 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 15:18:07 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** We could use putchar here, but for large strings, we would receive
** a significant performance hit.
*/

void	ft_putstr(const char *s)
{
	ft_putstr_fd(s, 1);
}
