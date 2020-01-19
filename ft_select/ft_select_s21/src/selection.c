/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	g_active_index = -1;

int		get_active_cell_offset()
{
	return (g_active_index);
}

void		set_active_cell_offset(int offset)
{
	g_active_index = offset;
}

void		set_active_cell(t_table* t, t_coord new_c)
{
	t_coord c;

	if (is_out_of_table(t, new_c.row, new_c.col))
	{
		debug_printf("ignore set active cell to %d:%d since it out of table\n", new_c.row, new_c.col);
		return;
	}
	c = get_active_cell_coord(t);
	set_active_cell_offset(get_offset(t, new_c.row, new_c.col));
	debug_printf("change active cell from %d:%d to %d:%d (%d)\n", c.row, c.col, new_c.row, new_c.col, g_active_index);
}

BOOL		is_active2(int offset)
{
	return (g_active_index == offset);
}

BOOL		is_active(t_table *t, int i, int j)
{
	return (is_active2(get_offset(t, i, j)));
}


int* g_selected = NULL;
int g_selected_count = 0;

void		alloc_selected(int size)
{
	g_selected = (int*)malloc(sizeof(int) * size);
}

void		free_selected()
{
	free(g_selected);
}

void		print_selection(char **options)
{
	int	i;
	BOOL		first;

	first = TRUE;
	i = -1;
	while (*options != NULL)
	{
		debug_printf("check: '%s'\n", *options);
		if (ft_contains_int(g_selected, g_selected_count, ++i))
		{
			if (!first)
			{
				ft_putchar(' ');
			}
			else
			{
				first = FALSE;
			}
			ft_printf("%s", *options);
		}
		options++;
	}
}

int		ft_int_index_of(int* a, int size, int value)
{
	while (--size >= 0)
	{
		//ft_printf("check %d\n", size);
		if (a[size] == value)
		{
			return (size);
		}
	}
	return (-1);
}

BOOL		ft_contains_int(int* a, int size, int value)
{
	return (ft_int_index_of(a, size, value) < 0 ? FALSE : TRUE);
}


BOOL		is_selected2(int offset)
{
	return (ft_contains_int(g_selected, g_selected_count, offset));
}

BOOL		is_selected(t_table *t, int row, int col)
{
	return (is_selected2(get_offset(t, row, col)));
}

void		dump_selection()
{
	int i;
	char *str;
	char* tmp;
	char* tmp2;

	debug_printf("selection changed (%d):\n", g_selected_count);
	i = -1;
	str = ft_strdup("");
	while (++i < g_selected_count)
	{
		tmp = str;
		tmp2 = ft_stprintf("%d, ", g_selected[i]);
		str = ft_strjoin(str, tmp2);
		free(tmp);
		free(tmp2);
	}
		tmp = str;
		str = ft_strjoin(str, "\n");
		free(tmp);
	debug_printf(str);
	free(str);
}

void		select_add(int offset)
{
	g_selected[g_selected_count++] = offset;
	dump_selection();
}

void		remove_from_selected_at(int n)
{
	while (n < g_selected_count)
	{
		g_selected[n] = g_selected[n + 1];
		n++;
	}
	g_selected[--g_selected_count] = -1;
}

BOOL		remove_if_selected(int offset)
{
	int n;

	n = ft_int_index_of(g_selected, g_selected_count, offset);
	if (n >= 0)
	{
		remove_from_selected_at(n);
		return (TRUE);
	}
	return (FALSE);
}

void		toggle_active_cell()
{
	if (!remove_if_selected(get_active_cell_offset()))
	{
		select_add(get_active_cell_offset());
	}
	dump_selection();
}

void	 handle_item_deleted(int offset)
{
	int	i;

	remove_if_selected(offset);
	i = offset;
	while (++i < g_options_count + 1)
	{
		if (remove_if_selected(i))
		{
			select_add(i - 1);
		}
	}
	dump_selection();
}