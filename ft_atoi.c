/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/05 16:24:28 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 12:24:05 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_LONG_MAX 9223372036854775807L
#define FT_LONG_MIN (-FT_LONG_MAX - 1)

static inline int			ft_isspace_local(int c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\r'
		|| c == '\v'
		|| c == '\f')
		return (1);
	else
		return (0);
}

static inline const char	*ft_strtol_trim(const char *restrict s,
		int *base, int *sign)
{
	char			c;

	while (ft_isspace_local(*s))
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

static inline const char	*ft_strtol_gen(const char *restrict s,
		unsigned long *acc, int base, int *overflow)
{
	unsigned long	cutoff;
	int				remnant;
	char			c;
	int				sign;

	sign = *acc;
	*acc = 0;
	cutoff = sign ? -(unsigned long)FT_LONG_MIN : (unsigned long)FT_LONG_MAX;
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

int							ft_atoi(const char *s)
{
	int				sign;
	const char		*str;
	int				overflow;
	unsigned long	acc;

	str = s;
	sign = 0;
	overflow = 10;
	str = ft_strtol_trim(str, &overflow, &sign);
	overflow = 0;
	acc = sign;
	str = ft_strtol_gen(str, &acc, 10, &overflow);
	if (overflow == -1)
		acc = sign ? FT_LONG_MIN : FT_LONG_MAX;
	else if (sign)
		acc = -acc;
	return ((int)acc);
}
