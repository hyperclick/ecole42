/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 14:08:18 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 14:08:20 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	g_awaited_process = 0;

pid_t	get_awaited_process(void)
{
	return (g_awaited_process);
}

void	set_awaited_process(pid_t pid)
{
	debug_printf("change g_awaited_process from %d to %d\n"
				, g_awaited_process, pid);
	if ((g_awaited_process != 0 && pid != 0) || g_awaited_process == pid)
	{
		exit(1);
	}
	g_awaited_process = pid;
}
