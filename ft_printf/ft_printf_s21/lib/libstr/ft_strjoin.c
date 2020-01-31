/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:19:06 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:19:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*str;

	if (s1 == NULL || s2 == NULL)
	{
		return (NULL);
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	str = ft_strnew(len_s1 + len_s2);
	if (str == NULL)
	{
		return (NULL);
	}
	return (ft_strcat(ft_strcat(str, s1), s2));
}

int		va_get_len(va_list args_list, int count)
{
	int		i;
	int		len;
	char	*s_i;

	i = -1;
	len = 0;
	while (++i < count)
	{
		s_i = va_arg(args_list, char*);
		len += ft_strlen(s_i);
	}
	return (len);
}

char	*ft_strjoin2(int count, ...)
{
	int		i;
	int		len;
	char	*str;
	char	*s_i;
	va_list	args_list;

	va_start(args_list, count);
	len = va_get_len(args_list, count);
	va_end(args_list);
	str = ft_strnew(len);
	if (str == NULL)
	{
		return (NULL);
	}
	va_start(args_list, count);
	i = -1;
	while (++i < count)
	{
		s_i = va_arg(args_list, char*);
		ft_strcat(str, s_i);
	}
	va_end(args_list);
	return (str);
}
