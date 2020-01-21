/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 12:24:18 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 12:24:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

BOOL			process_command(char *str)
{
	char cmd_name[100];
	int		r;

	if (str == NULL)
	{
		ft_exit(5);
	}
	ft_strcpy(cmd_name, str);
	free(str);
	debug_printf("\n");
	debug_printf("-----------------------\n");
	debug_printf("process command: '%s'\n", cmd_name);
	r = process_command2(cmd_name);
	debug_printf("command processed: '%s'\n", cmd_name);
	debug_printf("-------------------------\n");
	debug_printf("\n");
	if (r == DO_NOT_REDRAW)
	{
		return (FALSE);
	}
	if (r != DO_NOT_EXIT)
	{
		ft_exit(r);
	}
	return (TRUE);
}