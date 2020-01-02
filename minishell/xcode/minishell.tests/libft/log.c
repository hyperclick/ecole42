/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	log_log(const char *format, ...)
{
	int		fd;
	va_list	argptr;

	fd = open("log.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IWRITE);
	va_start(argptr, format);
	ft_vprintf_fd(fd, format, argptr);
	va_end(argptr);
	close(fd);
}

void	log_line(const char *str)
{
	log_log(str);
	log_log("\n");
}
