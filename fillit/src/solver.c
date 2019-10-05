#include "tetramino.h"
#include "result_checks.h"

t_r		fill(t_r r, const char rest[])
{
	size_t	len;
	t_t		f;
	char	next_rest[27];
	t_r		new_r;

	r.deep++;
	len = ft_strlen(rest);
	if (len == 0)
	{
		r.found = TRUE;
		return (r);
	}
	f = get_figure(rest[0]);
	for (int i = 0; i < r.height; i++)
	{
		for (int j = 0; j < r.width; j++)
		{
			if (can_append(r, i, j, f))
			{
				new_r = append(r, i, j, f);
				ft_strcpy(next_rest, rest);
				ft_str_remove_at(next_rest, 0);
				//printf("appended: path: %s next_rest: %s   i:%d j:%d\n", new_r.path, next_rest,  i, j);
				//print_r(new_r);
				//ft_putchar('\n');
				new_r = fill(new_r, next_rest);
				if (new_r.found)
				{
					return (new_r);
				}
			}
		}
	}
	return (r);
}

void	solve(const char *file_name)
{
	char	rest[27];
	int		width;
	int		max_width;
	t_r		r;

	if (read_file(file_name) == FALSE || get_figures_count() == 0)
	{
		ft_putstr("error\n");
		exit(5);
	}
	//print_figures();
	width = ft_sqrt_up(get_figures_count() * 4);
	max_width = width + 12;
	r.found = FALSE;
	while (width < max_width && r.found == FALSE)
	{
		r = fill(r = create_r(width), make_rest(rest));
		width++;
	}
	print_r(r);
}
