/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/09 15:32:17 by darugula          #+#    #+#             */
/*   Updated: 2019/07/09 15:32:24 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	if (n == 0)
	{
		return (0);
	}
	if (*s1 != *s2)
	{
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	if (*s1 == 0)
	{
		return (0);
	}
	return (ft_strncmp(s1 + 1, s2 + 1, n - 1));
}
