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
#include <stdio.h>

#define LEVEL_ALL 0
#define LEVEL_DEBUG 1
int	g_level = LEVEL_ALL;
FILE* output_stream = NULL;

void		set_level(int level)
{
	g_level = level;
	debug_printf("level set to %d\n", g_level);
}
void		set_out_stream(FILE* stream)
{
	output_stream = stream;
	//debug_printf("level set to %d\n", g_level);
}
void		close_out_stream()
{
	fclose(output_stream);
}

void		set_out_file(const char* filename, const char *mode)
{
	set_out_stream(fopen(filename, mode));
}
void	debug_printf(const char* format, ...)
{
	if (g_level < LEVEL_DEBUG)
	{
		return;
	}
	if (output_stream == NULL)
	{
		ft_e_putstr("output_stream == NULL");
		exit(1);
	}
	fprintf(output_stream, "\tdbg:\t");
	va_list argptr;
	va_start(argptr, format);
	vfprintf(output_stream, format, argptr);
	va_end(argptr);
	fflush(output_stream);
}
