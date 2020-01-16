/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quoted.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:36:10 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:36:12 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

const char		g_paired_quote[] = "%paired_quote%";
const char		g_unpaired_quote[] = "%unpaired_quote%";

static int	get_target_len(const char *str)
{
	int	quotes_count;
	int	digits_count;
	int	tokens_count;
	int	tokens_len;

	quotes_count = ft_str_count_chars(str, '\"');
	digits_count = int_lg(quotes_count) + 1;
	tokens_count = quotes_count / 2 + 1;
	tokens_len = ft_strlen(g_unpaired_quote) + digits_count;
	return (ft_strlen(str) + tokens_len * tokens_count);
}

char		*add_unpaired_quote(char *dst, const char *value)
{
	return (add_quote(dst, g_unpaired_quote, value));
}

char		*add_paired_quote(char *dst, const char *value)
{
	return (add_quote(dst, g_paired_quote, value));
}

static void	process_string(char *dst, const char *str)
{
	char	param_buffer[ft_strlen(str)];
	char	*p;

	while (*str != 0)
	{
		if (*str == '\"')
		{
			str++;
			p = param_buffer;
			while (*str != 0 && *str != '\"')
			{
				*p++ = *str++;
			}
			*p = 0;
			dst = (*str == 0) ?
				add_unpaired_quote(dst, param_buffer) :
				add_paired_quote(dst, param_buffer);
			if (*str == '\"')
				str++;
			continue;
		}
		*dst++ = *str++;
	}
	*dst++ = 0;
}

char		*replace_quoted(const char *str)
{
	char	*dst;
	int		count;

	count = get_target_len(str) + 1;
	dst = ft_strnew(count * sizeof(char));
	process_string(dst, str);
	debug_printf("quotes replaced: '%s'\n", dst);
	return (dst);
}
