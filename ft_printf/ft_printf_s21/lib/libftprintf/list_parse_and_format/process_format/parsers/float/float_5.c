/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:22:31 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:22:34 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

void		*on_crash(int err)
{
	(err == MALLOC_ERR) ? ft_putstr("Malloc error") : 0;
	ft_putstr("\n");
	exit(err);
}

static void	ft_do_null(char *str, int i)
{
	while (str[--i] == '0')
		str[i] -= '0';
}

static void	ft_res_more(char *res, int *k)
{
	int		l;

	l = 0;
	res[(*k) + 1] = res[(*k) + 1] + res[*k] / 10;
	while (res[(*k) + 1 + l] > 9)
	{
		++l;
		res[(*k) + 1 + l] = res[(*k) + 1 + l] + (res[(*k) + l] / 10);
		res[(*k) + l] = res[(*k) + l] % 10;
	}
	res[*k] = res[*k] % 10;
}

static void	ft_buf_more(char *a, char *b, t_join *st)
{
	st->buf[st->i][st->j + st->i] = st->buf[st->i][st->j + st->i]
			+ ((a[st->j] - '0') * (b[st->i] - '0'));
	if (st->buf[st->i][st->j + st->i] > 9)
		st->buf[st->i][st->j + st->i + 1] = (st->buf[st->i][st->j + st->i + 1]
				+ st->buf[st->i][st->j + st->i]) / 10;
	st->buf[st->i][st->j + st->i] = st->buf[st->i][st->j + st->i] % 10;
}

char		*ft_join_str(char **buf, int strs, int len)
{
	int		i;
	int		j;
	int		k;
	char	*res;

	if (!(res = ft_strnew(len)))
		return (ft_frees(buf, strs));
	j = -1;
	k = 0;
	while (++j < len - 1)
	{
		i = -1;
		while (++i < strs)
		{
			res[k] = res[k] + buf[i][j];
			res[k] > 9 ? ft_res_more(res, &k) : 0;
		}
		res[k] = res[k] + '0';
		++k;
	}
	ft_do_null(res, len - 1);
	ft_frees(buf, strs);
	return (res);
}

char		*ft_join(char *a, char *b)
{
	t_join	st;
	int		sa;
	int		sb;

	st.i = -1;
	sa = ft_strlen(a) + 1;
	sb = ft_strlen(b) + 1;
	if (!(st.buf = (char **) malloc(sizeof(char *) * sb)))
		return (on_crash(MALLOC_ERR));
	st.buf[sb - 1] = NULL;
	while (++st.i < sb - 1)
	{
		if (!(st.buf[st.i] = ft_strnew(sa + sb - 1)))
			return (ft_frees(st.buf, st.i));
		st.j = -1;
		while (++st.j < sa - 1)
			ft_buf_more(a, b, &st);
	}
	return (ft_join_str(st.buf, sb - 1, sa + sb));
}