/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darugula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 12:48:50 by darugula          #+#    #+#             */
/*   Updated: 2019/11/08 12:48:51 by darugula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_H
# define LS_H
# include <sys/types.h>
# include <dirent.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <errno.h>

# include "../libft/libft.h"
# define PATH_SEPARATOR '/'
# define XATTR_SIZE			10000

# define MAX_PATH			300
# define MAX_FSO_IN_DIR		5000
# define MAX_ARGS_COUNT		50

# define SORT_BY_NAME		1
# define SORT_BY_MOD_TIME	2
# define SORT_BY_SIZE		3

typedef struct				s_find_options
{
	BOOL					recursive;
	BOOL					all;
	BOOL					almost_all;
}							t_find_options;

typedef struct				s_sort_options
{
	int						sort_by;
	BOOL					sort_desc;
}							t_sort_options;

typedef struct				s_print_options
{
	BOOL					details;
	BOOL					single_column;
	BOOL					long_datetime;
}							t_print_options;

typedef struct				s_full_name
{
	char					path[MAX_PATH];
	char					name[MAX_PATH];
}							t_f_n;

typedef struct				s_entry
{
	t_f_n					full_name;
	BOOL					is_null;
	struct stat				s;
}							t_entry;

typedef struct				s_input
{
	t_entry					files[MAX_ARGS_COUNT];
	int						files_count;
	t_entry					folders[MAX_ARGS_COUNT];
	int						folders_count;
	t_find_options			find_options;
	t_sort_options			sort_options;
	t_print_options			print_options;
	int						args_count;
}							t_input;

typedef	struct				s_dir_info
{
	BOOL					any_has_xattr;
	BOOL					dir_with_bc;
	size_t					max_links_len;
	size_t					max_size_len;
	size_t					max_group_len;
	size_t					max_user_len;
	size_t					max_major_len;
	size_t					max_minor_len;
}							t_dir_info;

struct						s_parse_params
{
	const char				**args;
	int						count;
	t_input					*input;
	int						missing_entries_count;
};

t_entry						try_get_target_entry(const char link_path[]);
char						*get_link_target(char *buf, \
											const char *name, int size);
BOOL						is_null_entry(t_entry e);
t_entry						create_null_entry(void);
BOOL						need_to_show(t_entry e, t_find_options o);
BOOL						is_folder(const mode_t mode);
BOOL						is_link(const mode_t mode);
BOOL						is_char_dev(const t_entry e);
BOOL						is_block_dev(const t_entry e);
BOOL						is_absolute_path(const char *path);
t_entry						try_get_entry(const char arg[]);
t_input						parse_arguments(int c, const char *args[]);
void						parse_arguments_add_entry(
								t_input *input, t_entry e);
BOOL						parse_flag(t_input *input, const char f);
t_input						create_empty_input(void);
void						process_links(t_input *input);
t_entry						*sort(t_entry entries[MAX_FSO_IN_DIR], \
								int count, t_sort_options o);
void						print_folders(t_entry folders[], \
										int count, t_input input);
void						print_entries(t_entry	entries[], \
										int count, t_print_options o);
void						print_no_such_files(char *files[], int count);
int							get_folder_entries(
						t_entry **entries, t_entry folder, t_find_options o);
t_f_n						create_full_name(void);
t_f_n						get_full_name(const char name[]);
BOOL						is_cur_dir(const char name[]);
BOOL						is_parent_dir(const char name[]);
#endif
