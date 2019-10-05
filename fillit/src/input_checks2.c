/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 12:42:03 by darugula          #+#    #+#             */
/*   Updated: 2019/10/05 12:42:11 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "tetramino.h"
#include "result_checks.h"

BOOL		is_neighbour_empty(t_t t, int row, int col)
{
	return (row < 0 || row > 4 - 1 || col < 0 || col > 4 - 1
			|| is_empty(t.a[row][col]));
}
