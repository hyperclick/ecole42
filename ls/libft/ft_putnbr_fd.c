/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 16:01:36 by darugula          #+#    #+#             */
/*   Updated: 2019/07/08 16:01:39 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_nbr_fd_rec(long long n, int fd)
{
	if (n < 10 && n > -10)
	{
		n = n < 0 ? -n : n;
		ft_putchar_fd('0' + n, fd);
		return ;
	}
	put_nbr_fd_rec(n / 10, fd);
	put_nbr_fd_rec(n % 10, fd);
}

void		ft_putnbr_fd(long long nb, int fd)
{
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	put_nbr_fd_rec(nb, fd);
}
