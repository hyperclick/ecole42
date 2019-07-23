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
COMMON_SRC  = lib/*.c src/*.c
RELEASE_SRC = release/*.c
TEST_SRC = test/*.c

all:	compile

compile:
	gcc $(COMMON_SRC) $(RELEASE_SRC) -o $(NAME) $(ARGS)

test_compile:
	gcc $(COMMON_SRC) $(TEST_SRC) $(ARGS)


clean:
	rm -f $(NAME)
	rm -f log.txt
	rm -f .DS_Store
	rm -f a.out
	rm -f includes/.DS_Store

fclean:	clean

re:	fclean compile


test:	clean test_compile
	./a.out Makefile