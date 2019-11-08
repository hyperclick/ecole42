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
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/xattr.h>
#include <errno.h>

#include "../libft/libft.h"
#define PATH_SEPARATOR '/'
#define XATTR_SIZE 10000

#define	MAX_PATH			300//!!!todo: change to 1 and test, find actual amount
#define	MAX_FSO_IN_DIR		5000//!!!todo: change to 1 and test, find actual amount
#define	MAX_ARGS_COUNT		50

typedef struct	s_find_options
{
	BOOL recursive;//-R
	BOOL all;//-a
	BOOL almost_all; //-A
}				t_find_options;

typedef struct	s_sort_options
{
#define SORT_BY_NAME		1//default
#define SORT_BY_MOD_TIME	2//-t
#define SORT_BY_SIZE		3
	int		sort_by;
	BOOL	sort_desc;//-r
}				t_sort_options;

typedef struct	s_print_options
{
	BOOL	details;//-l
	BOOL	single_column;//-1
	BOOL	long_datetime;//-T
}				t_print_options;

typedef struct	s_full_name
{
	char		path[MAX_PATH];
	//char		folder2[MAX_PATH];
	char		name[MAX_PATH];
}					t_f_n;

typedef	struct	s_entry
{
	t_f_n		full_name;
	BOOL		is_null;
	struct stat	s;
	//struct stat	ls;
	//struct s_entry	*link_target;
}				t_entry;

typedef	struct	s_input
{
	t_entry			files[MAX_ARGS_COUNT];
	int				files_count;
	t_entry			folders[MAX_ARGS_COUNT];
	int				folders_count;
	t_find_options	find_options;
	t_sort_options	sort_options;
	t_print_options	print_options;
	int				args_count;
}				t_input;

typedef	struct	s_dir_info
{
	BOOL	any_has_xattr;
	int		max_link_len;
	int		max_size_len;
	int		max_group_len;
	int		max_user_len;
}				t_dir_info;

t_entry		try_get_target_entry(const char link_path[]);
char		*get_link_target(char *buf, const char *name, int size);
BOOL		is_null_entry(t_entry e);
t_entry		create_null_entry(void);
BOOL		need_to_show(t_entry e, t_find_options o);

BOOL		is_folder(const mode_t mode);
BOOL		is_link(const mode_t mode);
BOOL		is_char_dev(const t_entry e);
BOOL		is_block_dev(const t_entry e);
BOOL		is_absolute_path(const char *path);
t_entry		try_get_entry(const char arg[]);
t_input		parse_arguments(int c, const char* args[]);
t_entry*	sort(t_entry entries[MAX_FSO_IN_DIR], int count, t_sort_options o);
void		print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o);
//int			get_folder_entries(t_entry entries[], t_entry folder, t_find_options o);
int		get_folder_entries(t_entry **entries, t_entry folder, t_find_options o);

//void		set_cur_dir(const char *dir);
//t_entry		get_cur_dir(void);
t_f_n		create_full_name(void);
t_f_n		get_full_name(const char name[]);
#endif
