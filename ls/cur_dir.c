#include "ls.h"

t_entry	g_cur_dir;

void	set_cur_dir(const char *dir)
{
	g_cur_dir = try_get_entry(dir);
}

t_entry	get_cur_dir()
{
	return (g_cur_dir);
}
