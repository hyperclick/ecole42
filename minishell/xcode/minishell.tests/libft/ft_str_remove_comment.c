/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 01:51:27 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 01:51:31 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_remove_comment(const char *str, char comment)
{
	int offset;
	int n;

	if (*str == comment)
	{
		return (ft_strdup(""));
	}
	offset = 0;
	while (TRUE)
	{
		n = ft_str_index_of(str + offset, '#');
		if (n == -1)
		{
			return (ft_strdup(str));
		}
		offset += n + 1;
		if (str[offset - 2] == ' '
			|| str[offset - 2] == '\t' || str[offset - 2] == ';')
		{
			return (ft_strsub(str, 0, offset - 1));
		}
	}
}
