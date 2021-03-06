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

int ft_sqrt(int nb);

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

void	print_num(int n)
{
	if (n < 10)
	{
		ft_putchar((char)(n+'0'));
		return;
	}
	print_num(n / 10);
	print_num(n % 10);
}

int	main(void)
{
	//char c[] = "1234567890";
	//ft_putstr(c);
	//print_num(123456789);
	ft_putchar('\n');
	int q =	ft_sqrt(-1);
	print_num(q);
	ft_putchar('\n');
	 q =	ft_fibonacci(0);
	print_num(q);
	ft_putchar('\n');
	 q =	ft_fibonacci(1);
	print_num(q);
	ft_putchar('\n');
	 q =	ft_fibonacci(2);
	print_num(q);
	ft_putchar('\n');
	q =	ft_fibonacci(3);
	print_num(q);
	ft_putchar('\n');
	q =	ft_fibonacci(4);
	print_num(q);
	ft_putchar('\n');
	q =	ft_fibonacci(5);
	print_num(q);
	ft_putchar('\n');
	//ft_putchar('\n');
	//ft_putchar((char)(q+'0'));
	return (0);
}
