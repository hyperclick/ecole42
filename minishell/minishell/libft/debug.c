/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	g_p_name[255];
pid_t	g_main_pid = -1;
int		g_fd = -1;

int		debug_get_fd(void)
{
	return (g_fd);
}

void	print_prefix(void)
{
	int	i;

	i = -1;
	while (++i < getpid() - g_main_pid)
	{
		ft_printf_fd(g_fd, " ");
	}
	ft_printf_fd(g_fd, "[%s]\t", g_p_name);
}

void	close_out_stream(void)
{
	close(g_fd);
}

void	set_out_file(const char *filename)
{
	g_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC | O_APPEND, S_IWRITE);
	if (g_main_pid == -1)
	{
		g_main_pid = getpid();
		ft_strcpy(g_p_name, "main");
	}
}

void	debug_set_pname(const char name[])
{
	ft_strcpy(g_p_name, name);
}
