/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 23:59:38 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 23:59:44 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libio.h"

void	ft_putendl(const char *c)
{
	ft_putendl_fd(c, 1);
}
