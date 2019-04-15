# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/04/15 18:37:06 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = push_check
DIR_O = obj/
COMMON_C = ft_argscheck.c \
		   ft_stackfill.c \
		   ft_ops.c \
		   ft_opget.c
PUSH_SWAP_C = push_swap.c
CHECKER_C = checker.c
PUSH_SWAP_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(PUSH_SWAP_C)))
CHECKER_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(CHECKER_C)))
COMMON_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(COMMON_C)))
FILES_H = push_swap.h
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all $(NAME) test norme
.SILENT : clean fclean re all $(NAME) libft/libft.a push_swap checker test

all : $(NAME)

$(NAME) : push_swap checker

push_swap : $(PUSH_SWAP_O) $(COMMON_O)
	gcc -I . $(FLAGS) $(COMMON_O) $(PUSH_SWAP_O) -L ./libft/ -lft -o push_swap
	$(info PUSH_SWAP exec compiled)

checker : $(CHECKER_O) $(COMMON_O)
	gcc -I . $(FLAGS) $(COMMON_O) $(CHECKER_O) -L ./libft/ -lft -o checker
	$(info CHECKER exec compiled)

$(DIR_O)%.o : %.c $(FILES_H) libft/libft.a
	$(info PUSH_SWAP $<)
	@gcc -I . -I ./libft/includes/ $(FLAGS) -c -o $@ $<

test: all
	$(info LAUNCHING TEST)
	cat cmd | ./checker 4 2 3 1

norme: 
	@norminette $(COMMON_C) $(CHECKER_C) $(PUSH_SWAP_C) $(FILES_H)

libft/libft.a :
	$(info LIBFT update)
	make -C libft

clean : 
	rm -f $(PUSH_SWAP_O) $(CHECKER_O) $(COMMON_O)
	$(info PUSH_SWAP, CHECKER .o removed)

fclean : clean
	rm -f push_swap checker
	$(info PUSH_SWAP, CHECKER execs removed)

re : fclean all
