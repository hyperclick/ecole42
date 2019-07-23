# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: darugula <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/18 09:28:37 by darugula          #+#    #+#              #
#    Updated: 2019/07/18 09:28:40 by darugula         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
ARGS = -Wall -Wextra -Werror
SRC  = lib/*.c *.c

all:	compile

compile:
	gcc $(SRC) -o $(NAME) $(ARGS)

test_compile:
	gcc $(SRC) $(ARGS)

test:	test_compile
	./a.out main.c

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean compile

