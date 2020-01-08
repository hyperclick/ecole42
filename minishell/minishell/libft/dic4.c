/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:14 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:50:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*dic_get_value(t_list *dic, const char *key)
{
	t_list	*n;

	n = dic_find(dic, key);
	if (n == NULL)
	{
		ft_e_putstr("dic_get_value failed: missing key: ");
		ft_e_putstr(key);
		exit(1);
	}
	return (get_kvp(n)->value);
}
