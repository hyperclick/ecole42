#include "minishell.h"
#include <ctype.h>
#include "key_constants.h"

static struct termios stored_settings;
static int g_buf_len;
static char g_buffer[PATH_MAX];
static int g_x;
typedef struct s_input
{

}	t_input;

void set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(STDIN_FILENO, &stored_settings);

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0, TCSANOW, &new_settings);
	return;
}

void reset_keypress(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &stored_settings);
}

void move_cursor_left(int x)
{
	while (x-- > 0)
	{
		ft_putstr(KEY_LEFT);
		debug_printf("<\n");
	}
}

void move_cursor_to_the_bol()
{
	move_cursor_left(g_x);
}

void move_cursor_right(int x)
{
	while (x-- > 0)
	{
		ft_putstr(KEY_RIGHT);
	}
}


//void remove_char_at(int x)
//{
//	if (x > g_buf_len)
//	{
//		ft_e_putstr("x > g_buf_len\n");
//		debug_printf("x > g_buf_len\n");
//		exit(1);
//	}
//	if (x < 0)
//	{
//		ft_e_putstr("x < 0\n");
//		debug_printf("x < 0\n");
//		exit(1);
//	}
//	clean_printed_text();
//	g_buffer[g_buf_len + 1] = 0;
//	char* str = ft_strdup(g_buffer);
//	str[g_buf_len] = ' ';
//	ft_strncpy(str + x, g_buffer + x + 1, g_buf_len - x);
//	//debug_printf(str);
//
//	move_cursor_to_the_bol();
//	ft_putstr(str);
//	free(str);
//	move_cursor_right(g_x);
//}

void backspace(int x)
{
	int i;

	i = -1;
	while (++i < x)
	{
		ft_putstr(KEY_LEFT);
	}
	i = -1;
	while (++i < x)
	{
		ft_putstr(" ");
	}
	i = -1;
	while (++i < x)
	{
		ft_putstr(KEY_LEFT);
	}
}

//BOOL		process_esc(int len)
//{
//	debug_printf("len = %d\n", len);
//	backspace(len);
//	clean_buffer();
//	return (TRUE);
//}

BOOL		process_backspace()
{
	if (g_buf_len > -1)
	{
		backspace(1);
		g_buf_len--;
	}
	return (TRUE);
}

void inc_cursor_pos()
{
	if (g_x > g_buf_len)
	{
		ft_e_putstr("inc_cursor_pos: g_x >= g_buf_len");
		exit(1);
	}
	++g_x;
	debug_printf("gx = %d\n", g_x);
}
void dec_cursor_pos()
{
	if (g_x < 1)
	{
		ft_e_putstr("process_key_left: g_x <= 1");
		exit(1);
	}

	--g_x;
	debug_printf("gx = %d\n", g_x);
}

BOOL		process_key_left()
{
	if (g_x > 0)
	{
		move_cursor_left(1);
		dec_cursor_pos();
	}
	return (TRUE);
}
BOOL		process_key_right()
{
	if (g_x < g_buf_len)
	{
		move_cursor_right(1);
		inc_cursor_pos();
	}
	return (TRUE);
}

BOOL		processed(char		control[10])
{
	if (ft_strlen(control) > 4)
	{
		ft_e_putstr("unknown input\n");
		for (int i = 0; i < 4; i++)
		{
			char c = control[i];
			printf("\n%d ('%c')\n", c, c);
		}
		return (TRUE);
	}
	if (ft_strequ(control, KEY_LEFT))
	{
		return (process_key_left());
	}
	if (ft_strequ(control, KEY_RIGHT))
	{
		return (process_key_right());
	}
	if (ft_strequ(control, KEY_UP)
		|| ft_strequ(control, KEY_DOWN)
		|| ft_strequ(control, KEY_DELETE))
	{
		ft_putstr(control);
		return (TRUE);
	}
	if (control[0] == KEY_BACKSPACE)
	{
		return (process_backspace());
	}
	//if (control[0] == KEY_ESC)
	//{
	//	return (process_esc(buf_len));
	//}
	return (FALSE);
}

void		process_not_printable(char		control[10], int c)
{
	ft_str_append(control, c);

	if (processed(control))
	{
		control[0] = 0;
	}
}

void increase_buffer()
{
	if (g_buf_len++ > PATH_MAX - 1)
	{
		ft_e_putstr("buffer is too small\n");
		debug_printf("buffer is too small\n");
		reset_keypress();
		exit(1);
	}
	g_buffer[g_buf_len] = 0;
}

void		clean_buffer()
{
	//g_clean_buffer = TRUE;
	g_buf_len = 0;
	g_buffer[g_buf_len] = 0;
}

void	 clean_printed_text()
{
	move_cursor_left(g_x);
	int i = -1;
	while (++i < g_buf_len)
	{
		ft_putchar(' ');
		debug_printf("_\n");
	}
	//move_cursor_right(g_x);
}
char read_key()
{
	char c;
	read(STDIN_FILENO, &c, 1);
	return c;
}
void print_buffer()
{
	debug_printf("before text clean\n");
	debug_printf("press any key\n");
	read_key();

	clean_printed_text();

	debug_printf("text cleaned\n");
	debug_printf("press any key\n");
	read_key();

	move_cursor_left(g_x);

	debug_printf("cursor moved\n");
	debug_printf("press any key\n");
	read_key();
	ft_putstr(g_buffer);
	//move_cursor_right(g_x);
}

const char* read_line_hidden()
{
	int r;
	char		control[10];
	control[0] = 0;
	char c;

	g_x = 0;
	clean_buffer();
	set_keypress();
	while ((r = read(STDIN_FILENO, &c, 1)) > 0)
	{
		debug_printf("\nentered:\n%d ('%c')\n", c, c);

		if (ft_strlen(control) == 0)
		{
			if (c == '\n')
			{
				ft_putchar(c);
				break;
			}
			if (ft_isprint(c))
			{
				debug_printf("g_x: %d, g_buf_len = %d, g_buffer = '%s'\n", g_x, g_buf_len, g_buffer);
				debug_printf("before text clean\n");
				//debug_printf("press any key\n");
				//read_key();

				clean_printed_text();

				debug_printf("text cleaned\n");
				//debug_printf("press any key\n");
				//read_key();

				move_cursor_left(g_buf_len);

				debug_printf("cursor moved\n");
				//debug_printf("press any key\n");
				//read_key();

				increase_buffer();
				ft_str_insert_at(g_buffer, g_x, c);

				ft_putstr(g_buffer);
				inc_cursor_pos();
				move_cursor_left(g_buf_len);
				move_cursor_right(g_x);
				continue;
			}
		}
		process_not_printable(control, c);
	}
	debug_printf("r = %d\n", r);
	reset_keypress();
	if (r == 0)
	{
		printf("std in is all\n");
		exit(1);
	}
	return (g_buffer);
}