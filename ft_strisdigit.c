/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strisdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 13:25:52 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/06 13:28:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strisdigit(char *str)
{
	if (str)
	{
		while (*str && ft_isdigit(*str))
			str++;
		if (*str)
			return (0);
		else
			return (1);
	}
	return (0);
}
