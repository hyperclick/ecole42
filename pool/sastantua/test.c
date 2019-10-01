/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 21:22:14 by darugula          #+#    #+#             */
/*   Updated: 2019/07/03 21:22:14 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i++]);
	}
	ft_putchar('\n');
}
void print_num(int n)
{
	if (n < 10)
	{
		ft_putchar((char)(n+'0'));
		return;
	}
	print_num(n/10);
	print_num(n%10);
}

void	sastantua(int size);


int	main(void)
{
	
	sastantua(1);
	sastantua(2);
	sastantua(5);
	return (0);
}
