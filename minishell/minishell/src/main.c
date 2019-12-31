#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	init(argc, argv, envp);
	if (argc > 1)
	{
		cd(argc - 1, argv + 1);
	}
	while (TRUE)
	{
		print_prompt();
		process_command(read_line_hidden());
	}
}
