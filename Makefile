# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/04/12 15:30:21 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = push_check
DIR_O = obj/
COMMON_C = ft_argscheck.c \
		   ft_stackfill.c
PUSH_SWAP_C = push_swap.c \
			  $(COMMON_C)
CHECKER_C = checker.c \
			$(COMMON_C)
PUSH_SWAP_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(PUSH_SWAP_C)))
CHECKER_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(CHECKER_C)))
FILES_H = push_swap.h
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all $(NAME) test
.SILENT : clean fclean re all $(NAME) libft/libft.a push_swap checker test

all : $(NAME)

$(NAME) : push_swap checker

push_swap : $(PUSH_SWAP_O)
	gcc -I . $(FLAGS) $(PUSH_SWAP_O) -L ./libft/ -lft -o push_swap
	$(info PUSH_SWAP exec compiled)

checker : $(CHECKER_O)
	gcc -I . $(FLAGS) $(CHECKER_O) -L ./libft/ -lft -o checker
	$(info CHECKER exec compiled)

$(DIR_O)%.o : %.c $(FILES_H) libft/libft.a
	@gcc -I . -I ./libft/includes/ $(FLAGS) -c -o $@ $<

test: all
	$(info LAUNCHING TEST)
	./checker

libft/libft.a :
	$(info LIBFT update)
	make -C libft

clean : 
	rm -f $(PUSH_SWAP_O) $(CHECKER_O)
	$(info PUSH_SWAP, CHECKER .o removed)

fclean : clean
	rm -f push_swap checker
	$(info PUSH_SWAP, CHECKER execs removed)

re : fclean all
