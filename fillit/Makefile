
.PHONY: clean fclean re make all

FILENAMES = figures.c input_checks.c input_checks2.c main.c mormalizer.c print.c reader.c tetramino.c  result.c result_checks.c solver.c tetramino_linq.c 
NAME = fillit

SRCS	=$(addprefix src/, $(FILENAMES))
OBJS	=$(addprefix build/, $(FILENAMES:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
CFLAGS	+= -I includes/
LFLAGS	= -L ./libft/ -lft

all: $(NAME)

$(NAME):$(OBJS) | lib
	@$(CC) $(CFLAGS) -o $(NAME) $(LFLAGS) $(OBJS)

build/%.o: src/%.c | build
	@$(CC) $(CFLAGS) -o $@ -c $^

re: fclean all

lib:
	@make -C ./libft
	@make clean -C ./libft

clean:
	@rm -rf build/

fclean: clean
	@make fclean -C ./libft
	@rm -f $(NAME)

build:
	@mkdir build/
