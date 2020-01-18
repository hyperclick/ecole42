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
void		set_signal_handlers();
void		clear();
void		show_selection();
void		redraw();

void		ft_exit(int ret_code);
void		init(int argc, char **argv);
void		ft_default_sig_handler(int signum);
int			process_command( char *str);

char		*replace_quoted(const char *str);
void		replace_back(char *a[]);
void		free_quoted_params(void);
char		*add_quote(char *dst, const char *prefix, const char *value);

void		move_cursor_left(int x);
void		move_cursor_right(int x);
void	move_cursor_up(int x);
void	move_cursor_down(int x);
void		inc_cursor_pos(void);
void		dec_cursor_pos(void);


void		set_keypress(void);
void		reset_keypress(void);
cc_t		get_param(int p);
void		hide_cursor();
void		show_cursor(); 
int	ft_putc(int c);

char* read_command(void);

BOOL		process_key_left(void);
BOOL		process_key_right(void);
BOOL		process_key_down(void);
BOOL		process_key_up(void);
BOOL		process_delete(void);

#endif
