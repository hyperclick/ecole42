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

# include "../ft_printf_internal.h"

# define MAXWIDHT		2147483640

# define DI				s[*i] == 'd' || s[*i] == 'i'
# define UU				s[*i] == 'u' || s[*i] == 'U'
# define OXX			s[*i] == 'o' || s[*i] == 'x' || s[*i] == 'X'
# define CSP			s[*i] == 'c' || s[*i] == 's' || s[*i] == 'p'
# define F				s[*i] == 'f'
# define NUM			s[*i] >= '0' && s[*i] <= '9'
# define PREC			s[*i] == 'l' || s[*i] == 'L'
# define PREC2			s[*i] == 'h' || s[*i] == 'j' || s[*i] == 'z'
# define SIGN			s[*i] == '-' || s[*i] == '+' || s[*i] == '#'
# define SIGN2			s[*i] == '.' || s[*i] == '*'
# define NUL			s[*i] == ' ' || s[*i] == '0'
# define TYPE			DI || UU || OXX || CSP || F || s[*i] == '%'

enum				e_error
{
	MALLOC_ERR = 0,
};

typedef union			u_double
{
	struct
	{
		unsigned long	m: 64;
		unsigned int	e: 15;
		unsigned int	s: 1;
	}					bits;
	long double			num;
	int					prec;
	int 				length;
	char 				*str;
	int 				count;
	unsigned char		byte[10];
}						t_double;

typedef struct			s_join
{
	char				**buf;
	int					i;
	int					j;
}						t_join;

union					u_bin
{
	int					i;
	unsigned char		byte[4];
};

void					ft_precision(t_double *pnf, const char *s, long long *i, va_list *ap);
char					*ft_do_union(int sign);
void					ft_bits(unsigned char num, unsigned char *str);
static char				*ft_between(t_double *floats, char **s, int exp);
static char				*ft_more(t_double *floats, char **s);
static char				*ft_low(t_double *floats, char **s);
static char				*ft_final_str(const unsigned char *bin_deg, char *res, int sigi,
										 int sign);
char					*ft_final_str_from_2(t_double *floats, char *tmp1, char *tmp2);
void					ft_change_prec(t_double *floats, char *tmp1, char *tmp2, int len);
char					*ft_sum_to_str(t_double *s, char **buf, int strs, size_t len, int sign);
char					*ft_join(char *a, char *b);
char					*ft_frees(char **obj, int strs);
char 					*ft_free(char *str1, char *str2);
void					*on_crash(int err);

#endif