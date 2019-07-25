/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 04:54:48 by darugula          #+#    #+#             */
/*   Updated: 2019/07/04 04:54:53 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	show_comma(int number_shown)
{
	if (number_shown == 1)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

int		should_show(int x, int y)
{
	if (x >= y)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	process(int a, int b, int c, int d)
{
	ft_putchar((char)a);
	ft_putchar((char)b);
	ft_putchar(' ');
	ft_putchar((char)c);
	ft_putchar((char)d);
}

void	process_second_number(int a, int b, int *number_shown)
{
	int c;
	int d;

	c = (int)'0';
	while (c <= (int)'9')
	{
		d = (int)'0';
		while (d <= (int)'9')
		{
			if (should_show(a * 10 + b, c * 10 + d) == 1)
			{
				show_comma(*number_shown);
				process(a, b, c, d);
				*number_shown = 1;
			}
			d++;
		}
		c++;
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int number_shown;

	number_shown = 0;
	a = (int)'0';
	while (a <= (int)'9')
	{
		b = (int)'0';
		while (b <= (int)'9')
		{
			process_second_number(a, b, &number_shown);
			b++;
		}
		a++;
	}
	ft_putchar('\n');
}
