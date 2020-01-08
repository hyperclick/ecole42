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
#include "key_constants.h"

BOOL	process_delete(void)
{
	clean_printed_text_and_move_cursor_left();
	buffer_delete();
	buffer_print();
	return (TRUE);
}

void	process_printable(char c)
{
	debug_printf("process printable: '%c'\n", c);
	clean_printed_text_and_move_cursor_left();
	buffer_insert(c);
	buffer_print();
}

BOOL	process_tab(void)
{
	return (TRUE);
}

BOOL	process_backspace(void)
{
	clean_printed_text_and_move_cursor_left();
	buffer_backspace();
	buffer_print();
	return (TRUE);
}
