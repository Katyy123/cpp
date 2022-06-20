# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/16 16:09:24 by cfiliber          #+#    #+#              #
#    Updated: 2022/06/20 18:59:28 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Polymorphism

SRCS = \
		main.cpp\
		Animal.cpp\
		Dog.cpp\
		Cat.cpp\
		WrongAnimal.cpp\
		WrongCat.cpp\
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -g #-fsanitize=address

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

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll files have been compiled"$(RESET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
