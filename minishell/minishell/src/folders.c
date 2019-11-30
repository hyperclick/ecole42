#include "minishell.h"
/*
char		**g_folders;
int		g_count;

void		free_folders()
{
	ft_free_array(g_folders, g_count);
	free(g_folders);
	g_count = 0;
	g_folders = NULL;
}



void		update_folders()
{
	free_folders();
	const char* path = env_get_value("PATH=");
	ft_putstr(path);
	g_count = ft_count_words(path, ":");
	g_folders = (char**)malloc((sizeof(char*)) * (g_count + 1));
	folders[g_count] = NULL;
	ft_split(folders, path, g_count, ":");
	printf("\npath[0] = '%s'\n", folders[0]);
}

char** get_path_folders()
{
	return (g_folders);
}
*/
char** fill_path_folders()
{
	//free_folders();
	const char* path = env_get_value("PATH");
	//ft_putstr(path);
	int count = (path == NULL) ? 0 : ft_count_words(path, ":");
	char **folders = (char**)malloc((sizeof(char*)) * (count + 1));
	folders[count] = NULL;
	ft_split(folders, path, count, ":");
	//printf("\npath[0] = '%s'\n", folders[0]);
	return (folders);
}
