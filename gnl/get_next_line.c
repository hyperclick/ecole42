/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 00:54:40 by darugula          #+#    #+#             */
/*   Updated: 2019/09/19 00:54:41 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*find_or_create(int fd, t_list **buffers)
{
	t_list		*n;
	t_buffer	*b;

	b = NULL;
	if (*buffers != NULL)
	{
		n = *buffers;
		b = (t_buffer*)n->content;
		while (b->fd != fd && (n = n->next) != NULL)
			b = (t_buffer*)n->content;
		if (b->fd != fd)
			b = NULL;
	}
	if (*buffers == NULL || b == NULL)
	{
		b = malloc(sizeof(t_buffer));
		b->fd = fd;
		b->line = NULL;
		b->rest = ft_strnew(0);
		ft_lstadd(buffers, ft_lstnew(b, sizeof(b)));
	}
	return (b);
}

void		set_rest(t_buffer *b, char *src)
{
	free(b->rest);
	b->rest = src;
}

int			extract_line_from_rest(t_buffer *b)
{
	char	*right;
	char	*tmp;

	if ((right = ft_strchr(b->rest, '\n')))
	{
		tmp = ft_strsub(b->rest, 0, ft_strlen(b->rest) - ft_strlen(right));
		b->line = ft_strdup(tmp);
		free(tmp);
		set_rest(b, ft_strdup(right + 1));
		return (1);
	}
	return (0);
}

int			read_line(t_buffer *b)
{
	ssize_t		bytes_read;
	int			r;

	if ((r = extract_line_from_rest(b)) != 0)
		return (r);
	while ((bytes_read = read(b->fd, b->buffer, BUFF_SIZE)) == BUFF_SIZE)
	{
		b->buffer[bytes_read] = 0;
		set_rest(b, ft_strjoin(b->rest, b->buffer));
		if ((r = extract_line_from_rest(b)) != 0)
			return (r);
	}
	if (bytes_read < 0)
		return (-1);
	b->buffer[bytes_read] = 0;
	if (ft_strlen(b->rest) == 0 && ft_strlen(b->buffer) == 0)
		return (0);
	set_rest(b, ft_strjoin(b->rest, b->buffer));
	if ((r = extract_line_from_rest(b)) != 0)
		return (r);
	b->line = ft_strdup(b->rest);
	free(b->rest);
	b->rest = ft_strnew(0);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static t_list	*buffers;
	t_buffer		*b;
	int				r;

	if (fd < 0 || line == NULL || BUFF_SIZE == 0)
	{
		return (-1);
	}
	b = find_or_create(fd, &buffers);
	if ((r = read_line(b)) > 0)
	{
		*line = ft_strdup(b->line);
		free(b->line);
	}
	return (r);
}
