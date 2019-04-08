# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/04/08 20:28:23 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = push_check
DIR_O = obj/
COMMON_C = tmp.c
PUSH_SWAP_C = push_swap.c \
			  $(COMMON_C)
CHECKER_C = checker.c \
			$(COMMON_C)
PUSH_SWAP_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o), $(PUSH_SWAP_C))
CHECKER_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o), $(CHECKER_C))
FILES_H = push_swap.h
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all $(NAME)
.SILENT : clean fclean re all $(NAME) push_swap checker

all : $(NAME)

$(NAME) : push_swap checker

push_swap : $(PUSH_SWAP_O)
	make -C libft
	make -C libft clean
	gcc -I ./$(DIR_H) $(FLAGS) $(PUSH_SWAP_O) -L libft/ -lft -c -o push_swap

checker : $(CHECKER_O) 
	gcc -I ./$(DIR_H) $(FLAGS) $(CHECKER_O) -c -o checker

$(DIR_O)%.o : %.c $(FILES_H)
	@gcc -I ./$(DIR_H) $(FLAGS) -c -o $@ $<

clean : 
	rm -f $(FILES_O)
	$(info > PUSH_SWAP .o removed)

fclean : clean
	rm -f $(NAME)
	$(info > PUSH_SWAP execs removed)

re : fclean all
