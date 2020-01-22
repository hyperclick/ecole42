/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contains_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:04:34 by darugula          #+#    #+#             */
/*   Updated: 2019/09/10 11:04:36 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

BOOL		ft_contains_int(int *a, int size, int value)
{
	return (ft_int_index_of(a, size, value) < 0 ? FALSE : TRUE);
}
