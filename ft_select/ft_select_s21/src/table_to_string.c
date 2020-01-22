/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_to_String.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:29:04 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:29:06 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

char	*fill_spaces(char *str, int n)
{
	while (n-- > 0)
	{
		*str++ = ' ';
	}
	return (str);
}

char	*fill_table_cell(char *str, t_table *t, int i, int j)
{
	char	*cell;
	int		cell_len;
	int		spaces;

	cell = get_cell(t, i, j);
	cell_len = ft_strlen(cell);
	str = colorize(cell, is_active(t, i, j), is_selected(t, i, j), str);
	ft_strcpy(str, cell);
	str += cell_len;
	ft_strcpy(str, DEFAULT_COLOR);
	str += ft_strlen(DEFAULT_COLOR);
	spaces = t->col_widths[j] - cell_len;
	str = fill_spaces(str, spaces);
	return (str);
}

char	*fill_table_string2(t_table *t, char *str)
{
	int	j;
	int	i;

	i = -1;
	while (++i < t->height)
	{
		j = -1;
		while (++j < t->width)
		{
			if (is_out_of_table(t, i, j))
			{
				*str = 0;
				return (str);
			}
			str = fill_table_cell(str, t, i, j);
		}
		str = fill_spaces(str, g_size_current.ws_col - t->printed_width);
		*str = '\n';
		str++;
	}
	return (str);
}

void	fill_table_string(char *str, t_table *t)
{
	str = fill_table_string2(t, str);
	if (*(str - 1) == '\n')
	{
		str--;
	}
	if (*(str - 1) == ' ')
	{
		str--;
	}
	*str = 0;
}

char	*table_to_string(t_table *t)
{
	char	*r;
	int		size;

	size = t->height + t->height * g_size_current.ws_col + 1
		+ ft_count_null_term_array((void **)g_options) * 6 * 6;
	r = (char *)malloc(sizeof(char) * size);
	debug_printf("%d allocated for table string(%d + %d * %d + 1)\n"
				, size, t->height, t->height, g_size_current.ws_col);
	fill_table_string(r, t);
	debug_printf("table_to_string succeeded\n");
	return (r);
}
