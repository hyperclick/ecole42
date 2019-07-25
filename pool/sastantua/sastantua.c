#include <stdio.h>

int	ft_putchar(char c);

void draw_offset(int count)
{
	while (count--)
	{
		ft_putchar(' ');
	}
}

int get_delta(int cols)
{
	return cols % 2 == 0 ? 4 : 3;
}

void draw_line(int col_count, int offset)
{
//ft_putchar('0' + col_count);

	//offset += get_delta(col_count);
	draw_offset(offset);
	ft_putchar('/');
	for (int i = 0; i < col_count - 2; i++)
	{
		ft_putchar('*');
	}
	ft_putchar('\\');
	ft_putchar('\n');
}

int draw_lines(int row, int base_col_count, int offset)
{
	if (row == 0)
	{
		return base_col_count;
	}
	draw_lines(row - 1, base_col_count - 2, offset + 1);
	draw_line(base_col_count, offset);
	return base_col_count;
}


int get_next_columns(int tier, int prev_columns)
{
	return prev_columns + 2 * get_delta(prev_columns);
}

int get_shoulder(int tier)
{
	int s = 2;
	while (tier--)
	{
		s+= tier % 2 ? 1:0;
	}
	return s;
}

int draw_tier(int tier, int offset)
{
	if(tier == 0)
	{
		return -1;
	}
	int row_count = tier + 2;
	int new_offset = row_count - 1;
	int shoulder = get_shoulder(tier);
	int prev_columns = draw_tier(tier - 1, offset + new_offset + shoulder);
	
	int top = 2 * shoulder + prev_columns;
	int new_col_count_on_base_level = top + 2 * new_offset;
//	printf("tier: %d, row_count: %d, prev_columns: %d, top: %d, base: %d, offset: %d, shoulder: %d\n"
//		   , tier, row_count, prev_columns, top, new_col_count_on_base_level, offset, shoulder);
	return draw_lines(row_count, new_col_count_on_base_level, offset);
}


/*
void draw(int tiers)
{
	if (tiers == 0)
	{
		return;
	}
	draw(tiers - 1);
	draw_tier(tiers);
}
*/
void	sastantua(int size)
{
	printf("tiers: %d:\n", size);
	int tiers = size;
	if (tiers == 0)
	{
		return;
	}
		draw_tier(tiers, 0);
	
	//draw_first_tier();
	//if (--tiers == 0)
	//{
	//	return;
	//}
	//if(tiers > 1)
	//{
	//	draw(tiers);
	//}
	//draw_last_tier(size);
}

