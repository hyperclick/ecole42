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

#include "../libft/libft.h"
#define PATH_SEPARATOR '/'
#define XATTR_SIZE 10000

#define	MAX_PATH			300//!!!todo: change to 1 and test, find actual amount
#define	MAX_FSO_IN_DIR		100//!!!todo: change to 1 and test, find actual amount

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
	BOOL one_file_per_line;//-l
}				t_print_options;

typedef struct	s_full_name
{
	char		path[MAX_PATH];
	char		folder[MAX_PATH];
	char		name[MAX_PATH];
}					t_f_n;
typedef	struct	s_entry
{
	t_f_n		full_name;
	//char		type;
	BOOL		is_null;
	//time_t		creation_time;
	//time_t		access_time;
	//time_t		mod_time;
	//off_t		size;
	struct stat s;
	struct stat ls;
}				t_entry;

typedef	struct	s_input
{
	//t_entry			cur_dir;
	t_entry			files[MAX_FSO_IN_DIR];
	int				files_count;
	t_entry			folders[MAX_FSO_IN_DIR];
	int				folders_count;
	t_find_options	find_options;
	t_sort_options	sort_options;
	t_print_options	print_options;
}				t_input;

BOOL		is_null_entry(t_entry e);

BOOL		is_folder(const mode_t mode);
BOOL		is_link(const mode_t mode);
t_entry		try_get_entry(const char arg[]);
t_input		parse_arguments(int c, const char* args[]);
t_entry*	sort(t_entry entries[MAX_FSO_IN_DIR], int count, t_sort_options o);
void		print_entries(t_entry	entries[MAX_FSO_IN_DIR], int count, t_print_options o);
int			get_folder_entries(t_entry entries[], t_entry folder, t_find_options o);

//void		set_cur_dir(const char *dir);
//t_entry		get_cur_dir(void);
t_f_n		create_full_name(void);
t_f_n		get_full_name(const char name[]);
#endif
