/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_strings.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:13:03 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:13:05 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

static BOOL	need_swap(const char a[], const char b[])
{
	return (ft_strcmp(a, b) > 0);
}

static void	swap(char a[], char b[])
{
	char	*copy_a;

	copy_a = ft_strdup(a);
	ft_strcpy(a, b);
	ft_strcpy(b, copy_a);
	free(copy_a);
}

void		ft_sort_strings(char *a[], int count)
{
	BOOL	sorted;
	int		i;

	sorted = FALSE;
	while (!sorted)
	{
		i = -1;
		sorted = TRUE;
		while (++i < count - 1)
		{
			if (need_swap(a[i], a[i + 1]))
			{
				swap(a[i], a[i + 1]);
				sorted = FALSE;
			}
		}
	}
}
