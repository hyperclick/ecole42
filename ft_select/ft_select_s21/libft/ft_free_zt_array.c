/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:59:02 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:59:04 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_array(void **r, int n)
{
	while (n-- > 0)
	{
		free(r[n]);
	}
}

int		ft_count_null_term_array(void **a)
{
	int	count;

	count = 0;
	while (*a != NULL)
	{
		a++;
		count++;
	}
	return (count);
}

void	ft_free_array2(void ***r)
{
	ft_free_array(**r, ft_count_null_term_array(**r));
	free(*r);
	*r = NULL;
}

void	ft_free_null_term_array(void **a)
{
	ft_free_array(a, ft_count_null_term_array(a));
	free(a);
}

void		zta_remove_at(void** a, int size, int n)
{
	debug_printf("free '%s'\n", a[n]);
	free(a[n]);
	while (n < size)
	{
		a[n] = a[n + 1];
		n++;
	}
}