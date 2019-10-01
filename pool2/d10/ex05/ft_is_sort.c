/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 02:16:58 by darugula          #+#    #+#             */
/*   Updated: 2019/07/16 02:17:00 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		sorted(int a, int b, int (*f)(int, int))
{
	return (f(a, b) <= 0);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (tab <= 0 || f <= 0)
	{
		return (0);
	}
	i = 0;
	while (i < length - 1)
	{
		if (!sorted(tab[i], tab[i + 1], f))
		{
			return (0);
		}
		++i;
	}
	return (1);
}
