/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 23:03:52 by darugula          #+#    #+#             */
/*   Updated: 2019/07/06 23:03:55 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	pow_rec(int nb, int power)
{
	if (power == 1)
	{
		return (nb);
	}
	return (nb * pow_rec(nb, --power));
}

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
	{
		return (0);
	}
	if (power == 0)
	{
		return (1);
	}
	return (pow_rec(nb, power));
}
