#include "minishell.h"

static t_list* g_quoted_params = NULL;

const char paired_quote[] = "%paired_quote%";
const char unpaired_quote[] = "%unpaired_quote%";

int get_target_len(const char* str)
{
	int quotes_count = ft_str_count_chars(str, '\"');
	int digits_count = int_lg(quotes_count) + 1;
	int tokens_count = quotes_count / 2 + 1;

	int tokens_len = ft_strlen(unpaired_quote) + digits_count;
	return (ft_strlen(str) + tokens_len * tokens_count);
}

char* add_quote(char* dst, const char* prefix, const char* value)
{
	char* itoa;
	int count = dic_get_count(g_quoted_params) + 1;
	char key[200];
	ft_strcpy(key, prefix);
	itoa = ft_itoa(count);
	ft_strcpy(key + ft_strlen(prefix), itoa);
	free(itoa);
	g_quoted_params = dic_add(g_quoted_params, key, value);

	ft_strcpy(dst, key);

	debug_printf("quote replaced: '%s' -> '%s'\n", dic_get_value(g_quoted_params, key), key);
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

static void process_string(char *dst, const char *str)
{
	char param_buffer[ft_strlen(str)];
	char* p;

	while (*str != 0)
	{
		if (*str == '\"')
		{
			str++;
			p = param_buffer;
			while (*str != 0 && *str != '\"')
			{
				*p++ = *str++;
			}
			*p = 0;
			dst = (*str == 0) ? add_unpaired_quote(dst, param_buffer) : add_paired_quote(dst, param_buffer);
			if (*str == '\"')
			{
				str++;
			}
			continue;
		}
		*dst++ = *str++;
	}
	*dst++ = 0;
}

char*		replace_quoted(const char* str)
{
	char	*dst;
	int		count;

	count = get_target_len(str) + 1;
	dst = ft_strnew(count * sizeof(char));
	//dst[count - 1] = 0;
	process_string(dst, str);
	debug_printf("quotes replaced: '%s'\n", dst);
	return (dst);
}

void		replace_back_unused(char* a[])
{
	debug_printf("replace back:\n");
	debug_print_dic(g_quoted_params);
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

void		replace_back(char* a[])
{
	char **keys = dic_get_keys(g_quoted_params);
	char **keys_start = keys;
	while (*a != NULL)
	{
		debug_printf("processing %s\n", *a);
		while (*keys != NULL)
		{
			if (ft_str_contains(*a, *keys))
			{
				char* tmp = *a;
				*a = ft_str_replace(*a, *keys, dic_get_value(g_quoted_params, *keys));
				free((char*)tmp);
			}
			keys++;
		}
		keys = keys_start;
		a++;
	}
	ft_free_null_term_array((void**) keys_start);
}

void		free_quoted_params()
{
	dic_free(&g_quoted_params);
	if (g_quoted_params != NULL)
	{
		debug_printf("ERROR\n");
		exit(1);
	}
}
