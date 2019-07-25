/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 01:06:49 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 01:06:51 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "bool.h"

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);
char	*itoa(int n, char *r);
int		ft_strlen(char *str);
char	*trim(char *str);
int		parse(char *str);

struct	s_opp
{
	char	*name;
	int		(*ptr)(int, int);
};

struct s_opp g_opptab[] =
{
	{"-", &ft_sub},
	{"+", &ft_add},
	{"*", &ft_mul},
	{"/", &ft_div},
	{"%", &ft_mod},
	{0, 0}
};

int		ft_strcmp(char *s1, char *s2)
{
	if (*s1 != *s2)
	{
		return (*s1 - *s2);
	}
	if (*s1 == 0)
	{
		return (0);
	}
	return (ft_strcmp(s1 + 1, s2 + 1));
}

int		(*g_find_op(char *name))(int, int)
{
	int	i;

	if (!name || *name == 0)
	{
		return (NULL);
	}
	i = 0;
	while (g_opptab[i].name != 0)
	{
		if (ft_strcmp(g_opptab[i].name, name) == 0)
		{
			return (g_opptab[i].ptr);
		}
		++i;
	}
	return (NULL);
}

char	*calc(int a, int b, int (*op)(int, int), char dst[])
{
	int		len;

	if (op == NULL)
	{
		return ("0\n");
	}
	if (b == 0 && op == ft_div)
	{
		return ("Stop : division by zero\n");
	}
	if (b == 0 && op == ft_mod)
	{
		return ("Stop : modulo by zero\n");
	}
	itoa(op(a, b), dst);
	len = ft_strlen(dst);
	dst[len++] = '\n';
	dst[len] = 0;
	return (dst);
}

char	*do_op(int argc, char **argv, char dst[])
{
	int (*op)(int, int);

	if (argc != 4)
	{
		return ("");
	}
	op = g_find_op(trim(argv[2]));
	return (calc(parse(argv[1]), parse(argv[3]), op, dst));
}
