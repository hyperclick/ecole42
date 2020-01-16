/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 13:24:44 by darugula          #+#    #+#             */
/*   Updated: 2020/01/01 13:24:46 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "key_constants.h"
# include "../libft/libft.h"
# include <termcap.h>
# define TAB_LEN 4

typedef struct s_table
{
	int	height;
	int width;
	char** cells;
	int	cells_count;
	int	*col_widths;
	int	printed_width;
	int	active_index;
}	t_table;

extern char** g_options;
extern int g_options_count;
extern struct winsize size_used;
extern struct winsize g_size_current;
extern t_table	*g_table;
char		* table_to_string(t_table* t);

void		free_table(void);
t_table	*try_cols(int cols);
t_coord	get_active_cell_coord(t_table* t);
int		get_offset(t_table* t, int row, int col);
char		*fill_spaces(char* str, int n);
int		get_last_row(t_table* t);
int		get_last_col(t_table* t); 
BOOL		is_out_of_table2(t_table* t, int offset);
BOOL		is_out_of_table(t_table* t, int row, int col);

BOOL		is_active2(int offset);
BOOL		is_active(t_table* t, int i, int j);
int		get_active_cell_offset();
void		set_active_cell_offset(int offset);
void		set_active_cell(t_table* t, t_coord new_c);
void		alloc_selected(int size);
void		free_selected();
int		ft_int_index_of(int* a, int size, int value);
BOOL		ft_contains_int(int* a, int size, int value);
BOOL		is_selected2(int offset);
BOOL		is_selected(t_table* t, int row, int col);
void		toggle_active_cell();
void		print_selection(char** options);

void update_hw();
void		clear();
void		show_selection();

t_list		*env_get_g_env(void);
const char	*env_extract_key(const char *kvp);
BOOL		env_greater_than(t_list *a, t_list *b);
void		env_free_one(void *item, size_t size);
BOOL		key_equal(char *const key, t_list *n);

void		env_from_array(char *env[]);
char		*env_get_value(const char *key);
void		env_add_new(t_list *new);
void		env_free(void);
char		**env_replace_vars(char **r, const char **a);
char		**env_to_array(void);
void		ft_env(int argc, char *const argv[]);
void		ft_unset_env(int argc, char *const argv[]);
void		ft_set_env(int argc, char *const argv[]);

char		**fill_path_folders(void);

BOOL		built_in_processed(char *const args[], int count);
pid_t		exec2(const char *argv[]);

pid_t		get_awaited_process(void);
void		set_awaited_process(pid_t pid);

void		ft_exit(int ret_code);
void		init(int argc, char **argv, char **envp);
void		ft_default_sig_handler(int signum);
int			process_command( char *str);
int			process_commands(char *s);
void		free_commands(void);

void		clean_buffer(void);
int			get_buf_len(void);
char	* read_command(void);

void		h_free(void);
BOOL		h_has_previous(void);
BOOL		h_has_next(void);
const char	*h_get_current(void);
const char	*h_get_previous(void);
const char	*h_get_next(void);
void		h_append(const char *content);

void		pipe_free(t_list **pipe);
BOOL		has_exit(const char *str);
t_list		*pipe_parse2(const char **cmds);
t_list		*pipe_parse(const char *str);
void		pipe_exec(char *str);
void		exec_ve(const char *argv[]);
void		exec_ve2(const char *str);
pid_t		exec(char *str);

void		close_g_fd_to_close(void);
void		pipe_set_fd_to_close(int fd);

char		*replace_quoted(const char *str);
void		replace_back(char *a[]);
void		free_quoted_params(void);
char		*add_quote(char *dst, const char *prefix, const char *value);

void		buffer_changed(void);
int			get_g_x(void);
int			get_act_x(void);
void		move_cursor_left(int x);
void		move_cursor_right(int x);
void	move_cursor_up(int x);
void	move_cursor_down(int x);
void		backspace(int x);
void		inc_cursor_pos(void);
void		dec_cursor_pos(void);
void		move_to_bol(void);
int			get_printed_buf_len(void);

void		set_keypress(void);
void		reset_keypress(void);
cc_t		get_param(int p);

void		set_buf_len(int len);
int			get_buf_len(void);
int			get_printed_buf_len(void);
const char	*get_buffer(void);
void		increase_buffer(void);
void		decrease_buffer(void);
void		clean_printed_text(void);
void		clean_printed_text_and_move_cursor_left(void);
void		buffer_print(void);
void		clean_buffer(void);
void		buffer_set(const char *new_value);
void		buffer_delete(void);
void		buffer_backspace(void);
void		buffer_insert(char c);
char		get_previous_char(void);
char		get_next_char(void);
char		get_char_at_cursor(void);

BOOL		process_key_left(void);
BOOL		process_key_right(void);
BOOL		process_key_down(void);
BOOL		process_key_up(void);
BOOL		process_backspace(void);
BOOL		process_tab(void);
BOOL		process_delete(void);
void		process_printable(char c);
void		process_not_printable(char control[10], int c);

void		dump_buffer(void);

#endif
