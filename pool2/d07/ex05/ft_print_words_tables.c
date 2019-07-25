/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_words_tables.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 23:02:52 by darugula          #+#    #+#             */
/*   Updated: 2019/07/11 23:02:54 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (*str != 0)
	{
		ft_putchar(*str++);
	}
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (*tab[i] != 0)
	{
		ft_putstr(tab[i]);
		ft_putstr("\n");
		i++;
	}
}
