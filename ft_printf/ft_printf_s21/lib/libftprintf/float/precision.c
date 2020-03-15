/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:23:01 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:23:05 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "float.h"

void	ft_read(int *j, const char *s, long long *i)
{
	char	*buf;
	char	*tmp;
	char	c[2];

	c[1] = '\0';
	if (!(buf = ft_strnew(0)))
		exit(0);
	while (s[*i] >= '0' && s[*i] <= '9')
	{
		tmp = buf;
		c[0] = s[(*i)++];
		if (!(buf = ft_strjoin(tmp, &c[0])))
			exit(0);
		free(tmp);
		*j = ft_atoi(buf);
		if (*j > MAXWIDHT)
		{
			free(buf);
			exit(0);
		}
	}
	--(*i);
	free(buf);
}

void	ft_precision(t_double *pnf, const char *s, long long *i, va_list *ap)
{
	(*i) = 0;
	while (!(TYPE) && (SIGN || SIGN2 || NUL || PREC || PREC2 || (NUM)))
	{
		if (s[*i] == '.')
		{
			pnf->prec = -1;
			++(*i);
			if (s[*i] == '*')
			{
				++(*i);
				pnf->prec = va_arg(*ap, int);
				if (pnf->prec > MAXWIDHT)
					exit(0);
			}
			else if (s[*i] >= '0' && s[*i] <= '9')
				ft_read(&pnf->prec, s, i);
			if (pnf->prec == -1)
				pnf->prec = 0;
		}
		(*i)++;
	}
}
