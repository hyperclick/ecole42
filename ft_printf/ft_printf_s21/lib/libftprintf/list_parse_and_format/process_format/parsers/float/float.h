/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plettie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 15:21:43 by plettie           #+#    #+#             */
/*   Updated: 2020/02/24 15:21:53 by plettie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FLOAT_H
#define PRINTF_FLOAT_H

#include <stdarg.h>
#include <stdlib.h>
# include "../../../../ft_printf_internal.h"

enum				e_error
{
	MALLOC_ERR = 0,
};

typedef struct			u_double
{
	struct
	{
		unsigned long	m : 64;
		unsigned int	e : 15;
		unsigned int	s : 1;
	}					bits;
	long double			num;
	int					prec;
	int 				length;
	char *str;
	int 				count;
	unsigned char		byte[10];
}						t_double;

typedef struct			s_join
{
	char **buf;
	int					i;
	int					j;
}						t_join;

union					u_bin
{
	int					i;
	unsigned char		byte[4];
};

char				*to_string(long double num);
char				*ft_printf_f(t_double *count, long double num);
char				*ft_do_union(int sign);
void				ft_bits(unsigned char num, unsigned char *str);
char *ft_do_str(t_double *floats, int exp, const unsigned char *man);
char				*ft_between(t_double *floats, char **s, int exp);
char				*ft_more(t_double *floats, char **s);
char				*ft_low(t_double *floats, char **s);
char				*ft_final_str(const unsigned char *bin_deg, char *res, int sigi,
	int sign);
char				*ft_final_str_from_2(t_double *floats, char *tmp1, char *tmp2);
void				ft_change_prec(t_double *floats, char *tmp1, char *tmp2, int len);
char				*ft_sum_to_str(t_double *s, char **buf, int strs, size_t len, int sign);
char				*ft_frees(char **obj, int strs);
char				*ft_free(char *str1, char *str2);
void				*on_crash(int err);

#endif