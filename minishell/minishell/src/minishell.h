#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define MAX_CMD_LINE	255

BOOL		built_in_processed(const char str[MAX_CMD_LINE]);
//BOOL		is_exit(const char str[MAX_CMD_LINE]);

#endif