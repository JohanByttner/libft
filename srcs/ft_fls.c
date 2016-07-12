/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/11 20:21:48 by jbyttner          #+#    #+#             */
/*   Updated: 2016/07/11 20:30:34 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

/*
** We safeguard against shifting by "sizeof (int) * CHAR_BIT" bits.
*/

#if UINT_MAX > 0xffff
# define FT_FLS_SHIFT_16 16
#else
# define FT_FLS_SHIFT_16 0
#endif

/*
** This seems to be the fastest way to do it,
** resulting in only 13 instructions.
** http://aggregate.org/MAGIC/#Most%20Significant%201%20Bit
*/

int		ft_fls(register int byte)
{
	byte |= (byte >> 1);
	byte |= (byte >> 2);
	byte |= (byte >> 4);
	byte |= (byte >> 8);
	byte |= (byte >> FT_FLS_SHIFT_16);
	return (byte & ~(byte >> 1));
}
