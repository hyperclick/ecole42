/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:57:20 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:57:22 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	**g_options = NULL;
int		g_options_count = -1;
t_table	*g_table = NULL;
BOOL	g_show_selection = FALSE;

void		show_selection(void)
{
	g_show_selection = TRUE;
}

void		ft_exit(int ret_code)
{
	debug_printf("exit process (%d)\n", ret_code);
	reset_keypress();
	if (g_show_selection)
	{
		print_selection(g_options);
	}
	if (g_options != NULL)
	{
		ft_free_array((void **)g_options, g_options_count);
	}
	free_table();
	free_selected();
	close_out_stream();
	exit(ret_code);
}

char		**from_arc_argv(int argc, char **argv)
{
	char	**r;
	char	**start_r;
	char	*w;

	r = (char**)malloc(sizeof(char*) * (argc + 1));
	start_r = r;
	r[argc] = NULL;
	while (argc-- > 0)
	{
		w = ft_strdup(*argv++);
		*r = w;
		r++;
	}
	return (start_r);
}

t_table		*rebuild_table(void)
{
	int	count;

	free_table();
	count = MIN(g_size_current.ws_col / 2 - 1
			, ft_count_null_term_array((void**)g_options));
	while (count > 0)
	{
		if ((g_table = try_cols(count--)) != NULL)
		{
			return (g_table);
		}
	}
	return (NULL);
}

void		init(int argc, char **argv)
{
	set_out_file("debug_out4.txt");
	debug_printf("%s\n", "started");
	debug_printf("agrc = %d\n", argc);
	log_line("n\n\n\nstarted\n\n");
	g_options = from_arc_argv(argc - 1, argv + 1);
	g_options_count = argc - 1;
	alloc_selected(g_options_count);
	set_signal_handlers();
}
