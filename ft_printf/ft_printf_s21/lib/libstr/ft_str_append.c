/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_append.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:09:42 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 18:09:44 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

void	ft_str_append(char *str, const char letter)
{
	size_t	len;

	len = ft_strlen(str);
	str[len] = letter;
	str[len + 1] = 0;
}
