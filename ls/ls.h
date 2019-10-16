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

#define BOOL    unsigned char
#define TRUE    1
#define FALSE   0
#define XATTR_SIZE 10000

#define	MAX_PATH	        10000//!!!todo: change to 1 and test, find actual amount
#define	MAX_FSO_IN_DIR		10000//!!!todo: change to 1 and test, find actual amount

typedef struct s_find_options
{

}               t_find_ptions;

typedef struct s_sort_options
{

}               t_sort_options;

typedef struct s_print_options
{

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
}				t_entry;

typedef	struct	s_input
{
	t_entry files[MAX_FSO_IN_DIR];
	t_entry folders[MAX_FSO_IN_DIR];
	t_find_ptions	find_options;
	t_sort_options	sort_options;
	t_print_options	print_options;
}				t_input;

#endif