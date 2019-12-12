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
	while (TRUE)
	{
		print_prompt();
		process_command(read_line_hidden());
	}

	ft_exit(0);
	return (0);
}
