/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:55:09 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:55:11 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	print_dup(char *str, int count)
{
	if (count == 0)
	{
		return ;
	}
	ft_putstr(str);
	print_dup(str, count - 1);
}
