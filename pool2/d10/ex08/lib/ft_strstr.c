/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 14:15:57 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 14:16:00 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*str_str(char *str, char *to_find, int i_str, int i_to_find)
{
	if (to_find[i_to_find] == 0)
	{
		return (str + i_str - i_to_find);
	}
	if (str[i_str] == 0)
	{
		return (0);
	}
	if (str[i_str] != to_find[i_to_find])
	{
		return (str_str(str, to_find, i_to_find == 0 ? i_str + 1 : i_str, 0));
	}
	else
	{
		return (str_str(str, to_find, i_str + 1, i_to_find + 1));
	}
}

char	*ft_strstr(char *str, char *to_find)
{
	return (str_str(str, to_find, 0, 0));
}
