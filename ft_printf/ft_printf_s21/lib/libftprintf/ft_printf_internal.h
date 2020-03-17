#ifndef FT_PRINTF_INTERNAL_H

# define FT_PRINTF_INTERNAL_H

# include "libstr.h"
# include "../liblists/lists.h"
# include "../libio/libio.h"
# include "libmem.h"

# define DEFAULT_WIDTH 0
# define DEFAULT_PRECISION 0

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
	BOOL		precision_set;
	int			precision;
	char		length[3];
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
	BOOL	was_format;
	char *str;
	int		str_len;
	t_fmt	*fmt;
}				t_item;


t_list	*to_list(char *format, int *r);
BOOL	is_string(t_item*);
BOOL	is_format(t_item*);
t_item	*create_string(char *str);
t_item	*create_format(const t_fmt *fmt);
void	add_string(t_list *list, char *str);
void	add_format(t_list *list, const t_fmt *fmt);
void	free_list(t_list **list);
void	free_item(void *content);
void	free_format(t_fmt *fmt);
char	*handle_parsed(char *format, t_fmt *fmt, t_list *list, int *r, BOOL smth_parsed);
t_fmt	*get_default_format();

void	free_format(t_fmt* fmt);
t_fmt	*get_default_format();

char	*try_parse_flags(char *format, t_fmt *fmt, BOOL *parsed);
void	normalize_flags(t_fmt *fmt);
char	*try_parse_width(char *format, t_fmt *fmt); 
char	*try_parse_precision(char *format, t_fmt *fmt);
char	*try_parse_length(char* format, t_fmt* fmt);
char	*try_parse_type(char *format, t_fmt *fmt);
char	*try_extract_id(t_list* list, char* format, int* r);


void	process_width(t_fmt *fmt);
void	process_sign(t_fmt *fmt);
void	process_blank(t_fmt *fmt);
void	process_precision(t_fmt *fmt);
void	recalc_size(t_fmt* fmt);
void	process_string(t_fmt* fmt);
int		replace_args(t_list *list, va_list args_list);
int		process_type(t_fmt *fmt, va_list args_list);

BOOL	is_int_number(char t);
BOOL	is_signed_number(char t);
BOOL	is_number(char t);
BOOL	is_valid_type(char t);

void	parse_d(t_fmt* fmt, va_list args_list);
void	parse_u(t_fmt* fmt, va_list args_list);
t_fmt	*char_to_string(t_fmt *fmt, long long int c);
t_fmt	*pchar_to_string(t_fmt* fmt, const char* str);
t_fmt	*hex_to_string(t_fmt* fmt, unsigned long long int p, BOOL is_upper_case);
t_fmt	*little_hex_to_string(t_fmt *fmt, unsigned long long int p);
t_fmt	*big_hex_to_string(t_fmt *fmt, unsigned long long int p);
t_fmt	*pointer_to_string(void* p, t_fmt* fmt);
t_fmt	*oct_to_string(t_fmt* fmt, unsigned long long int n);
t_fmt	*int_to_string(t_fmt *fmt, long long int n);
t_fmt	*uint_to_string(t_fmt* fmt, unsigned long long int n);

BOOL	is_valid_length(t_fmt* fmt);
BOOL	is_zero_char(t_fmt* fmt);

char	*list_to_string(t_list *list, int *size);

#endif 