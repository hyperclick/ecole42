/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/14 21:58:25 by darugula          #+#    #+#             */
/*   Updated: 2019/07/14 21:58:37 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include <unistd.h>
# define BOOL int
# define TRUE 1
# define FALSE 0

int		str_len(char *str);
void	put_char(char c);
void	put_digit(int d);
void	put_str(char *str);
void	new_line();
void	put_dup(char *str, int n);
void	fill_with_zeroes(int *array, int len);
#endif
