/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 16:39:10 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 18:08:10 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define FT_LONG_MAX 9223372036854775807L
#define FT_LONG_MIN (-FT_LONG_MAX - 1)

static inline void	ft_strtol_trim(const char *restrict s, int *base, int *sign)
{
	char			c;

	while (ft_isspace(*s)) 
		s++;
	if (*s == '+' || *s == '-')
		*sign = *s++ == '-' ? 1 : 0;
	c = *s++;
	if ((*base == 0 || *base == 16) && c == '0' && ft_tolower(*s) == 'x')
	{
		*base = 16;
		s++;
	}
	else if ((*base == 0 || *base == 2) && c == '0' && ft_tolower(*s) == 'b')
	{
		*base = 2;
		s++;
	}
	if (*base == 0)
		*base = c == '0' ? 8 : 10;
}

static inline const char	*ft_strtol_gen(const char *restrict s, unsigned long *acc,
						int base, int sign)
{
	unsigned long	cutoff;
	int				remnant;
	char			c;

	cutoff = sign ? -(unsigned long)FT_LONG_MIN : (unsigned long)FT_LONG_MAX;
	remnant = cutoff % base;
	cutoff /= base;
	while ((c = *s++))
	{
		if (ft_isdigit(c))
			c -= '0';
		else if (ft_isalpha(c))
			c = 10 + (ft_tolower(c) - 'a');
		else
			break ;
		if (c >= base)
			break ;
		if (*acc > cutoff || (*acc == cutoff && c > remnant))
		{
			*acc = sign ? FT_LONG_MIN : FT_LONG_MAX;
			break ;
		}
		*acc *= base;
		*acc += c;
	}
	return (s);
}

long			ft_strtol(const char *restrict s, char **restrict endp, int base)
{
	int				sign;
	int				b;
	unsigned long	acc;

	b = base;
	sign = 0;
	acc = 0;
	if (!(s))
		return (0);
	ft_strtol_trim(s, &b, &sign);
	s = ft_strtol_gen(s, &acc,  b, sign);
	if (endp)
		*endp = (char *)s - 1;
	return (acc);
}
