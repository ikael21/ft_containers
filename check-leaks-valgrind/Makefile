NAME =	check_leaks

SRCS =	src/execute_valgrind.cpp	src/get_valgrind_info.cpp\
		src/read_info.cpp			src/parse_info.cpp\
		src/save_info.cpp			src/print_info.cpp

MAIN =	src/main.cpp

OBJS = $(patsubst %.cpp,$(OBJS_DIR)/%.o, $(SRCS))
D_FILES = $(patsubst %.cpp,$(OBJS_DIR)/%.d, $(SRCS))
OBJS_DIR = objs
ALL_OBJS_DIRS = $(sort $(dir $(OBJS)))

CC = clang++
FLAGS = -Wall -Wextra -Werror -std=c++98

#colors for beauty
YELLOW =	\033[33;1m
RESET =		\033[0m
RED =		\033[31;1m
GREEN =		\033[32;1m
MAGENTA =	\033[35;1m

ERASE = \33[2K

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(ALL_OBJS_DIRS) $(OBJS) $(MAIN)
	@$(CC) $(FLAGS) -Iincludes $(MAIN) $(OBJS) -o $(NAME)
	@echo "\n$(MAGENTA)$(NAME) $(GREEN)compiled$(RESET)"

$(ALL_OBJS_DIRS): $(OBJS_DIR)
	@mkdir -p $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o:%.cpp
	@$(CC) $(FLAGS) -Iincludes -c $< -o $@ -MMD
	@printf "$(ERASE)$(RED)>> $(YELLOW)[$@]$(GREEN)$(RESET)\r"

include $(wildcard $(D_FILES))

clean:
	@rm -rf $(OBJS_DIR)
	@rm -rf valgrind_logs
	@echo "$(YELLOW)objs $(RED)deleted$(RESET)"
	@echo "$(YELLOW)valgrind_logs $(RED)deleted$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(MAGENTA)$(NAME) $(RED)deleted$(RESET)"

re: fclean all
