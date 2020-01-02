
.PHONY: clean fclean re make all

FILENAMES = awaited_process.c cd.c console_read_buffer.c console_read_buffer2.c console_read_buffer3.c console_reader.c cmd_parser.c cursor_move.c cursor_move2.c ft_set_env.c env.c env2.c env3.c env4.c exec.c exec2.c folders.c history.c history2.c key_handlers.c key_handlers2.c pipe_exec.c pipe_parse.c process_command.c replace_quoted.c replace_quoted2.c shell.c termios.c

NAME = minishell

SRCS	=$(addprefix src/, $(FILENAMES))

H		=src/history.h src/key_constants.h src/minishell.h

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror
CFLAGS	+= -g -I includes/

LIBFT = libft/libft.a

all:		$(NAME) ut

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 
	
$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS) $(H)
	$(CC) $(CFLAGS) src/main.c  -o $(NAME) $(OBJS) $(LIBFT) 


clean:
	@rm -rf $(OBJS)
	@make clean -C libft
	#rm ut

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

ut:	$(NAME)  tests/*.c 
	$(CC) tests/*.c $(OBJS) $(LIBFT) -g -o ut
