/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_putstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:27:21 by darugula          #+#    #+#             */
/*   Updated: 2019/07/08 15:27:25 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void		ft_e_putstr(const char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
}

void		ft_e_ft_putstr_and_free(char *str)
{
	ft_e_putstr(str);
	free(str);
}
