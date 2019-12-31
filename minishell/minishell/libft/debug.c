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
char p_name[255];
pid_t	main_pid = -1;

void		set_level(int level)
{
	g_level = level;
	debug_printf("level set to %d\n", g_level);
}
void		set_out_stream(FILE* stream)
{
	if (main_pid == -1)
	{
		main_pid = getpid();
		ft_strcpy(p_name, "main");
	}
	output_stream = stream;
	//debug_printf("level set to %d\n", g_level);
}

void		close_out_stream()
{
	fclose(output_stream);
}

void		set_out_file(const char* filename, const char* mode)
{
	set_out_stream(fopen(filename, mode));
	//printf("file %s is opened\n", filename);
}

void debug_set_pname(const char name[])
{
	ft_strcpy(p_name, name);
}

void print_prefix()
{
	for (int i = 0; i < getpid() - main_pid; i++)
	{
		fprintf(output_stream, " ");
	}
	fprintf(output_stream, "[%s]\t", p_name);

}
void	debug_printf(const char* format, ...)
{
	if (g_level < LEVEL_DEBUG)
	{
		return ;
	}
	if (output_stream == NULL)
	{
		ft_e_putstr("output_stream == NULL");
		exit(1);
	}
	print_prefix();
	va_list argptr;
	va_start(argptr, format);
	vfprintf(output_stream, format, argptr);
	va_end(argptr);
	fflush(output_stream);
}

void	debug_print_zt_array(const char* a[])
{
	while (*a != NULL)
	{
		fprintf(output_stream, "'%s'\t", *a);
		++a;
	}
	fprintf(output_stream, "\n");
}

void debug_print_dic(t_list* dic)
{
	t_kvp **kvps;
	t_kvp **kvps_start;
	int count;

	count = dic_get_count(dic);
	debug_printf("dic count = %d\n", count);
	if (count == 0)
	{
		return ;
	}
	kvps = dic_get_kvps(dic);
	kvps_start = kvps;
	//	debug_printf("kvps = %p\n", kvps);
	while (*kvps != NULL)
	{
		debug_printf("'%s' (%p)\t->\t'%s'\t(%p)\n", (*kvps)->key, (*kvps)->key, (char*)(*kvps)->value, *kvps);
		++(kvps);
	}
	free(kvps_start);
}
