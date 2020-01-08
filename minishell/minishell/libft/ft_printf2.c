/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL	valid_token_second_char(char c)
{
	return (c != 0 && c != '%' && c != ' ');
}

BOOL	is_token(const char *str)
{
	return (*str == '%' && valid_token_second_char(*(str + 1)));
}

int		count_tokens(const char *str)
{
	int len;

	len = 0;
	while (*str != 0)
	{
		if (is_token(str))
		{
			++len;
		}
		++str;
	}
	return (len);
}

void	fill_tokens(char **tokens, const char *str)
{
	while (*str != 0)
	{
		if (is_token(str))
		{
			*tokens = ft_strsub(str, 0, 2);
			tokens++;
		}
		++str;
	}
}
