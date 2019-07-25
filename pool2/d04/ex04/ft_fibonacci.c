/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 23:32:37 by darugula          #+#    #+#             */
/*   Updated: 2019/07/06 23:32:39 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	fibonacci(int index, int a, int b)
{
	if (index == 2)
	{
		return (a + b);
	}
	return (fibonacci(index - 1, b, a + b));
}

int	ft_fibonacci(int index)
{
	if (index < 0)
	{
		return (-1);
	}
	if (index == 0)
	{
		return (0);
	}
	if (index == 1)
	{
		return (1);
	}
	return (fibonacci(index, 0, 1));
}
