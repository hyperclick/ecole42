#include "minishell.h"
#include <ctype.h>
#include "key_constants.h"

static struct termios stored_settings;
static int g_buf_len;
static char g_buffer[PATH_MAX];
static int g_x;
static BOOL g_set = FALSE;
void set_keypress(void)
{
	struct termios new_settings;

	tcgetattr(STDIN_FILENO, &stored_settings);

	new_settings = stored_settings;

	new_settings.c_lflag &= (~ICANON & ~ECHO);
	new_settings.c_cc[VTIME] = 0;
	new_settings.c_cc[VMIN] = 1;

	tcsetattr(0, TCSANOW, &new_settings);
	g_set = TRUE;
	return;
}

void reset_keypress(void)
{
	if (g_set)
	{
		tcsetattr(STDIN_FILENO, TCSANOW, &stored_settings);
		g_set = FALSE;
	}
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


void inc_cursor_pos()
{
	if (g_x > g_buf_len)
	{
		ft_e_putstr("inc_cursor_pos: g_x >= g_buf_len");
		reset_keypress();
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
		reset_keypress();
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

void decrease_buffer()
{
	if (--g_buf_len < 0)
	{
		ft_e_putstr("buffer is negative\n");
		debug_printf("buffer is negative\n");
		reset_keypress();
		exit(1);
	}
	g_buffer[g_buf_len] = 0;
}
void		clean_buffer()
{
	g_buf_len = 0;
	g_buffer[g_buf_len] = 0;
	g_x = 0;
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
}

char read_key()
{
	char c;
	read(STDIN_FILENO, &c, 1);
	return c;
}

//BOOL		is_buffer_change(char		control[10], char c)
//{
//	return (
//		(ft_strlen(control) == 1 && ft_isprint(c))
//		|| (ft_strlen(control) == 1 && c == KEY_BACKSPACE)
//		|| ft_str_equals(control, KEY_DELETE));
//}

void buffer_delete()
{
	if (g_x < g_buf_len)
	{
		ft_str_remove_at(g_buffer, g_x);
		decrease_buffer();
	}
}

void buffer_backspace()
{
	if (g_x > 0)
	{
		ft_str_remove_at(g_buffer, g_x - 1);
		decrease_buffer();
		dec_cursor_pos();
	}
}

void buffer_insert(char c)
{
	increase_buffer();
	ft_str_insert_at(g_buffer, g_x, c);
	inc_cursor_pos();
}

void		buffer_print()
{
	debug_printf("g_x: %d, g_buf_len = %d, g_buffer = '%s'\n", g_x, g_buf_len, g_buffer);
	ft_putstr(g_buffer);
	move_cursor_left(g_buf_len);
	move_cursor_right(g_x);
}
void clean_printed_text_and_move_cursor_left()
{
	debug_printf("g_x: %d, g_buf_len = %d, g_buffer = '%s'\n", g_x, g_buf_len, g_buffer);
	clean_printed_text();
	move_cursor_left(g_buf_len);
}

BOOL		process_backspace()
{
	clean_printed_text_and_move_cursor_left();
	buffer_backspace();
	buffer_print();
	return (TRUE);
}
BOOL		process_delete()
{
	clean_printed_text_and_move_cursor_left();
	buffer_delete();
	buffer_print();
	return (TRUE);
}
void buffer_set(const char* new_value)
{
	clean_printed_text_and_move_cursor_left();
	ft_strcpy(g_buffer, new_value);
	g_buf_len = ft_strlen(g_buffer);
	g_x = g_buf_len;

}
BOOL		process_key_down()
{
	if (h_has_next())
	{
		buffer_set(h_get_next());
		buffer_print();
	}
	return (TRUE);
}
BOOL		process_key_up()
{
	if (h_has_previous())
	{
		buffer_set(h_get_previous());
		buffer_print();
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
	if (ft_strequ(control, KEY_UP))
	{
		return (process_key_up());
	}
	if (ft_strequ(control, KEY_DOWN))
	{
		return (process_key_down());
	}
	if (ft_strequ(control, KEY_DELETE))
	{
		return (process_delete());
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
		debug_printf("\n");
		debug_printf("entered:\t%d ('%c'), control = '%s'\n", c, c, control);
		if (ft_strlen(control) == 0 && c == '\n')
		{
			ft_putchar(c);
			break;
		}
		if (ft_strlen(control) == 0 && ft_isprint(c))
		{
			clean_printed_text_and_move_cursor_left();
			buffer_insert(c);
			buffer_print();
			continue;
		}

		process_not_printable(control, c);
	}
	debug_printf("r = %d\n", r);
	reset_keypress();
	if (r == 0)
	{
		debug_printf("std in is all\n");
		exit(1);
	}
	if (g_buf_len > 0)
	{
		h_append(ft_strdup(g_buffer));
	}
	return (g_buffer);
}
