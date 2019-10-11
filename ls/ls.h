#ifndef LS_H
# define LS_H

# include "libft.h"

#include <dirent.h>

#define MAX_BUFFER	1000
#define MAX_NAME	MAX_BUFFER
#define MAX_FSO_IN_DIR	1000

typedef struct	g_file
{
	char		name[MAX_NAME];
}				t_file;

typedef struct	g_directory
{
	char		name[MAX_NAME];
	DIR	dirs[1];
	t_file		files[MAX_FSO_IN_DIR];
}				t_dir;

typedef struct s_find
{
	char	pattern[MAX_BUFFER];
} g_find;

typedef struct s_sort
{
	char	pattern[MAX_BUFFER];
} g_sort;

typedef struct s_format
{
	char	pattern[MAX_BUFFER];
} g_format;

typedef struct s_print
{
	char	pattern[MAX_BUFFER];
} g_print;

typedef struct s_input
{
	char		path[MAX_BUFFER];
	char		search_string[MAX_BUFFER];
	g_find		find;
	g_sort		sort;
	g_format	format;
	g_print		print;
} g_input;

#endif
