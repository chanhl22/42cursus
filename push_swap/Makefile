# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhlee <chanhlee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/28 19:53:32 by chanhlee          #+#    #+#              #
#    Updated: 2021/05/28 20:53:56 by chanhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
LIB     =       libft
PUSH_SWAP_DIR =		srcs

SRCS  =   ./$(PUSH_SWAP_DIR)/iter_command.c ./$(PUSH_SWAP_DIR)/get_value_in_lst.c ./$(CHECK_DIR)/check_descending.c ./$(PUSH_SWAP_DIR)/main.c ./$(PUSH_SWAP_DIR)/find_chunk.c  ./$(PUSH_SWAP_DIR)/get_idx_in_lst.c  ./$(PUSH_SWAP_DIR)/print_commands.c  ./$(PUSH_SWAP_DIR)/push_swap.c ./$(CHECK_DIR)/sa.c ./$(CHECK_DIR)/sb.c ./$(CHECK_DIR)/ss.c ./$(CHECK_DIR)/pa.c\
					 ./$(CHECK_DIR)/pb.c ./$(CHECK_DIR)/ra.c ./$(CHECK_DIR)/rb.c ./$(CHECK_DIR)/rr.c ./$(CHECK_DIR)/rra.c ./$(CHECK_DIR)/rrb.c ./$(CHECK_DIR)/rrr.c ./$(CHECK_DIR)/check_argv.c\
					 ./$(PUSH_SWAP_DIR)/check_little_number.c ./$(PUSH_SWAP_DIR)/check_five.c ./$(PUSH_SWAP_DIR)/check_three.c ./$(PUSH_SWAP_DIR)/get_chunk.c 

INC_DIR = ./
OBJ = $(SRCS:.c=.o)
CC			= gcc
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -I. 
OPTIONS = -I$(INC_DIR) -I./libft -lft -L./libft

all:     $(LIB) $(NAME)

$(LIB): relib cleanlib

$(NAME):  $(LIB) $(OBJ)
					${CC} ${CFLAGS} -o ${NAME} ${OPTIONS} ${OBJ}

clean:    cleanlib
				rm -rf $(OBJ)

fclean:   clean fcleanlib
				rm -rf $(NAME)

re:       fclean all

relib:
	@$(MAKE) -C ./Libft re

cleanlib:
	@$(MAKE) -C ./Libft clean

fcleanlib: cleanlib
	@$(MAKE) -C ./Libft fclean