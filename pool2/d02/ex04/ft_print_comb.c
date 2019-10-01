/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 03:33:31 by darugula          #+#    #+#             */
/*   Updated: 2019/07/04 03:33:35 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	process(int a, int b, int c, int *shown)
{
	if (a < b && a < c && b < c)
	{
		if (*shown == 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		ft_putchar((char)a);
		ft_putchar((char)b);
		ft_putchar((char)c);
		*shown = 1;
	}
}

void	ft_print_comb(void)
{
	int a;
	int b;
	int c;
	int shown;

	shown = 0;
	a = (int)'0';
	while (a <= (int)'9')
	{
		b = (int)'0';
		while (b <= (int)'9')
		{
			c = (int)'0';
			while (c <= (int)'9')
			{
				process(a, b, c, &shown);
				c++;
			}
			b++;
		}
		a++;
	}
	ft_putchar('\n');
}
