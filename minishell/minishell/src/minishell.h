#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define MAX_CMD_LINE	255
t_list		*env_get_g_env(void);
const char	*env_extract_key(const char *kvp);
BOOL		env_greater_than(t_list *a, t_list *b);
void		env_free_one(void *item, size_t size);
BOOL		key_equal(char *const key, t_list *n);


void		env_from_array(char* env[]);
char		*env_get_value(const char* key);
void		env_add_new(t_list *new);
void		env_free(void);
char		**env_replace_vars(char **r, const char **a);
char		**env_to_array(void);
void		ft_env(int argc, char* const argv[]); 
void		ft_unset_env(int argc, char* const argv[]);
void		ft_set_env(int argc, char* const argv[]);


char		**fill_path_folders(void);

BOOL		is_child(pid_t pid);
BOOL		built_in_processed(char * const args[], int count);
void		fork_and_exec(char* argv[], pid_t* ppid);
BOOL		try_execute(char* filename, char* argv[], pid_t* ppid);
pid_t		exec2(char* argv[]);

pid_t		get_awaited_process(void);
void		set_awaited_process(pid_t pid);
void		wait_child(pid_t  pid);

void		ft_exit(int ret_code);
void		init(int argc, char **argv, char **envp);
void		cd(int argc, char* const argv[]);
void		ft_default_sig_handler(int signum);
void		print_prompt(void);
int			process_command(const char* str);
int			process_one_command(char* cmd);

void		clean_buffer(void);
void		reset_keypress(void);
const char	*read_line_hidden(void);


void		h_free(void);
BOOL		h_has_previous(void);
BOOL		h_has_next(void);
const char* h_get_current(void);
const char* h_get_previous(void);
const char* h_get_next(void);
void h_append(const char* content);

void pipe_free(t_list **pipe);
t_list* pipe_parse2(const char **cmds);
t_list* pipe_parse(const char* str);
void	ft_pipe(int* r, int* w); 
//pid_t pipe_exec2(t_list* p, int prev_r);
void pipe_exec(char* str);
void	close_g_fd_to_close(void);
pid_t	ft_fork(void);
void		exec_ve(char* argv[]);
void		exec_ve2(const char* str);
pid_t exec(char* str);


char	* replace_quoted(const char* str); 
void		replace_back(char* a[]);
void		free_quoted_params(void);

#endif
