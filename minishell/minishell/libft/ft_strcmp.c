/*_**************************************************************************_*/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:32:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 15:32:24 by darugula         ###   ########.fr       */
/*                                                                            */
/*_**************************************************************************_*/

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	return (ft_strncmp(s1, s2, MAX(ft_strlen(s1), ft_strlen(s2)) + 1));
}

BOOL ft_str_greater_than(const char* a, const char* b)
{
	return (ft_strcmp(a, b));
}