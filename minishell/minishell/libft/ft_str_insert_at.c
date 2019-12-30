/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert_at.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 18:08:51 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 18:08:53 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_str_insert_at(char *dst, int n, char c)
{
	char* right;
	int len;

	len = ft_strlen(dst);
	dst[len + 1] = 0;
	right = ft_strsub(dst, n, len - n);
	dst[n] = c;
	ft_strcpy(dst + n + 1, right);
	debug_printf("dst = '%s', n = %d, dst + n = '%s', len = %d, right = '%s'\n",dst, n, dst + n, len, right);
	free(right);
}
