TEST1 = vector_speed_test
TEST1_SRC = vector_speed_test.cpp
CONT_DIR = ../ft_containers
CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++11

#colors for beauty
YELLOW =	\033[33;1m
RESET =		\033[0m
RED =		\033[31;1m
GREEN =		\033[32;1m
MAGENTA =	\033[35;1m

.PHONY: all clean fclean re

all: $(TEST1)

$(TEST1):
	@$(CC) $(FLAGS) -I$(CONT_DIR) $(TEST1_SRC) -o $(TEST1)
	@echo "$(MAGENTA)$(TEST1) $(GREEN)compiled$(RESET)"

fclean:
	@rm -rf $(TEST1)
	@echo "$(MAGENTA)$(TEST1) $(RED)removed$(RESET)"

re: fclean all
