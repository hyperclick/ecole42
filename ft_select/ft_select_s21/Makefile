
.PHONY: clean fclean re make all

FILENAMES = active_cell.c color.c console_reader.c draw.c key_handlers.c process_command.c process_command2.c selection.c selection2.c selection3.c shell.c sig_handlers.c sig_handlers2.c table.c table2.c table3.c table_create.c table_to_string.c table_try.c termcaps.c termcaps2.c

NAME = ft_select

SRCS	=$(addprefix src/, $(FILENAMES))

H		= src/key_constants.h src/ft_select.h

OBJS			= $(SRCS:%.c=%.o)

CC		= gcc
CFLAGS	+= -Wall -Wextra -Werror  -g

LIBFT = libft/libft.a

all:		$(NAME)

$(OBJS): %.o: %.c 
	$(CC) $(CFLAGS) $< -o $@ -c 
	
$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJS) $(H)
	$(CC) $(CFLAGS) src/main.c  -o $(NAME) $(OBJS) $(LIBFT) -ltermcap


clean:
	@rm -rf $(OBJS)
	@make clean -C libft
	#rm ut

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

debug:
	$(CFLAGS)	= $(CFLAGS) -g
	make $(NAME)
	