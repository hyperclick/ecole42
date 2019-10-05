/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 11:46:01 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 11:46:03 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../libft/libft.h"
#include "tetramino.h"
#include "result_checks.h"

#define BUFF_SIZE ((4 + 1)*(4) + 1) * sizeof(char)

BOOL		is_input_filled(t_elem e)
{
	return (e == FILLED_ELEM);
}

BOOL		parse(t_t *t, char str[BUFF_SIZE], char letter)
{
	int	i;
	int	j;

	(*t).letter = letter;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (is_empty(str[i * 5 + j]))
				(*t).a[i][j] = EMPTY_ELEM;
			else
			{
				if (!is_input_filled(str[i * 5 + j]))
					return (FALSE);
				(*t).a[i][j] = letter;
			}
		}
		if (str[i * 5 + j] != '\n')
			return (FALSE);
	}
	if (str[i * 5] != '\n')
		return (FALSE);
	return (validate_figure(*t));
}

BOOL		is_bad_buffer(const char buffer[BUFF_SIZE], ssize_t bytes_read)
{
	if (bytes_read == BUFF_SIZE)
	{
		return (buffer[BUFF_SIZE - 1] != '\n');
	}
	return (bytes_read != BUFF_SIZE - 1);
}

BOOL		read_file2(int fd)
{
	t_t		t;
	char	buffer[BUFF_SIZE];
	ssize_t	bytes_read;
	char	letter;
	BOOL	has_lf;

	if (fd < 0)
		return (FALSE);
	letter = 'A';
	set_figures_count(0);
	while ((bytes_read = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (is_bad_buffer(buffer, bytes_read)
			|| parse(&t, buffer, letter++) == FALSE)
			return (FALSE);
		buffer[bytes_read] = 0;
		has_lf = buffer[bytes_read - 2] == '\n'
			&& buffer[bytes_read - 1] == '\n';
		add_figure(normalize(t));
	}
	if (bytes_read != 0 || has_lf)
		return (FALSE);
	return (TRUE);
}

BOOL		read_file(const char *filename)
{
	return (read_file2(open(filename, O_RDONLY)));
}
