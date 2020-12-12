#include "ft_printf_internal.h"

int	to_string_get_size(t_list *list)
{
	int size;
	int len;

	size = 0;
	while (list != NULL)
	{
		len = ((t_item *)list->content)->str_len;
		if (len < 0)
		{
			return (size);
		}
		size += len;
		list = list->next;
	}
	return (size);
}

char *list_to_string(t_list *list, int *size)
{
	char *r;
	char *start;
	t_item *e;
	char *last_format_end;

	*size = to_string_get_size(list);
	r = (char *)malloc(sizeof(char) * (*size + 1));
	start = r;
	last_format_end = r;
	r[*size] = 0;
	while (list != NULL)
	{
		e = (t_item *)list->content;
		if (e->str_len < 0)
		{
			*size = e->str_len;
			//r = last_format_end;
			break;
		}
		ft_strncpy(r, e->str, e->str_len);
		r += e->str_len;
		if (e->was_format)
		{
			last_format_end = r;
		}
		list = list->next;
	}
	*r = 0;
	return (start);
}