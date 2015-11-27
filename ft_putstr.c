/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:47:52 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 14:50:50 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** We could use putchar here, but for large strings, we would receive
** a significant performance hit.
*/

void	ft_putstr(const char *s)
{
	write(1, s, ft_strlen(s));
}
