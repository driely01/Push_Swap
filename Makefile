# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 15:08:14 by del-yaag          #+#    #+#              #
#    Updated: 2022/12/21 17:19:10 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c rules_part_one.c sorting.c helper_function_algo.c\
		rules_part_two.c ft_strjoin.c split.c ft_substr.c chunks_algo.c\
		parce.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap.a

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all
