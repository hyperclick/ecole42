/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:27:21 by darugula          #+#    #+#             */
/*   Updated: 2019/07/08 15:27:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *str, int fd)
{
	int i;

	if (str == NULL)
	{
		return ;
	}
	i = 0;
	while (str[i] != 0)
	{
		ft_putchar_fd(str[i++], fd);
	}
}
