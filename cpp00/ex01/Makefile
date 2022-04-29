# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cfiliber <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/09 18:45:41 by cfiliber          #+#    #+#              #
#    Updated: 2022/04/29 16:58:59 by cfiliber         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = my_awesome_phonebook

SRCS = \
		main.cpp\
		PhoneBook.Class.cpp\
		Contact.Class.cpp 

OBJS = $(SRCS:.cpp=.o)

CC = clang++

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

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo $(GREEN)$(CURSIVE)"\nAll files have been compiled"$(RESET)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
