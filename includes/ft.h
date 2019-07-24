/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 21:53:10 by darugula          #+#    #+#             */
/*   Updated: 2019/07/21 21:53:15 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include "bool.h"
# include <limits.h>

extern const int	g_last_int;

void	ft_putchar(char c);
void	new_line();
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strlen(char *str);
char	*ft_concat(char *dst, char *a, char *b);
char	*ft_concat3(char *dst, char *a, char *b, char *c);
void	print_dup(char *str, int count);
int		ft_str_is_alpha(char *str);
int		count_words(char *str, char *delimeters);
BOOL	is_end_of_string_array(char *str);
char	**split(char *str, int *len, char *delimeters);
int		ft_count_char(const char *str, const char c);
int		get_lenght_of_string_array(char *a[]);
char	**split_char(char *src[], char to_split);
int		is_digit(char c);
BOOL	starts_with_number(char *str);
BOOL	is_number(char *str);
char	*ft_itoa(int n, char *r);
int		ft_atoi(char *str);
void	ft_foreach(int *tab, int length, void (*f)(int));
void	print_params(int argc, char **argv, int i);
BOOL	contains(char *delimeters, char c);
void	print_string_array(char *a[]);
char	**make_string_array(char *dst[], char *str, ...);
int		*convert_to_int_array(int dst[], char	*a[]);
void	print_int_array(int a[]);

void	print_to_out(int fd, char *str);
void	_logger(char *logger, char *str);
void	_log(char *str);
void	_log2(char *a, char *b);
void	create_directory(char *path);

void	*m_alloc(int size, char *name);
void	m_free(void *p, char *name);
int		m_get_count();

#endif
