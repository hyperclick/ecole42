/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/31 14:50:14 by darugula          #+#    #+#             */
/*   Updated: 2019/12/31 14:50:16 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

int		ft_vsprintf(char *dst, const char *format, va_list args_list);
char	*ft_vstprintf(int *r, const char *format, va_list args_list);
int		ft_stprintf(char *dst, const char *format, ...);
int		ft_vprintf_fd(int fd, const char *format, va_list args_list);
int		ft_printf_fd(int fd, const char *format, ...);
int		ft_printf(const char *format, ...);

#endif