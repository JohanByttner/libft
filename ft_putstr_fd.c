/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 15:16:13 by jbyttner          #+#    #+#             */
/*   Updated: 2015/11/27 22:52:16 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** We could use putchar here, but for large strings, we would receive
** a significant performance hit.
*/

void	ft_putstr_fd(const char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
