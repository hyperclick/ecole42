/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 01:53:11 by darugula          #+#    #+#             */
/*   Updated: 2019/07/11 01:53:14 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strcpy(char *dest, char *src)
{
	int len;

	len = 0;
	while (*src != 0)
	{
		*dest = *src;
		dest++;
		src++;
		len++;
	}
	return (dest - len);
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

char	*concat(int count, char *argv[], char *dst, char *separator)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_strcpy(dst, argv[i]);
		dst += ft_strlen(argv[i]);
		if (i < count - 1)
		{
			ft_strcpy(dst, separator);
			dst += ft_strlen(separator);
		}
		i++;
	}
	return (dst);
}

int		calc_len(int count, char *argv[], int separator_len)
{
	int len;

	len = 0;
	while (count > 0)
	{
		len += ft_strlen(argv[count - 1]) + separator_len;
		count--;
	}
	return (len - separator_len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		len;
	char	*separator;

	if (argc < 1)
	{
		return (NULL);
	}
	separator = "\n";
	len = calc_len(argc, argv, ft_strlen(separator));
	return (concat(argc, argv, malloc(len * sizeof(char*)), separator) - len);
}
