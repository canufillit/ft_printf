# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apeyret <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/10 18:24:48 by apeyret           #+#    #+#              #
#    Updated: 2019/04/12 17:25:28 by ktlili           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		ft_printf 

CC =		gcc	

CFLAGS =	-I inc/ -I libft/ -Wall -Werror -Wextra

INC_DIR =	inc

INC_FILE =	ft_printf.h

SRC_DIR =	src

SRC_FILE =	pf_put.c	\
		pf_options.c	\
		pf_len.c	\
		pf_utils.c	\
		pf_router.c	\
		pf_struct.c	\
		pf_test.c	\
		ft_printf.c	\
		pf_parsing.c	\
		pf_base.c	\
		pf_ftoa.c

OBJ_DIR =	.obj
OBJ_FILE =	$(SRC_FILE:.c=.o)

CRT_DIR =	.

SRC = 		$(addprefix $(SRC_DIR)/,$(SRC_FILE))
INC = 		$(addprefix $(INC_DIR)/,$(INC_FILE))
OBJ = 		$(addprefix $(OBJ_DIR)/,$(OBJ_FILE))
CRT = 		$(addprefix $(OBJ_DIR)/,$(CRT_DIR))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(INC) Makefile
	@printf "\033[0;32m[ft_printf] Compilation [o.]\033[0;0m\r"
	@mkdir -p $(CRT) 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "\033[0;32m[ft_printf] Compilation [.o]\033[0;0m\r"

norm:
	@norminette $(SRC)
	@norminette $(INC)

$(NAME): $(OBJ)
	@printf "\033[0;32m[ft_printf] Compilation [OK]\033[0;0m\n"
	@make -C libft/
	@ar rc $(NAME) $(OBJ) libft/libft.a

clean:
	@make clean -C libft/
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf $(OBJ_DIR)
	@printf "\033[0;31m[ft_printf] Deleted *.o\033[0;0m\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f libft/libft.a
	@printf "\033[0;31D[ft_printf] Deleted ft_printf\033[0;0m\n"

re: fclean all

.PHONY: all clean fclean re
