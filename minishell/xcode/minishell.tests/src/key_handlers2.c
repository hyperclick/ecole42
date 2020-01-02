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

BOOL	process_key_down(void)
{
	if (h_has_next())
	{
		buffer_set(h_get_next());
		buffer_print();
	}
	return (TRUE);
}

BOOL	process_key_up(void)
{
	if (h_has_previous())
	{
		buffer_set(h_get_previous());
		buffer_print();
	}
	return (TRUE);
}

BOOL	process_backspace(void)
{
	clean_printed_text_and_move_cursor_left();
	buffer_backspace();
	buffer_print();
	return (TRUE);
}

BOOL	process_delete(void)
{
	clean_printed_text_and_move_cursor_left();
	buffer_delete();
	buffer_print();
	return (TRUE);
}

void	process_printable(char c)
{
	clean_printed_text_and_move_cursor_left();
	buffer_insert(c);
	buffer_print();
}
