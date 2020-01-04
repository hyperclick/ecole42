/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	debug_printf(const char *format, ...)
{
	va_list argptr;

	if (debug_get_fd() == -1)
	{
		ft_e_putstr("output_stream == -1\n");
		exit(1);
	}
	print_prefix();
	va_start(argptr, format);
	ft_vprintf_fd(debug_get_fd(), format, argptr);
	va_end(argptr);
}

void	debug_print_zt_array(const char *a[])
{
	while (*a != NULL)
	{
		debug_printf("'%s'\t", *a);
		++a;
	}
	debug_printf("\n");
}

void	debug_print_dic(t_list *dic)
{
	t_kvp	**kvps;
	t_kvp	**kvps_start;
	int		count;

	count = dic_get_count(dic);
	debug_printf("dic count = %d\n", count);
	if (count == 0)
	{
		return ;
	}
	kvps = dic_get_kvps(dic);
	kvps_start = kvps;
	while (*kvps != NULL)
	{
		debug_printf("'%s' (%p)\t->\t'%s'\t(%p)\n"
					, (*kvps)->key, (*kvps)->key, (char*)(*kvps)->value, *kvps);
		++(kvps);
	}
	free(kvps_start);
}
