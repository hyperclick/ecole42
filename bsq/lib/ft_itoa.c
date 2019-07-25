/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:49:42 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:49:49 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bool.h"

char	*uitoa(unsigned int n, char *r)
{
	if (n < 10)
	{
		*r = (char)('0' + n);
		r++;
		return (r);
	}
	return (uitoa(n % 10, uitoa(n / 10, r)));
}

char	*ft_itoa(int n, char *r)
{
	char *str;

	str = r;
	if (n < 0)
	{
		*r = '-';
		r++;
		n = -n;
	}
	r = uitoa(n, r);
	*r = '\0';
	return (str);
}
