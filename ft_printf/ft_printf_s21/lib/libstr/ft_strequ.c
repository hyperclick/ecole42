/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strequ.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:32:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 15:32:24 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

BOOL		ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
	{
		return (FALSE);
	}
	return (ft_strcmp(s1, s2) == 0 ? TRUE : FALSE);
}
