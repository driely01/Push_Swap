# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 15:08:14 by del-yaag          #+#    #+#              #
#    Updated: 2022/12/27 15:51:49 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c rules_part_one.c sorting_smaller_nums.c helper_function_algo.c\
		rules_part_two.c ft_strjoin.c split.c ft_substr.c chunks_algo.c\
		parsing.c sorting_smaller_two.c push_swap.c

BNS = my_checker/get_next_line_utils.c my_checker/get_next_line.c my_checker/checker.c \
		my_checker/rules_part_two.c my_checker/rules_part_one.c my_checker/ft_strjoin.c \
		my_checker/split.c my_checker/ft_substr.c my_checker/parsing.c my_checker/ft_atoi.c \
		my_checker/fill_free_list.c my_checker/instraction_app.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BNS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
BONUS = checker

%.o: %.c
	$(CC) $(CC_FLAGS) -c $< -o $@

all: $(NAME)
	@echo ""
	@echo ""
	@echo "			██████╗██╗   ███████████╗  ██╗    █████████╗    ██╗█████╗██████╗ "
	@echo "			██╔══████║   ████╔════██║  ██║    ██╔════██║    ████╔══████╔══██╗"
	@echo "			██████╔██║   ████████████████║    █████████║ █╗ ███████████████╔╝"
	@echo "			██╔═══╝██║   ██╚════████╔══██║    ╚════████║███╗████╔══████╔═══╝ "
	@echo "			██║    ╚██████╔█████████║  ██║    ███████╚███╔███╔██║  ████║     "
	@echo "			╚═╝     ╚═════╝╚══════╚═╝  ╚═╝    ╚══════╝╚══╝╚══╝╚═╝  ╚═╚═╝     "
	@echo "					--wlecome to push swap world--"
	@echo ""
	@echo ""

bonus: $(BONUS)
	@echo ""
	@echo ""
	@echo "		▄████████    ▄█    █▄       ▄████████  ▄████████    ▄█   ▄█▄    ▄████████    ▄████████ "
	@echo "		███    ███   ███    ███     ███    ███ ███    ███   ███ ▄███▀   ███    ███   ███    ███ "
	@echo "		███    █▀    ███    ███     ███    █▀  ███    █▀    ███▐██▀     ███    █▀    ███    ███ "
	@echo "		███         ▄███▄▄▄▄███▄▄  ▄███▄▄▄     ███         ▄█████▀     ▄███▄▄▄      ▄███▄▄▄▄██▀ "
	@echo "		███        ▀▀███▀▀▀▀███▀  ▀▀███▀▀▀     ███        ▀▀█████▄    ▀▀███▀▀▀     ▀▀███▀▀▀▀▀   "
	@echo "		███    █▄    ███    ███     ███    █▄  ███    █▄    ███▐██▄     ███    █▄  ▀███████████ "
	@echo "		███    ███   ███    ███     ███    ███ ███    ███   ███ ▀███▄   ███    ███   ███    ███ "
	@echo "		████████▀    ███    █▀      ██████████ ████████▀    ███   ▀█▀   ██████████   ███    ███ "
	@echo ""
	@echo "						checking..."
	@echo ""
	@echo ""

$(NAME): $(OBJS) push_swap.h
	$(CC) $(CFLAGS) $(OBJS) -o $@
	
$(BONUS): $(OBJS_BONUS) my_checker/checker.h
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	@echo ""
	@echo ""
	@echo "		▄████▄  ██▓   ▓█████▄▄▄      ███▄    █▓█████▓█████▄ "
	@echo "		▒██▀ ▀█ ▓██▒   ▓█   ▒████▄    ██ ▀█   █▓█   ▀▒██▀ ██▌"
	@echo "		▒▓█    ▄▒██░   ▒███ ▒██  ▀█▄ ▓██  ▀█ ██▒███  ░██   █▌"
	@echo "		▒▓▓▄ ▄██▒██░   ▒▓█  ░██▄▄▄▄██▓██▒  ▐▌██▒▓█  ▄░▓█▄   ▌"
	@echo "		▒ ▓███▀ ░██████░▒████▓█   ▓██▒██░   ▓██░▒████░▒████▓ "
	@echo "		░ ░▒ ▒  ░ ▒░▓  ░░ ▒░ ▒▒   ▓▒█░ ▒░   ▒ ▒░░ ▒░ ░▒▒▓  ▒ "
	@echo "		░  ▒  ░ ░ ▒  ░░ ░  ░▒   ▒▒ ░ ░░   ░ ▒░░ ░  ░░ ▒  ▒ "
	@echo "		░         ░ ░     ░   ░   ▒     ░   ░ ░   ░   ░ ░  ░ "
	@echo "		░ ░         ░  ░  ░  ░    ░  ░        ░   ░  ░  ░    "
	@echo "		░                                             ░      "
	@echo ""
	@echo ""

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: re fclean clean all