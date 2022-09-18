NAME = ft_containers_test
MAIN = main.cpp
HEADERS = include
FT_CONT_HEADERS = ../ft_containers/
INCLUDES = -I$(HEADERS) -I$(FT_CONT_HEADERS)

SRCS = src/vector_test.cpp

CXX = g++
FLAGS = -Wall -Wextra -Werror -pthread -std=c++11
LDFLAGS = -lgtest_main -lgtest

# to compile object files to another folder
OBJS = $(patsubst %.cpp,$(OBJS_DIR)/%.o, $(SRCS))
D_FILES = $(patsubst %.cpp,$(OBJS_DIR)/%.d, $(SRCS))
OBJS_DIR = objs
ALL_OBJS_DIRS = $(sort $(dir $(OBJS)))


all: $(NAME)


$(NAME): $(ALL_OBJS_DIRS) $(OBJS) $(MAIN)
	$(CXX) $(FLAGS) $(INCLUDES) $(MAIN) $(OBJS) -o $(NAME) $(LDFLAGS)


$(ALL_OBJS_DIRS): $(OBJS_DIR)
	@mkdir -p $@


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)


$(OBJS_DIR)/%.o:%.cpp
	$(CXX) $(FLAGS) $(INCLUDES) -c $< -o $@ -MMD

include $(wildcard $(D_FILES))


clean:
	rm -rf $(OBJS_DIR)


fclean: clean
	rm -rf $(NAME) $(NAME).dSYM


re: fclean all


init-gtest:
	brew install googletest
