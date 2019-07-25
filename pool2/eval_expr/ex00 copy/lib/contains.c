/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:42:05 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 22:42:08 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bool.h"

BOOL	contains(char *delimeters, char c)
{
	while (*delimeters != 0)
	{
		if (c == *delimeters)
		{
			return (TRUE);
		}
		++delimeters;
	}
	return (FALSE);
}
