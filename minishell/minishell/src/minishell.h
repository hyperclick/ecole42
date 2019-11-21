#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define MAX_CMD_LINE	255

typedef struct s_minishell_data
{
	char		**folders;
	int		folders_count;
	int		max_folders_count;
}				t_data;

t_data		g_data;

BOOL		built_in_processed(const char str[MAX_CMD_LINE]);
void		exec(const char* str, char* const envp[]);
//BOOL		is_exit(const char str[MAX_CMD_LINE]);
void		ft_exit(int ret_code);
#endif