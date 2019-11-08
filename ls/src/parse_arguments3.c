/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:40 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:42 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls.h"

void			parse_arguments_add_entry(t_input *input, t_entry e)
{
	if (is_folder(e.s.st_mode))
	{
		input->folders[input->folders_count++] = e;
		if (input->folders_count > MAX_FSO_IN_DIR)
		{
			ft_putstr("MAX_FSO_IN_DIR reached \n");
			exit(3);
		}
	}
	else
	{
		input->files[input->files_count++] = e;
		if (input->files_count > MAX_FSO_IN_DIR)
		{
			ft_putstr("MAX_FSO_IN_DIR reached \n");
			exit(4);
		}
	}
}

t_input			create_empty_input(void)
{
	t_input input;

	input.files_count = 0;
	input.folders_count = 0;
	input.args_count = 0;
	input.sort_options.sort_by = SORT_BY_NAME;
	input.sort_options.sort_desc = FALSE;
	return (input);
}
