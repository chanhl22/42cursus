# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:53:32 by chanhlee          #+#    #+#              #
#    Updated: 2021/06/16 10:02:42 by chanhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIB = libft
PUSH_SWAP_DIR = srcs

SRCS  =   ./$(PUSH_SWAP_DIR)/build.c ./$(PUSH_SWAP_DIR)/main.c ./$(PUSH_SWAP_DIR)/parse_nb_from_str.c\
			./$(PUSH_SWAP_DIR)/a_functions.c ./$(PUSH_SWAP_DIR)/b_functions.c ./$(PUSH_SWAP_DIR)/solve.c\
			./$(PUSH_SWAP_DIR)/run_commands.c ./$(PUSH_SWAP_DIR)/get_median.c

INC_DIR = ./
OBJ = $(SRCS:.c=.o)
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -I. 
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft

all:     $(LIB) $(NAME)

$(LIB): relib cleanlib

$(NAME):  $(LIB) $(OBJ)
					${CC} ${CFLAGS} -o ${NAME} ${OPTIONS} ${OBJ}

relib:
	@$(MAKE) -C ./Libft re

cleanlib:
	@$(MAKE) -C ./Libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./Libft fclean

clean:    cleanlib
				rm -rf $(OBJ)

fclean:   clean fcleanlib
				rm -rf $(NAME)

re:       fclean all