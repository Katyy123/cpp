NAME = tests

PROGRAM_DIR = ../

SRCS = \
		tests.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g -fsanitize=address

GREEN = '\x1b[32m'
YELLOW = '\x1b[33m'
RED = '\x1b[31m'
MAGENTA = '\x1b[35m'
CYAN = '\x1b[36m'
GRAY = '\x1b[2;37m'
CURSIVE = '\x1b[3m'
RESET = '\x1b[0m'

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) program
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll files have been compiled"$(RESET)

program: 
	@printf "Compiling program to test..." && make -C $(PROGRAM_DIR)

clean:
	@make clean -C $(PROGRAM_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(PROGRAM_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
