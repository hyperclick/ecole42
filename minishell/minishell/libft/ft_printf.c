/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:37:38 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:37:40 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*replace_tokens(char *dst, int count, char **args, char **tokens)
{
	int		i;
	char	*tmp;

	i = -1;
	while (++i < count)
	{
		tmp = dst;
		dst = ft_str_replace(dst, tokens[i], args[i]);
		free(tmp);
	}
	return (dst);
}

void	ft_vprintf_fd(int fd, const char *format, va_list args_list)
{
	char	**args;
	char	**tokens;
	int		count;
	char	*dst;

	if (format == NULL)
	{
		ft_putstr_fd("'NULL'", fd);
		return ;
	}
	count = count_tokens(format);
	args = (char**)malloc(sizeof(char*) * (count + 1));
	args[count] = NULL;
	tokens = (char**)malloc(sizeof(char**) * (count + 1));
	tokens[count] = NULL;
	fill_tokens(tokens, format);
	ft_printf_fill_args(args_list, count, args, tokens);
	dst = replace_tokens(ft_strdup(format), count, args, tokens);
	ft_putstr_fd(dst, fd);
	free(dst);
	ft_free_null_term_array((void**)args);
	ft_free_null_term_array((void**)tokens);
}

void	ft_printf_fd(int fd, const char *format, ...)
{
	va_list	args_list;

	va_start(args_list, format);
	ft_vprintf_fd(fd, format, args_list);
	va_end(args_list);
}

void	ft_printf(const char *format, ...)
{
	va_list argptr;

	va_start(argptr, format);
	ft_vprintf_fd(STDOUT_FILENO, format, argptr);
	va_end(argptr);
}
