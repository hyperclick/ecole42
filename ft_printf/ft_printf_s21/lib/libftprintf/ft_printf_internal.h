﻿#ifndef FT_PRINTF_INTERNAL_H

# define FT_PRINTF_INTERNAL_H

#include "lists.h"
# include "libstr.h"
# include "libio.h"
# include "libmem.h"

# define DEFAULT_WIDTH 0
# define DEFAULT_PRECISION -1

typedef	struct s_format_flags
{
	BOOL	is_alt_form;
	BOOL	zero_pad;
	BOOL	adjust_left;
	BOOL	blank_before_positive;
	BOOL	plus_before_positive;
}				t_fmt_flags;

typedef	struct s_format
{
	t_fmt_flags	flags;
	int			width;
	int			precision;
	char		type;
	//BOOL		value_is_negative;
	char		* prefix;
	char		* value;
	char		* pad_left;
	char		* pad_right;
	int			size;
}				t_fmt;

typedef	struct s_format_or_string
{
	//BOOL	is_string;
	char *str;
	int		str_len;
	t_fmt	*fmt;
}				t_item;
BOOL	is_string(t_item*);
BOOL	is_format(t_item*);
t_item *create_string(const char *str);
t_item *create_format(const t_fmt *fmt);
void	add_string(t_list *list, const char *str);
void	add_format(t_list *list, const t_fmt *fmt);
void	free_list(t_list **list);
int		count_format(t_list *list);

void	free_format(t_fmt* fmt);
t_fmt	*get_default_format();

char	*try_parse_flags(char *format, t_fmt *fmt);
void	normalize_flags(t_fmt *fmt);
char	*try_parse_type(char *format, t_fmt *fmt);
char *try_parse_width(char *format, t_fmt *fmt); 
char *try_parse_precision(char *format, t_fmt *fmt);

int		recalc_size(t_fmt* fmt);

void	replace_args(t_list *list, va_list args_list);

BOOL	is_int_number(char t);
BOOL	is_signed_number(char t);
BOOL	is_number(char t);
BOOL	is_valid_type(char t);

t_fmt* char_to_string(t_fmt* fmt, char c);
t_fmt* pchar_to_string(t_fmt* fmt, const char* str);
t_fmt* hex_to_string(long long p, BOOL is_upper_case, t_fmt* fmt);
t_fmt* pointer_to_string(void* p, t_fmt* fmt);
t_fmt* oct_to_string(uint p, t_fmt* fmt);
t_fmt* int_to_string(t_fmt* fmt, int n);
t_fmt* uint_to_string(t_fmt* fmt, uint n);

char* ft_str_prepend_and_free(const char* prefix, char* str);

#endif 