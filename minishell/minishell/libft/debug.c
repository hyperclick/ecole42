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

char	p_name[255];
pid_t	g_main_pid = -1;
int		g_fd = -1;

int		debug_get_fd()
{
	return (g_fd);
}

void	print_prefix()
{
	for (int i = 0; i < getpid() - g_main_pid; i++)
	{
		ft_printf_fd(g_fd, " ");
	}
	ft_printf_fd(g_fd, "[%s]\t", p_name);

}

void		close_out_stream()
{
	close(g_fd);
}

void		set_out_file(const char* filename)
{
	g_fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IWRITE);
	if (g_main_pid == -1)
	{
		g_main_pid = getpid();
		ft_strcpy(p_name, "main");
	}
}

void		debug_set_pname(const char name[])
{
	ft_strcpy(p_name, name);
}