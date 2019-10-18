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

#include "libft.h"
#define PATH_SEPARATOR '/'
#define XATTR_SIZE 10000

#define	MAX_PATH	        100//!!!todo: change to 1 and test, find actual amount
#define	MAX_FSO_IN_DIR		100//!!!todo: change to 1 and test, find actual amount

typedef struct s_find_options
{
	BOOL recursive;//-R
	BOOL show_hidden;//-a
}               t_find_options;

typedef struct s_sort_options
{
	BOOL sort_asc;
}               t_sort_options;

typedef struct s_print_options
{
	BOOL show_details;//-l
}               t_print_options;

typedef struct s_full_name
{
	char		path[MAX_PATH];
	char		folder[MAX_PATH];
	char		name[MAX_PATH];
}					t_f_n;
typedef	struct	s_entry
{
	t_f_n	full_name;
	BOOL		is_folder;
	BOOL        is_null;
}				t_entry;

typedef	struct	s_input
{
	t_entry files[MAX_FSO_IN_DIR];
	int     files_count;
	t_entry folders[MAX_FSO_IN_DIR];
	int     folders_count;
	t_find_options	find_options;
	t_sort_options	sort_options;
	t_print_options	print_options;
}				t_input;

BOOL is_null_entry(t_entry e);



t_entry try_get_entry(const char    arg[]);
t_input	parse_arguments(int c, const char *args[]);
t_entry *sort(t_entry entries[MAX_FSO_IN_DIR], t_sort_options o);
void    print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o);
int		get_folder_entries(t_entry entries[], t_entry folder, t_find_options o);
#endif