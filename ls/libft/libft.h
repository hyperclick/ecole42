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
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <string.h>

# define BOOL int
# define FALSE 0
# define TRUE 1
# define MAX(a, b) a > b ? a : b
# define MIN(a, b) a > b ? b : a
# define MAX_UNSIGNED_VALUE(T) (T)((T) - 1)
# define MAX_SIZE_T MAX_UNSIGNED_VALUE(size_t)

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;
t_list			*ft_lstnew(void const *content, size_t content_size);
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


int		ft_last_index(const char* str, const char to_find);
void			*ft_memset (void *ptr, int value, size_t num);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *d, const void *s, size_t n);
void			*ft_memccpy(void *d, const void *s, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strndup(const char *s1, size_t len);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *a, const char *b, size_t n);
size_t			ft_strlcat(char *d, const char *src, size_t s);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
int				ft_count_words(const char *str, const char whitespaces[]);
char			**ft_split(char **r, const char *str, int c, const char *d);
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
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
void			ft_str_append(char	*str, const char letter);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_str_remove_at(char *dst, int n);
char			*ft_strtrim(char const *s);
int				ft_sqrt_up(int a);
char			*ft_itoa(int n);
void			ft_putchar(int c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(int c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
int				ft_contains(const char *str, char to_find);
int				ft_atoi(const char *str);
#endif
