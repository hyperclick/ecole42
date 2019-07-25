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

NAME = eval_expr
ARGS = -Wall -Wextra -Werror
SRC  = eval.c lib/*.c state_extensions.c calc.c state_is_op_set.c state_is_op_set2.c main.c

all:	compile

compile:
	gcc $(SRC) -o $(NAME) $(ARGS)

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean compile

