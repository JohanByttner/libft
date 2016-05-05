/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:04:26 by jbyttner          #+#    #+#             */
/*   Updated: 2015/12/03 16:24:52 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H
# include <stdlib.h>
# include "libft.h"
# define BUFF_SIZE 30

/*
** Heap memory is associated with a file descriptor.
** content_size in the file descriptor gives the length of array
** in t_mem. This structure is meant to be safe to cast.
** The fd is accessed as ((t_mem *)list->content)->fd)
*/

typedef struct	s_mem
{
	int			fd;
	char		*array;
}				t_mem;

int				get_next_line(const int fd, char **line);

#endif
