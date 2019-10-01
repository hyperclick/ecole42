/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 22:32:51 by darugula          #+#    #+#             */
/*   Updated: 2019/07/06 22:33:04 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	factorial(int n)
{
	if (n == 1)
	{
		return (1);
	}
	return (n * factorial(n - 1));
}

int	ft_recursive_factorial(int nb)
{
	if (nb <= 0 || nb > 12)
	{
		return (0);
	}
	return (factorial(nb));
}
