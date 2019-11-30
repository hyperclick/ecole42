#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define MAX_CMD_LINE	255
/*
typedef struct s_minishell_data
{
	//char		**folders;
	//int		folders_count;
	//int		max_folders_count;
	//char		** env;
}				t_data;

t_data		g_data;
*/
void		env_from_array(char* env[]);
char* env_get_value(const char* key);
//char*	env_extract_value(char* env[], char* key);
void		env_free();
char** env_replace_vars(char** r, const char** a);
char** env_to_array();
void		ft_env(int argc, char* const argv[]); 
void ft_unset_env(int argc, char* const argv[]);
void	ft_set_env(int argc, char* const argv[]);

//void		free_folders();
//void		update_folders();
//char** get_path_folders();
char** fill_path_folders();

BOOL		built_in_processed(char * const args[], int count);
void fork_and_exec(char* argv[]);
//void		exec(const char* str, char* const envp[]);
void		exec2(char* argv[]);
//BOOL		is_exit(const char str[MAX_CMD_LINE]);

void		ft_exit(int ret_code);

void		cd(int argc, char* const argv[]);
void		ft_default_sig_handler(int signum);

int	process_command(char* str);
#endif