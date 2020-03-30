#ifndef LIBSTR_H
# define LIBSTR_H

# include "libmem.h"

# define EMPTY_STRING ""

int				ft_contains(const char *str, char to_find);
int				ft_atoi(const char *str);
char			*ft_itoa(long long int n);
char			* ft_uitoa(unsigned long long int n);
char			*ft_itoa_base(long long int n, const char *digits);
char			* ft_itoa_base2(unsigned long long int n, const char* digits, BOOL is_negative);


void	ft_putchar_fd(int c, int fd);
void		ft_e_putstr(const char *str);
void	ft_putstr(const char *str);
void	ft_putstr_fd(char const *str, int fd);


int				ft_str_count_chars(const char *str, const char find);
void			ft_sort_strings(char *a[], int count);
BOOL			ft_starts_with(const char *str, const char c);
BOOL			ft_str_ends_with(char const *str, const char *end);
BOOL			ft_str_starts_with(char const *str, const char *start);
void			ft_str_insert_at(char *dst, int n, char c);
BOOL			ft_str_is_empty(const char *s);
int				ft_strlen(const char *s);
BOOL			ft_str_contains(const char *haystack, const char *needle);

char			*ft_str_prepend_and_free(const char *prefix, char *str);
char			*ft_prepend_and_free(const char prefix, char *str);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, int len);
char			*ft_strcpy(char *dst, const char *src);
BOOL			ft_str_equals(const char *a, const char *b);
char			 *ft_str_left_from(const char *s, char c);
char			 *ft_str_right_from(const char *s, int c);
char			 *ft_strncpy(char *dst, const char *src, size_t len);
char			 *ft_strcat(char *s1, const char *s2);
char			 *ft_strncat(char *a, const char *b, size_t n);
size_t			ft_strlcat(char *d, const char *src, size_t s);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
char *ft_str_remove_comment(const char *str, char comment);
char *ft_str_replace2(char *dst, const char *src, const char *find
	, const char *replace);
char *ft_str_replace(const char *src, const char *find
	, const char *replace);
char *ft_str_repeat(char *s, int n);
int				ft_count_words(const char *str, const char whitespaces[]);
void			ft_free_array(void **r, int n);
void			ft_free_array2(void ***r);
void			ft_free_null_term_array(void **a);
int				ft_count_null_term_array(void **a);
void		zta_remove_at(void **a, int size, int n);
char **ft_split(char **r, const char *str, int c, const char *d);
char **ft_split2(const char *str, int count, const char *sep);
char **ft_split3(const char *str, const char *sep);
char **ft_strsplit(char const *s, char c);
char *ft_strstr(const char *haystack, const char *needle);
char *ft_strnstr(const char *haystack, const char *needle, size_t l);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t len);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_is_number(char *s);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_last_index(const char *str, const char to_find);
void			ft_str_append(char *str, const char letter);
int				ft_str_index_of(const char *s, int c);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, int start, int len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strjoin2(int count, ...);
char			*ft_str_remove_at(char *dst, int n);
void			ft_swap(char *a, char *b);
char			*ft_strrev(char *str);
char			*ft_strtrim2(char const *s, char const *whitespaces);
char			*ft_strtrim(char const *s);

#endif
