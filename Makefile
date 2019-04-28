# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/04/28 14:58:01 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = push_check
DIR_O = obj/
COMMON_C = ft_argscheck.c \
		   ft_stackfill.c \
		   ft_stackdel.c \
		   ft_stackprint.c \
		   ft_stacksort_check.c \
		   ft_stacksort_utils_find.c \
		   ft_opfunctions.c \
		   ft_opswitch.c
PUSH_SWAP_C = push_swap.c \
			  ft_opadd.c \
			  ft_opwrite.c \
			  ft_stacksort.c \
			  ft_stacksort_selection.c \
			  ft_stacksort_bubble.c \
			  ft_stacksort_quicksort.c \
			  ft_stacksort_post.c \
			  ft_stacksort_utils_manip.c
CHECKER_C = checker.c
TEST_C = test.c \
		 $(CHECKER_C) \
		 $(PUSH_SWAP_C)
TEST_C := $(filter-out push_swap.c, $(TEST_C))
TEST_C := $(filter-out checker.c, $(TEST_C))
PUSH_SWAP_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(PUSH_SWAP_C)))
CHECKER_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(CHECKER_C)))
TEST_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(TEST_C)))
COMMON_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(COMMON_C)))
FILES_H = push_swap.h
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all $(NAME) test norme libft test
.SILENT : clean fclean re all $(NAME) libft push_swap checker test

all : $(NAME)

$(NAME) : push_swap checker

push_swap : libft $(PUSH_SWAP_O) $(COMMON_O)
	gcc -I . $(FLAGS) $(COMMON_O) $(PUSH_SWAP_O) -L ./libft/ -lft -o push_swap
	$(info PUSH_SWAP exec compiled)

checker : libft $(CHECKER_O) $(COMMON_O)
	gcc -I . $(FLAGS) $(COMMON_O) $(CHECKER_O) -L ./libft/ -lft -o checker
	$(info CHECKER exec compiled)

test: libft $(TEST_O) $(COMMON_O)
	gcc -I . $(FLAGS) $(COMMON_O) $(TEST_O) -L ./libft/ -lft -o test
	$(info TEST exec compiled)

$(DIR_O)%.o : %.c $(FILES_H)
	$(info PUSH_SWAP $<)
	@gcc -I . -I ./libft/includes/ $(FLAGS) -c -o $@ $<

norme: 
	@norminette $(TEST_C) $(COMMON_C) $(CHECKER_C) $(PUSH_SWAP_C) $(FILES_H)

libft:
	$(info LIBFT update)
	make -C libft/

clean : 
	rm -f $(PUSH_SWAP_O) $(CHECKER_O) $(COMMON_O)
	$(info PUSH_SWAP, CHECKER .o removed)

fclean : clean
	rm -f push_swap checker
	$(info PUSH_SWAP, CHECKER execs removed)

re : fclean all
