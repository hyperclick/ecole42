/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:20:33 by darugula          #+#    #+#             */
/*   Updated: 2019/09/06 10:20:38 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

//# include <stdio.h>

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdarg.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <sys/wait.h>
# include <termios.h>
# include <signal.h>

# define BOOL int
# define FALSE 0
# define TRUE 1
# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a > b ? b : a
# define MAX_UNSIGNED_VALUE(T) (T)((T) - 1)
# define MAX_SIZE_T MAX_UNSIGNED_VALUE(size_t)
# define PATH_SEPARATOR '/'

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

typedef struct	s_double_list
{
	struct s_list			list;
	struct s_double_list	*prev;
}				t_d_list;

t_list			*ft_lst_new(void const *content, size_t content_size);
t_d_list		*ft_dlst_new(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
t_list			*ft_lst_find(t_list *lst, void *p, BOOL (*f)(t_list*, void*));
void			ft_lst_free_item(void *item, size_t size);
void			ft_lst_free(t_list **head);
void			*ft_lst_reduce(t_list *lst, void (*f)(t_list*, void*), void *a);
int				ft_lst_count(t_list *lst);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_lst_insert_after(t_list *node, t_list *new);
void			ft_lst_insert_sorted(t_list **list, t_list *new
									, BOOL (grater_than)(t_list *a, t_list *b));
void			ft_lst_remove_sorted(t_list **list, t_list *to_remove
	, BOOL(equal)(t_list *a, t_list *b)
	, void (*free_content)(void*, size_t));
t_list			*ft_lst_get_last(t_list *n);
void			ft_lst_append(t_list *node, t_list *new);

typedef struct	s_key_value_pair
{
	char			*key;
	void			*value;
}				t_kvp;
t_kvp			*get_kvp(t_list *n);
BOOL			dic_is_empty(t_list *dic);
int				dic_get_count(t_list *dic);
t_list			*dic_find(t_list *dic, const char *key);
BOOL			dic_contains_key(t_list *dic, const char *key);
BOOL			ft_str_greater_than(const char *a, const char *b);
t_list			*dic_add(t_list *dic, const char *key, const char *value);
void			dic_free(t_list **dic);
t_list			*dic_remove(t_list *dic, const char *key);
void			dic_replace(t_list *dic, const char *key, const char *value);
const char		*dic_get_value(t_list *dic, const char *key);
char			**dic_get_keys(t_list *dic);
t_kvp			**dic_get_kvps(t_list *dic);

void			close_fd(int fd);
void			redirect(int from, int to);
void			save_stdin(void);
void			restore_stdin(void);
void			restore_stdout(void);
void			save_stdout(void);

void			assert_is_null(void *p);
void			assert_is_not_null(void *p);
void			assert_true(BOOL b);
void			assert_false(BOOL b);
void			assert_int_equals(int e, int a);
void			assert_str_equals(const char *e, const char *a);

pid_t			ft_fork(void);
BOOL			is_child(pid_t pid);
void			ft_pipe(int *r, int *w);
void			wait_child(pid_t pid);

int				int_lg(int n);

void			close_out_stream(void);
//void			set_out_stream(FILE *stream);
void			set_out_file(const char *filename);
void			set_level(int level);
void			debug_set_pname(const char name[]);
void			debug_printf(const char *str, ...);
void			debug_print_zt_array(const char *a[]);
void			debug_print_dic(t_list *dic);

void			ft_e_putstr(const char *str);
void			ft_e_ft_putstr_and_free(char *str);
BOOL			ft_ends_with(const char *str, const char c);
int				ft_last_index(const char *str, const char to_find);
void			*ft_memset (void *ptr, int value, size_t num);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *d, const void *s, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			ft_readline(char *dst, int size);

int				ft_str_count_chars(const char *str, const char find);
void			ft_sort_strings(char *a[], int count);
BOOL			ft_starts_with(const char *str, const char c);
BOOL			ft_str_starts_with(char const *str, const char *start);
void			ft_str_insert_at(char *dst, int n, char c);
BOOL			ft_str_is_empty(const char *s);
int				ft_strlen(const char *s);
BOOL			ft_str_contains(const char *haystack, const char *needle);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, int len);
char			*ft_strcpy(char *dst, const char *src);
BOOL			ft_str_equals(const char *a, const char *b);
char			*ft_str_left_from(const char *s, char c);
char			*ft_str_right_from(const char *s, int c);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *a, const char *b, size_t n);
size_t			ft_strlcat(char *d, const char *src, size_t s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_str_remove_comment(const char *str, char comment);
char			*ft_str_replace2(char *dst, const char *src, const char *find
							, const char *replace);
char			*ft_str_replace(const char *src, const char *find
							, const char *replace);
int				ft_count_words(const char *str, const char whitespaces[]);
void			ft_free_array(void **r, int n);
void			ft_free_array2(void ***r);
void			ft_free_null_term_array(void **a);
int				ft_count_null_term_array(void **a);
char			**ft_split(char **r, const char *str, int c, const char *d);
char			**ft_split2(const char *str, int count, const char *sep);
char			**ft_split3(const char *str, const char *sep);
char			**ft_strsplit(char const *s, char c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle, size_t l);
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
void			log_log(const char *str);
void			log_line(const char *str);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_str_append(char	*str, const char letter);
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
char			*ft_strtrim2(char const *s, char const *whitespaces);
char			*ft_strtrim(char const *s);
int				ft_sqrt_up(int a);
char			*ft_itoa(long long n);
void			ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(long long n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(long long n, int fd);
int				ft_contains(const char *str, char to_find);
int				ft_atoi(const char *str);

void			ft_vprintf_fd(int fd, const char* format, va_list args_list);
void			ft_printf_fd(int fd, const char* format, ...);
void			ft_printf(const char* format, ...);
int				count_tokens(const char* str);
#endif
