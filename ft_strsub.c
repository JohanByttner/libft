/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 14:07:01 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/04 21:38:47 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Alloue (avec malloc(3)) et retourne la copie “fraiche” d’un
** tronçon de la chaine de caractères passée en paramètre. Le
** tronçon commence à l’index start et à pour longueur len. Si
** start et len ne désignent pas un tronçon de chaine valide,
** le comportement est indéterminé. Si l’allocation échoue, la
** fonction renvoie NULL.
*/

/*
** Returns a null-terminated  string of length len. If start and len
** do not delimit a valid string, the function returns
** a null-terminated string of memory length len + 1,
** including, if possible, a null-terminated copy of s.
** If start is larger than the length of s, the function returns
** a null-terminated string of length len, uninitialised
** but null-terminated at byte 0.
*/

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*copy;

	if (!(s) || !(*s))
		return (0);
	if (!(len))
		return ((char *)ft_memalloc(sizeof(char)));
	copy = 0;
	if ((copy = (char *)ft_memalloc(sizeof(char) * (len + 1))))
		if (start <= ft_strlen(s))
			ft_strlcpy(copy, s + start, len + 1);
	return (copy);
}
