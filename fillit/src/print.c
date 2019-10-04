#include "tetramino.h"

void	print_figure(t_t f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			ft_putchar(f.a[i][j]);
		}
		ft_putchar('\n');
	}
}

void	print_figures()
{
	int	i;

	i = -1;
	while (++i < g_figures_count)
	{
		print_figure(g_figures[i]);
		ft_putchar('\n');
	}
}

void	print_r(t_r r)
{
	int	i;
	int	j;

	i = 0;
	while (i < r.height)
	{
		j = 0;
		while (j < r.width)
		{
			ft_putchar(r.a[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
}
