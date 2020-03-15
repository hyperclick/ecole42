/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepend_and_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:09:42 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 18:09:44 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libstr.h"

char *ft_str_prepend_and_free(const char *prefix, char *str)
{
	char *tmp;

	tmp = str;
	str = ft_strjoin(prefix, str);
	free(tmp);
	return (str);
}

char *ft_prepend_and_free(const char prefix, char *str)
{
	char tmp[] = " ";

	*tmp = prefix;
	return (ft_str_prepend_and_free(tmp, str));
}