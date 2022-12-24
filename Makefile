# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/07 15:08:14 by del-yaag          #+#    #+#              #
#    Updated: 2022/12/24 16:33:15 by del-yaag         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_atoi.c rules_part_one.c sorting_smaller_nums.c helper_function_algo.c\
		rules_part_two.c ft_strjoin.c split.c ft_substr.c chunks_algo.c\
		parsing.c sorting_smaller_two.c push_swap.c

BNS = my_checker/get_next_line_utils.c my_checker/get_next_line.c my_checker/checker.c \
		my_checker/rules_part_two.c my_checker/rules_part_one.c my_checker/ft_strjoin.c \
		my_checker/split.c my_checker/ft_substr.c my_checker/parsing.c my_checker/ft_atoi.c \
		my_checker/fill_free_list.c my_checker/instraction_app.c

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
BONUS = checker

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

$(NAME): $(SRC) push_swap.h
	$(CC) $(CFLAGS) $(SRC) -o $@
	
$(BONUS): $(BNS) my_checker/checker.h
	$(CC) $(CFLAGS) $(BNS) -o $@

clean:
	$(RM) $(NAME) $(BONUS)
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