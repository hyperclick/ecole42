/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 00:28:18 by darugula          #+#    #+#             */
/*   Updated: 2019/07/04 00:28:23 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_print_numbers(void)
{
	int c;

	c = (int)'0';
	while (c <= (int)'9')
	{
		ft_putchar((char)c++);
	}
	ft_putchar('\n');
}