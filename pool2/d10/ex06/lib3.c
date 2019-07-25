/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 01:08:21 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 01:08:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bool.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n);
BOOL	try_parse(char *str, int *n);

BOOL	need_trim(char c)
{
	return (c == ' ' || c == '\t' || c == '\"');
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i++] != 0)
	{
	}
	return (i - 1);
}

char	*trim(char *str)
{
	int		begin;
	int		len;
	int		end;

	begin = 0;
	while (str[begin] && need_trim(str[begin]))
	{
		++begin;
	}
	if (!str[begin])
	{
		return (str + begin);
	}
	len = ft_strlen(str);
	end = len - 1;
	while (str[end] && need_trim(str[end]))
	{
		--end;
	}
	(ft_strncpy(str, str + begin, len - end - begin));
	str[len - end - begin] = 0;
	return (str);
}

int		parse(char *str)
{
	int a;

	if (!try_parse(str, &a))
	{
		a = 0;
	}
	return (a);
}
