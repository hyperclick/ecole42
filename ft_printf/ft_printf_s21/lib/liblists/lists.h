#ifndef LISTS_H

# define LISTS_H
# include <stdlib.h>

# define BOOL int

typedef struct	s_list
{
	void *content;
	size_t			content_size;
	struct s_list *next;
}				t_list;

typedef struct	s_double_list
{
	struct s_list			list;
	struct s_double_list *prev;
}				t_d_list;

int				lst_count(t_list *lst);
int				lst_count_if(t_list *lst, BOOL (*predicate)(void *));
t_list			*lst_new(void const *content, size_t content_size);
t_d_list		*dlst_new(void const *content, size_t content_size);
void			lstdelone(t_list **alst, void (*del)(void *));
void			lstdel(t_list **alst, void (*del)(void *));
void			lstadd(t_list **alst, t_list *new);
t_list			*lst_find(t_list *lst, void *p, BOOL(*f)(t_list *, void *));
void			lst_free_item(void *item);
void			lst_free(t_list **head);
t_list			*lst_get_last(t_list *lst);
void			*lst_reduce(t_list *lst, void (*f)(t_list *, void *), void *a);
void			lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			lst_insert_after(t_list *node, t_list *new);
void			lst_insert_sorted(t_list **list, t_list *new
			, BOOL(grater_than)(t_list *a, t_list *b));
void			lst_remove_sorted(t_list **list, t_list *to_remove
			, BOOL(equal)(t_list *a, t_list *b)
			, void (*free_content)(void *));
t_list		*lst_get_last(t_list *n);
void			lst_append(t_list *node, t_list *new);

#endif