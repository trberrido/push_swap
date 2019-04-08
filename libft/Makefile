# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thberrid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/17 17:15:46 by thberrid          #+#    #+#              #
#    Updated: 2019/04/08 19:37:38 by thberrid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = /bin/sh
NAME = libft.a
FILES_C = get_next_line.c \
		  ft_factorial.c \
		  ft_power.c \
		  ft_sqrt.c \
		  ft_atoi.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isdigit.c \
		  ft_isprint.c \
		  ft_itoa.c \
		  ft_lstadd.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memrealloc.c \
		  ft_memset.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c
DIR_O = obj/
FILES_O = $(addprefix $(DIR_O), $(patsubst %.c, %.o, $(FILES_C)))
INC = $(addprefix includes/, get_next_line.h libft.h)
FLAGS = -Wall -Wextra -Werror

.PHONY : clean fclean re all
.SILENT : clean fclean re all $(NAME) 

all : $(NAME)

$(NAME) : $(FILES_O)
	$(info > LIBFT compiling...)
	ar rc $(NAME) $(FILES_O)
	ranlib $(NAME)
	$(info > LIBFT compilatio over)

$(DIR_O)%.o : %.c $(INC)
	@gcc -I ./includes $(FLAGS) -c -o $@ $<

clean : 
	rm -f $(FILES_O)
	$(info > *.o removed)

fclean : clean
	rm -f $(NAME)
	$(info > libft.a removed)

re : fclean all