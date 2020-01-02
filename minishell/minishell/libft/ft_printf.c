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
BOOL	valid_token_second_char(char c)
{
	return (c != 0 && c != '%' && c != ' ');
}

BOOL	is_token(const char* str)
{
	return (*str == '%' && valid_token_second_char(*(str + 1)));
}

int		count_tokens(const char* str)
{
	int len = 0;
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

static void	fill_tokens(char** tokens, const char* str)
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

void ft_vprintf_fd(int fd, const char* format, va_list args_list)
{
	int i;
	char** args;
	char** tokens;

	if (format == NULL)
	{
		ft_putstr("'NULL'");
	}
	int count = count_tokens(format);

	args = (char**)malloc(sizeof(char*) * (count + 1));
	args[count] = NULL;
	tokens = (char**)malloc(sizeof(char**) * (count + 1));
	tokens[count] = NULL;

	fill_tokens(tokens, format);


	i = -1;
	while (++i < count)
	{
		if (ft_str_equals(tokens[i], "%s"))
		{
			char* arg = va_arg(args_list, char*);
			args[i] = ft_strdup(arg == NULL ? "(NULL)" : arg);
		}
		else if (ft_str_equals(tokens[i], "%c"))
		{
			args[i] = ft_strnew(1);
			args[i][0] = (char)va_arg(args_list, int);
		}
		else if (ft_str_equals(tokens[i], "%d"))
		{
			args[i] = ft_itoa(va_arg(args_list, int));
		}
		else if (ft_str_equals(tokens[i], "%p"))
		{
			void* p = va_arg(args_list, void*);
			args[i] = ft_itoa((long long)p);
		}
		else
		{
			ft_e_putstr("unexpected format: ");
			ft_e_putstr(tokens[i]);
			ft_e_putstr("\n");
			exit(1);
		}
	}
	char* dst;
	dst = ft_strdup(format);
	i = -1;
	while (++i < count)
	{
		char* tmp = dst;
		dst = ft_str_replace(dst, tokens[i], args[i]);

		//printf("%d: %s\n", i, args[i]);
		free(tmp);
	}
	//printf("\n");

	ft_putstr_fd(dst, fd);
	free(dst);
	//free(args);
	ft_free_null_term_array((void**)args);
	ft_free_null_term_array((void**)tokens);

}

void	ft_printf_fd(int fd, const char* format, ...)
{


	va_list args_list;
	va_start(args_list, format);
	ft_vprintf_fd(fd, format, args_list);
	va_end(args_list);

}

void	ft_printf(const char* format, ...)
{
	va_list argptr;
	va_start(argptr, format);
	ft_vprintf_fd(STDOUT_FILENO, format, argptr);
	va_end(argptr);
}
