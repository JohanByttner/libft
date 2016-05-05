/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyttner <jbyttner@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 19:18:45 by jbyttner          #+#    #+#             */
/*   Updated: 2016/02/08 18:24:19 by jbyttner         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static size_t	join_to_heap(t_list *heap, char *buff, size_t r)
{
	char			*tmp;

	if (!(tmp = ft_memalloc(heap->content_size + r)))
		return (0);
	ft_memcpy(tmp + heap->content_size, buff, r);
	ft_memcpy(tmp, ((t_mem *)heap->content)->array, heap->content_size);
	free(((t_mem *)heap->content)->array);
	((t_mem *)heap->content)->array = tmp;
	heap->content_size += r;
	return (heap->content_size);
}

/*
** 0 = continue searching
** 1 = Found newline, copied.
** -1 = Error.
*/

static int		get_line_from_buffer(char **line, t_list *heap)
{
	char			*str;
	size_t			len;

	if (!(str = ft_memchr(((t_mem *)heap->content)->array, '\n',
			heap->content_size)))
		return (0);
	len = (str - (char *)((t_mem *)heap->content)->array);
	if (!(*line = ft_memalloc(len + sizeof(char))))
		return (-1);
	ft_memcpy(*line, ((t_mem *)heap->content)->array, len);
	heap->content_size -= (len + 1);
	if (!(ft_memmove(((t_mem *)heap->content)->array, str + 1,
			heap->content_size)))
		return (-1);
	return (1);
}

static int		read_data_from_fd(int fd, t_list *heap, char **line)
{
	char			buff[BUFF_SIZE];
	int				r;

	if ((r = get_line_from_buffer(line, heap)))
		return (r);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		if (!(join_to_heap(heap, buff, r)))
			return (-1);
		if ((r = get_line_from_buffer(line, heap)))
			return (r);
	}
	if (r == -1)
		return (-1);
	if (heap->content_size)
	{
		*line = ft_memalloc(heap->content_size + 1);
		ft_memcpy(*line, ((t_mem *)heap->content)->array, heap->content_size);
		heap->content_size = 0;
		return (1);
	}
	return (0);
}

/*
** Once we get a call, we want to find the heap where the current
** file descriptor's calls are stored.
** The list secretly stores t_mem pointers (see get_next_line.h)
** which can be retrieved with ((t_mem *)(ptr->content)) .
** Content length is set to give the length of the array in the t_mem object.
** Warning: This is non-standard but legal behaviour.
** Please follow this convention
** in this file.
*/

static t_list	*get_fd_ptr_from_heap(int fd, char **line, t_list **heap)
{
	t_list			*ptr;
	t_mem			mem;

	mem.fd = fd;
	mem.array = 0;
	if (!line)
		return (0);
	if (!(*heap))
	{
		if (!(*heap = ft_lstnew(&mem, sizeof(t_mem))))
			return (0);
		(*heap)->content_size = 0;
		return (*heap);
	}
	ptr = *heap;
	while (ptr && ptr->next && (((t_mem *)ptr->content)->fd != fd))
		ptr = ptr->next;
	if (((t_mem *)ptr->content)->fd == fd)
		return (ptr);
	if (!(ptr->next = ft_lstnew(&mem, sizeof(t_mem))))
		return (0);
	ptr->next->content_size = 0;
	return (ptr->next);
}

/*
** heap is cleaned up on EOF
*/

int				get_next_line(int fd, char **line)
{
	int				r;
	t_list			*ptr;
	static t_list	*heap = 0;
	t_list			*cleanup;

	if (!(ptr = get_fd_ptr_from_heap(fd, line, &(heap))))
		return (-1);
	if ((r = read_data_from_fd(fd, ptr, line)))
		return (r);
	if (ptr == heap)
		heap = ptr->next;
	else
	{
		cleanup = heap;
		while (cleanup && cleanup->next && cleanup->next != ptr)
			cleanup = cleanup->next;
		cleanup->next = ptr->next;
	}
	ft_memdel((void **)&(((t_mem *)ptr->content)->array));
	ft_memdel((void **)&(ptr->content));
	ft_memdel((void **)&(ptr));
	return (0);
}
