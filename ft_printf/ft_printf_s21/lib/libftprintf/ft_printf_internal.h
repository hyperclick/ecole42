#ifndef FT_PRINTF_INTERNAL_H

# define FT_PRINTF_INTERNAL_H

#include "lists.h"
# include "libstr.h"
# include "libio.h"

typedef	struct s_format_flags
{
	BOOL	is_alt_form;
	BOOL	zero_pad;
	BOOL	adjust_right;
	BOOL	blank_before_positive;
	BOOL	plus_before_positive;
}				t_fmt_flags;

typedef	struct s_format
{
	t_fmt_flags	flags;
	char		type;

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
t_fmt	*get_default_format();


void	replace_args(t_list *list, va_list args_list);

#endif 