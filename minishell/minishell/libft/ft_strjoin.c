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

#include "libft.h"

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

char	*ft_strjoin2(int count, ...)
{
	int	i;
	int	len;

	char	*str;
	char *s_i;
	va_list       s;
	va_start(s, count);
	i = -1; 
	len = 0;
	while (++i < count)
	{
		s_i = va_arg(s, char*);
		len += ft_strlen(s_i);
		//printf("len = %d, s_i = '%s'\n", len, s_i);
	} 
	va_end(s);

	str = ft_strnew(len);
	if (str == NULL)
	{
		//printf("len = %d\n", len);
		return (NULL);
	}

	va_start(s, count);
	i = -1; 
	while (++i < count)
	{
		s_i = va_arg(s, char*);
		ft_strcat(str, s_i);
	} 
	va_end(s);


	return (str);
}