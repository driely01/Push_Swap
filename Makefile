# Folders
ALGO = algo/
PARS = parsing/
RULS = rules/
STRS = strings/
CHKR = my_checker/

SRC = push_swap.c\
		${ALGO}sorting_smaller_two.c \
		${ALGO}sorting_smaller_nums.c \
		${ALGO}helper_function_algo.c\
		${ALGO}chunks_algo.c\
		${RULS}rules_part_one.c \
		${RULS}rules_part_two.c \
		${STRS}ft_atoi.c \
		${STRS}ft_strjoin.c \
		${STRS}split.c \
		${STRS}ft_substr.c \
		${PARS}parsing.c
		

BNS = ${CHKR}checker.c \
		${CHKR}${RULS}rules_part_two.c \
		${CHKR}${RULS}rules_part_one.c \
		${CHKR}${PARS}parsing.c \
		${CHKR}${STRS}get_next_line_utils.c \
		${CHKR}${STRS}get_next_line.c \
		${CHKR}${STRS}ft_strjoin.c \
		${CHKR}${STRS}split.c \
		${CHKR}${STRS}ft_substr.c \
		${CHKR}${STRS}ft_atoi.c \
		${CHKR}${STRS}fill_free_list.c \
		${CHKR}${STRS}instraction_app.c

OBJS = $(SRC:.c=.o)
OBJS_BONUS = $(BNS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap
BONUS = checker

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

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
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	
$(BONUS): $(OBJS_BONUS) my_checker/checker.h
	@$(CC) $(CFLAGS) $(OBJS_BONUS) -o $@

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