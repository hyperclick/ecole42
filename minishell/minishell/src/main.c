#include "minishell.h"

int main(int argc, char** argv, char** envp)
{

	set_out_file("debug_out.txt", "w");
	set_level(1);
	debug_printf("%s\n", "started");
	debug_printf("agrc = %d\n", argc);
	debug_printf("agrv[1] = %s\n", argv[1]);
	log_line("n\n\n\nstarted\n\n");
	//parse args
	signal(SIGINT, ft_default_sig_handler);
	env_from_array(envp);
	//atexit()
	if (argc > 1)
	{
		cd(argc - 1, argv + 1);
	}
	char		cmd_line[MAX_CMD_LINE];
	while (TRUE)
	{
		print_prompt();
		read_line_hidden(cmd_line, MAX_CMD_LINE);
		//printf("read: '%s'\n", cmd_line);
		//history.push
		//if (is_up_arrow(cmd_line))
		//{
		//	ft_strcpy(cmd_line, history.pop());
		//}
		process_command(cmd_line);
	}

	ft_exit(0);
	return (0);
}
