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

#TEST_ARGS = test_files/good/one_line_all_free.txt #test_files/good/two_lines_all_free.txt
#TEST_ARGS_2 = test_files/good/one_cell_free.txt test_files/good/one_cell_free.txt
#TEST_ARGS_2 = test_files/good/two_lines_all_free.txt


TEST_ARGS 	= test_files/good/two_lines_all_free.txt
TEST_ARGS_1	= test_files/good/one_cell_free.txt 
TEST_ARGS_2 	= test_files/good/one_line_all_two_free.txt
TEST_ARGS_3 	= test_files/good/one_line_all_three_free.txt
TEST_ARGS_4 	= test_files/good/one_line_all_free.txt

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

c:	clean

fclean:	clean

re:	fclean compile


t:	clean test_compile
	./a.out $(TEST_ARGS)
#	cat test_files/example_file.txt | ./a.out

t1:	clean test_compile
	./a.out $(TEST_ARGS_1)

t2:	clean test_compile
	./a.out $(TEST_ARGS_2)

t3:	clean test_compile
	./a.out $(TEST_ARGS_3)

t4:	clean test_compile
	./a.out $(TEST_ARGS_4)
