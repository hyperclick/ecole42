#include "minishell.h"

static t_list* g_quoted_params = NULL;

const char paired_quote[] = "%paired_quote%";
const char unpaired_quote[] = "%unpaired_quote%";

int get_target_len(const char* str)
{
	int quotes_count = ft_str_count_chars(str, '\"');
	int digits_count = int_lg(quotes_count) + 1;
	int tokens_count = quotes_count / 2 + 1 + digits_count;
	return (tokens_count);
}

char* add_quote(char* dst, const char* prefix, const char* value)
{
	int count = dic_get_count(g_quoted_params) + 1;
	char key[20];
	ft_strcpy(key, prefix);
	ft_strcpy(key + ft_strlen(prefix), ft_itoa(count));
	g_quoted_params = dic_add(g_quoted_params, key, value);

	ft_strcpy(dst, key);
	//debug_printf("quote replaced: '%s'\n", dst);
	return (dst + ft_strlen(key));
}
char* add_unpaired_quote(char* dst, const char* value)
{
	return (add_quote(dst, unpaired_quote, value));
}

char* add_paired_quote(char* dst, const char* value)
{
	return (add_quote(dst, paired_quote, value));
}

char* replace_quoted(const char* str)
{
	char param_buffer[ft_strlen(str)];
	char* param_start = param_buffer;
	char* p = param_buffer;
	char* dst;
	dst = (char*)malloc(get_target_len(str) * sizeof(char));
	char* dst_start = dst;
	while (*str != 0)
	{
		if (*str == '\"')
		{
			str++;
			p = param_start;
			while (*str != 0 && *str != '\"')
			{
				*p++ = *str++;
			}
			*p = 0;
			dst = (*str == 0) ? add_unpaired_quote(dst, param_start) : add_paired_quote(dst, param_start);
			//			debug_printf("dst_start = %s, str = %s\n", dst_start, str);
			if (*str == '\"')
			{
				str++;
			}
			continue;
		}
		*dst++ = *str++;
	}
	*dst++ = 0;
	debug_print_dic(g_quoted_params);
	return (dst_start);
}

void		replace_back(char* a[])
{
	while (*a != NULL)
	{
		if (dic_contains_key(g_quoted_params, *a))
		{
			char* tmp = *a;
			debug_printf("replace %s -> %s\n", *a, dic_get_value(g_quoted_params, *a));
			*a = ft_strdup(dic_get_value(g_quoted_params, *a));
			free((char*)tmp);
		}
		a++;
	}
}

void		free_quoted_params()
{
	dic_free(&g_quoted_params);
}