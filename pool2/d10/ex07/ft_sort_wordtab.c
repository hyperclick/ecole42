/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 21:35:49 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 21:35:51 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BOOL	int
#define FALSE	0
#define TRUE	1

int		find_len(char **tab)
{
	int		len;

	len = 0;
	while (tab[len] != 0)
	{
		++len;
	}
	return (len);
}

void	swap(char *tab[], int i, int j)
{
	char	*a;
	char	*b;

	a = tab[i];
	b = tab[j];
	tab[i] = tab[j];
	tab[j] = a;
}

void	ft_advanced_sort_wordtab(char **tab, int (*cmp)(char *, char *))
{
	BOOL	is_sorted;
	int		i;
	int		len;

	len = find_len(tab);
	is_sorted = FALSE;
	while (!is_sorted)
	{
		i = 0;
		while (i < len - 1)
		{
			is_sorted = TRUE;
			if (cmp(tab[i], tab[i + 1]) > 0)
			{
				swap(tab, i, i + 1);
				is_sorted = FALSE;
			}
			++i;
		}
	}
}

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

void	ft_sort_wordtab(char **tab)
{
	ft_advanced_sort_wordtab(tab, &ft_strcmp);
}
