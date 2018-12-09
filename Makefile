# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                                                  #
#                                                     +:+ +:+         +:+      #
#    By: glavigno <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:48:50 by glavigno          #+#    #+#              #
#    Updated: 2018/12/09 04:09:14 by Sawyerf                                   #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRC =	ft_printf.c \
		pf_base.c \
		pf_ftoa.c \
		pf_len.c \
		pf_options.c \
		pf_parsing.c \
		pf_put.c \
		pf_router.c \
		pf_struct.c \
		pf_test.c

CHECK =	ft_printf.c \
		pf_base.c \
		pf_ftoa.c \
		pf_len.c \
		pf_options.c \
		pf_parsing.c \
		pf_put.c \
		pf_router.c \
		pf_struct.c

CC = gcc

CFLAGS = -I libft/ #-Wall -Werror -Wextra 

DEBUG= -g3 -fsanitize=address

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@printf "\033[0;32m[Printf] Compilation [o.]\r"
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[Printf] Compilation [.o]\r"

check:
	-@cat $(CHECK) | grep ft_strnew		| grep -v "if (\!(" 
	-@cat $(CHECK) | grep ft_strdup 	| grep -v "if (\!(" 
	-@cat $(CHECK) | grep ft_strndup	| grep -v "if (\!(" 
	-@cat $(CHECK) | grep malloc    	| grep -v "if (\!(" 
	-@cat $(CHECK) | grep printf		| grep -v ft_printf	| grep -v t_printf

$(NAME): $(OBJ)
	@printf "[Printf] Compilation [OK]\n"
	@make -C libft/
	@gcc $(CFLAGS) $(DEBUG) $(OBJ) libft/libft.a
	@ar rc $(NAME) $(OBJ) libft/*.o

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@printf "\033[0;31m[Printf] Deleted *.o\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@make nofclean -C libft/
	@printf "\033[0;31D[Printf] Deleted ft_printf.a\n"

re: fclean all

.PHONY: all clean fclean re
