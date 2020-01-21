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

# define DO_NOT_REDRAW -21
# define DO_NOT_EXIT -20

# define DEFAULT_COLOR			"\033[0m"
# define A_COLOR				"\033[31m"
# define REVERSE_VIDEO_COLOR		"\033[7m"
# define UNDERLINED				"\033[4m"

typedef struct s_table
{
	int	height;
	int width;
	char **cells;
	int	cells_count;
	int *col_widths;
	int	printed_width;
	int	active_index;
}	t_table;

extern char **g_options;
extern int g_options_count;
extern struct winsize g_size_current;
extern t_table *g_table;

char *table_to_string(t_table *t);

t_table *rebuild_table();
t_table *table_create(int rows, int cols);
void		free_table(void);

t_table *try_cols(int cols);

char		*get_cell(t_table *t, int row, int col);
int		get_offset(t_table *t, int row, int col);
int		get_last_row(t_table *t);
int		get_last_col(t_table *t);
int		get_last_row_in_col(t_table *t, int col);
int		get_last_col_in_row(t_table *t, int row);
BOOL		is_out_of_table2(t_table *t, int offset);
BOOL		is_out_of_table(t_table *t, int row, int col);
BOOL		is_empty(const char *cell);
t_coord	get_coord_by_offset(t_table *t, int offset);
t_coord	get_active_cell_coord(t_table *t);

void		redraw();

BOOL		is_active2(int offset);
BOOL		is_active(t_table *t, int i, int j);
int		get_active_cell_offset();
void		set_active_cell_offset(int offset);
void		set_active_cell(t_table *t, t_coord new_c);

void		alloc_selected(int size);
void		free_selected();
BOOL		is_selected2(int offset);
BOOL		is_selected(t_table *t, int row, int col);
void		toggle_active_cell();
void		handle_item_deleted(int offset);
void		print_selection(char **options);
BOOL		remove_if_selected(int offset);
void		select_add(int offset);
void		dump_selection();

void		set_signal_handlers();
//void		update_hw();
void		sig_winch_handler();
void		sig_tstp_handler();
void		sig_cont_handler();
void	exit_signal_handler();
void		clear();
void		show_selection();

void		ft_exit(int ret_code);
void		init(int argc, char **argv);

BOOL		process_command(char *str);
int			process_command2(char *cmd_name);

void		set_keypress(void);
void		reset_keypress(void);
cc_t		get_param(int p);
void		hide_cursor();
void		show_cursor();
void		ft_tputs(const char *str);
int	ft_putc_err(int c);

char *read_command(void);

BOOL		process_key_left(void);
BOOL		process_key_right(void);
BOOL		process_key_down(void);
BOOL		process_key_up(void);
BOOL		process_delete(void);

#endif
