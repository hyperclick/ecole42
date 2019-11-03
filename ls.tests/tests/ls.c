#include "ls.h"

t_f_n	create_full_name()
{
	t_f_n fn;
	fn.folder[0] = 0;
	fn.name[0] = 0;
	fn.path[0] = 0;
	return (fn);
}
