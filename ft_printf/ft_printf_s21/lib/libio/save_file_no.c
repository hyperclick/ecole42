/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_file_no.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:17:30 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:17:32 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libio.h"

int	g_stdin = -1;
int g_stdout = -1;

void	save_stdin(void)
{
	g_stdin = dup(STDIN_FILENO);
	//debug_printf("duplicated stdin to %d\n", g_stdin);
}

void	restore_stdin(void)
{
	//debug_printf("restore stdin\n");
	redirect(g_stdin, STDIN_FILENO);
}

void	restore_stdout(void)
{
	//debug_printf("restore stdout\n");
	redirect(g_stdout, STDOUT_FILENO);
}

void	save_stdout(void)
{
	g_stdout = dup(STDOUT_FILENO);
	//debug_printf("duplicated stdout to %d\n", g_stdout);
}
