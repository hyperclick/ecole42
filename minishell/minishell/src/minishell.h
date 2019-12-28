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

BOOL		is_child(pid_t pid);
BOOL		built_in_processed(char * const args[], int count);
void fork_and_exec(char* argv[], pid_t* ppid);
BOOL		try_execute(char* filename, char* argv[], pid_t* ppid);
pid_t		exec2(char* argv[]);

pid_t get_awaited_process(); 
void set_awaited_process(pid_t pid);
void		wait_child(pid_t  pid);

void		ft_exit(int ret_code);
void		init(int argc, char** argv, char** envp);
void		cd(int argc, char* const argv[]);
void		ft_default_sig_handler(int signum);
void print_prompt();
int	process_command(const char* str);
int		process_one_command(char* cmd);

void		clean_buffer();
void		reset_keypress(void);
const char* read_line_hidden(void);



void		h_free();
BOOL		h_has_previous();
BOOL		h_has_next();
const char* h_get_current();
const char* h_get_previous();
const char* h_get_next();
void h_append(const char* content);

void pipe_free(t_list** pipe);
t_list* pipe_parse2(const char** cmds);
t_list* pipe_parse(const char* str);
void	ft_pipe(int* r, int* w); 
//pid_t pipe_exec2(t_list* p, int prev_r);
void pipe_exec(char* str);
pid_t	ft_fork();
void		exec_ve(char* argv[]);
void		exec_ve2(const char* str);
pid_t exec(char* str);


char	* replace_quoted(const char* str); 
void		replace_back(char* a[]);
void		free_quoted_params();

#endif