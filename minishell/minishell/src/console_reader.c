#include "minishell.h"
#include <ctype.h>
#include "key_constants.h"

static struct termios stored_settings;

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
	if (control[0] == KEY_TAB
		|| control[0] == KEY_BACKSPACE
		|| ft_strequ(control, KEY_UP)
		|| ft_strequ(control, KEY_DOWN)
		|| ft_strequ(control, KEY_RIGHT)
		|| ft_strequ(control, KEY_LEFT)
		|| ft_strequ(control, KEY_DELETE))
	{
		ft_putstr(control);
		return (TRUE);
	}
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

BOOL		g_clean_buffer;

void		clean_buffer()
{
	g_clean_buffer = TRUE;
}

void		read_line_hidden(char* dst, int size)
{
	int r;
	char		control[10];
	control[0] = 0;
	char c;
	int i;

	i = -1;
	g_clean_buffer = FALSE;
	set_keypress();
	while ((r = read(STDIN_FILENO, &c, 1)) > 0)
	{
		debug_printf("\nentered:\n%d ('%c')\n", c, c);
		if (g_clean_buffer)
		{
			i = -1;
			g_clean_buffer = FALSE;
		}
		if (ft_strlen(control) == 0)
		{
			if (ft_isprint(c))
			{
				ft_putchar(c);
				if (i > size)
				{
					ft_e_putstr("\nbuffer is too small\n");
					debug_printf("buffer is too small\n");
					reset_keypress();
					exit(1);
				}
				dst[++i] = c;
				continue;
			}
			if (c == '\n')
			{
				ft_putchar(c);
				break;
			}
		}
		process_not_printable(control, c);
	}
	debug_printf("r = %d\n", r);
	dst[++i] = 0;
	reset_keypress();
}