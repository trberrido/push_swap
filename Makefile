# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/05/25 15:20:25 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = push_check
DIR_O = obj
DIR_C = src
DIR_H = include
COMMON_C_NAME = args_check.c \
			    stack_fill.c \
			    stack_del.c \
			    stack_print.c \
				stack_find.c \
				stack_findminmax.c \
				stack_pull.c \
				stack_push.c \
				stack_pushrot.c \
				stack_push_andswap.c \
				stack_pushnext.c \
			    sort_check.c \
				op_add.c \
			    op_functions.c \
			    op_switch.c
PUSH_SWAP_C_NAME = push_swap.c \
				   op_write.c \
				   sort_switch.c \
				   sort_selection.c \
				   sort_bubble.c \
				   sort_quick.c \
				   sort_post.c
CHECKER_C_NAME = checker.c
TEST_C_NAME = test.c \
			  $(PUSH_SWAP_C_NAME) \
			  $(COMMON_C_NAME) \
			  $(CHECKER_C_NAME)

FILES_H_NAME = push_swap.h

TEST_C_NAME := $(filter-out push_swap.c, $(TEST_C_NAME))
TEST_C_NAME := $(filter-out checker.c, $(TEST_C_NAME))

PUSH_SWAP_O_NAME = $(PUSH_SWAP_C_NAME:.c=.o)
CHECKER_O_NAME = $(CHECKER_C_NAME:.c=.o)
COMMON_O_NAME = $(COMMON_C_NAME:.c=.o)
TEST_O_NAME = $(TEST_C_NAME:.c=.o)

PUSH_SWAP_O = $(addprefix $(DIR_O)/, $(PUSH_SWAP_O_NAME))
CHECKER_O = $(addprefix $(DIR_O)/, $(CHECKER_O_NAME))
COMMON_O = $(addprefix $(DIR_O)/, $(COMMON_O_NAME))
TEST_O = $(addprefix $(DIR_O)/, $(TEST_O_NAME))

COMMON_C = $(addprefix $(DIR_C)/, $(COMMON_C_NAME))
PUSH_SWAP_C = $(addprefix $(DIR_C)/, $(PUSH_SWAP_C_NAME))
CHECKER_C = $(addprefix $(DIR_C)/, $(CHECKER_C_NAME))
TEST_C = $(addprefix $(DIR_C)/, $(TEST_C_NAME))

FILES_H = $(addprefix $(DIR_H)/, $(FILES_H_NAME))

FLAGS = -Wall -Wextra -Werror -g3

.PHONY : clean fclean re all $(NAME) test norme libft test debug
.SILENT : clean fclean re all $(NAME) libft push_swap checker test debug

all : $(NAME)

$(NAME) : push_swap checker

echo:
	@echo $(PUSH_SWAP_C)

push_swap : libft $(PUSH_SWAP_O) $(COMMON_O)
	gcc -I ./$(DIR_H) $(FLAGS) $(COMMON_O) $(PUSH_SWAP_O) -L ./libft/ -lft -o push_swap
	$(info PUSH_SWAP exec compiled)

checker : libft $(CHECKER_O) $(COMMON_O)
	gcc -I ./$(DIR_H) $(FLAGS) $(COMMON_O) $(CHECKER_O) -L ./libft/ -lft -o checker
	$(info CHECKER exec compiled)

debug : libft
	gcc -I ./$(DIR_H) -I ./libft/include/ -ggdb $(FLAGS) $(COMMON_C) $(PUSH_SWAP_C) -L ./libft/ -lft -o push_swap
	$(info PUSH_SWAP exec compiled)
	$(info ARG=`ruby -e "puts (1 ... 100).to_a.shuffle.join(' ')"`; lldb push_swap $ARG)
	$(info b ft_slice)
	$(info run, next, step)

test: libft $(TEST_O)
	gcc -I ./$(DIR_H) $(FLAGS) $(TEST_O) -L ./libft/ -lft -o test
	$(info TEST exec compiled)

$(DIR_O)/%.o : $(DIR_C)/%.c $(FILES_H)
	@mkdir -p $(DIR_O)
	$(info PUSH_SWAP $<)
	@gcc -I ./$(DIR_H)/ -I ./libft/include/ $(FLAGS) -c -o $@ $<

norme: 
	norminette $(TEST_C) $(COMMON_C) $(CHECKER_C) $(PUSH_SWAP_C) $(FILES_H)

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
