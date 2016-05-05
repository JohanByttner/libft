/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:39:10 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 18:20:38 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static inline const char	*ft_strtol_trim(const char *s,
		int *base, int *sign)
{
	char			c;

	while (ft_isspace(*s))
		s++;
	if (*s == '+' || *s == '-')
		*sign = (*s++ == '-' ? 1 : 0);
	c = *s++;
	if ((*base == 0 || *base == 16) && c == '0' && ft_tolower(*s) == 'x')
	{
		*base = 16;
		s += 2;
	}
	else if ((*base == 0 || *base == 2) && c == '0' && ft_tolower(*s) == 'b')
	{
		*base = 2;
		s += 2;
	}
	if (*base == 0)
		*base = c == '0' ? 8 : 10;
	return (--s);
}

static inline int			ft_strtol_gen_c(char *c)
{
	if (ft_isdigit(*c))
		*c -= '0';
	else if (ft_isalpha(*c))
		*c = 10 + (ft_tolower(*c) - 'a');
	else
		return (0);
	return (1);
}

static inline const char	*ft_strtol_gen(const char *s,
		unsigned long *acc, int base, int *overflow)
{
	unsigned long	cutoff;
	int				remnant;
	char			c;
	int				sign;

	sign = *acc;
	*acc = 0;
	cutoff = sign ? -(unsigned long)LONG_MIN : (unsigned long)LONG_MAX;
	remnant = cutoff % base;
	cutoff /= base;
	while ((c = *s++))
	{
		if (!(ft_strtol_gen_c(&c)) || c >= base)
			break ;
		if (*acc > cutoff || (*acc == cutoff && c > remnant))
		{
			*overflow = -1;
			break ;
		}
		*overflow = 1;
		*acc *= base;
		*acc += c;
	}
	return (s);
}

long						ft_strtol(const char *restrict s,
		char **endp, int base)
{
	int				sign;
	const char		*str;
	int				overflow;
	unsigned long	acc;

	str = s;
	sign = 0;
	overflow = 0;
	str = ft_strtol_trim(str, &base, &sign);
	acc = sign;
	str = ft_strtol_gen(str, &acc, base, &overflow);
	if (overflow == -1)
		acc = sign ? LONG_MIN : LONG_MAX;
	else if (sign)
		acc = -acc;
	if (endp)
		*endp = (char *)(overflow ? str - 1 : s);
	return (acc);
}
