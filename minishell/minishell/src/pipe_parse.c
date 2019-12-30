#include "minishell.h"

void pipe_free(t_list **pipe)
{
	ft_lst_free(pipe);
}

t_list* pipe_parse2(const char **cmds)
{
	t_list* head = NULL;
	t_list* prev = NULL;
	while (*cmds != NULL)
	{
		//debug_printf("cmd = '%s'\n", *cmds);
		t_list* n = ft_lst_new(ft_strtrim2(*cmds, " \t"), -1);
		//debug_printf("n = '%s'\n", (char*)n->content);
		if (head == NULL)
		{
			head = n;
		}
		if (prev != NULL)
		{
			prev->next = n;
		}
		prev = n;
		cmds++;
	}
	return (head);
}

t_list *pipe_parse(const char *str)
{
	debug_printf("pipe_parse(%s)\n", str);
	char **cmds = ft_split3(str, "|");
	debug_printf("cmd[0] = '%s'\n", cmds[0]);
	t_list* list = pipe_parse2((const char**)cmds);

	ft_free_null_term_array((void**)cmds);
	//free(cmds);
	return (list);
}


t_list * pipe_create(const char **pipes[])
{

	t_list* head = NULL;
	t_list* prev = NULL;
	while (pipes != NULL)
	{
		debug_print_zt_array(*pipes);
		t_list* n = ft_lst_new(*pipes, -1);
		debug_print_zt_array((const char**)n->content);
		if (head == NULL)
		{
			head = n;
		}
		if (prev != NULL)
		{
			prev->next = n;
		}
		prev = n;
		pipes++;
	}
	return (head);
}
