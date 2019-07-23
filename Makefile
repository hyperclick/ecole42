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
#TEST_ARGS = test_files/good/one_line_all_free.txt test_files/good/two_lines_all_free.txt
TEST_ARGS = test_files/good/two_lines_all_free.txt

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
	rm -f test_files/.DS_Store
	rm -f test_files/good/.DS_Store
	rm -f libs/.DS_Store
	rm -f src/.DS_Store
	

fclean:	clean

re:	fclean compile


test:	clean test_compile
	./a.out $(TEST_ARGS)
#	cat test_files/example_file.txt | ./a.out
