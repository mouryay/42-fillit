# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: davigarc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/07 19:03:27 by davigarc          #+#    #+#              #
#    Updated: 2020/02/13 12:56:14 by myadaval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRCS = main.c valid.c makelist.c fillit.c solve_map.c
OBJS = *.o
HDR = fillit.h
FLAGS = -Wall -Wextra -Werror

all:		 $(NAME)

$(NAME):	$(SRCS) $(HDR)
			@gcc $(FLAGS) -c $(SRCS)
			@gcc -o $(NAME) $(OBJS)

clean:
			@rm -f $(OBJS)

fclean:		clean
			@rm -f $(NAME)

re:			fclean all
