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

BOOL		built_in_processed(char * const args[], int count);
void		cd(int argc, char* const argv[]);
void fork_and_exec(char* argv[], char* const envp[]);
//void		exec(const char* str, char* const envp[]);
void		exec2(char* argv[], char* const envp[]);
//BOOL		is_exit(const char str[MAX_CMD_LINE]);
void		ft_exit(int ret_code);
#endif