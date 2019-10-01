# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darugula <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/15 23:16:12 by darugula          #+#    #+#              #
#    Updated: 2019/07/15 23:18:39 by darugula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRC = main.c do_op.c operations.c lib.c lib2.c lib3.c
FLAGS = -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	gcc $(CFLAGS) -o $(NAME) $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
