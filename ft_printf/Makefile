# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chanhlee <chanhlee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/24 17:00:52 by chanhlee          #+#    #+#              #
#    Updated: 2021/04/29 16:49:37 by chanhlee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
LIBFT		= libft
LIBFT_LIB	= libft.a
SRCS		= ./ft_printf.c ./print_c.c\
			  ./print_p.c ./print_s.c ./print_u.c ./print_x.c
OBJS		= $(SRCS:.c=.o)
RM			= rm -f
AR			= ar rc
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

$(NAME) : $(OBJS)
	make all -C $(LIBFT)/
	cp $(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean :
	$(RM) $(OBJS)
	make clean -C $(LIBFT)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re : fclean all

.PHONY: all clean fclean re
