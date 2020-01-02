/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_reader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:30:12 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:30:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static const char	*read_line_hidden_end(int r)
{
	debug_printf("r = %d\n", r);
	reset_keypress();
	if (r == 0)
	{
		debug_printf("std in is all\n");
		exit(1);
	}
	if (get_buf_len() > 0)
	{
		h_append(ft_strdup(get_buffer()));
	}
	return (get_buffer());
}

const char			*read_line_hidden(void)
{
	int			r;
	char		control[10];
	char		c;

	control[0] = 0;
	clean_buffer();
	set_keypress();
	while ((r = read(STDIN_FILENO, &c, 1)) > 0)
	{
		debug_printf("entered:\t%d ('%c'), control = '%s'\n", c, c, control);
		if (ft_strlen(control) == 0 && c == '\n')
		{
			ft_putchar(c);
			break ;
		}
		if (ft_strlen(control) == 0 && ft_isprint(c))
		{
			process_printable(c);
			continue;
		}
		process_not_printable(control, c);
	}
	return (read_line_hidden_end(r));
}
