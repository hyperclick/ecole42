#ifndef DIC_H
#define DIC_H

#include "lists.h"
#include "libstr.h"
#include "libio.h"

typedef struct	s_key_value_pair
{
	char *key;
	void *value;
}				t_kvp;
t_kvp *get_kvp(t_list *n);
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

#endif
