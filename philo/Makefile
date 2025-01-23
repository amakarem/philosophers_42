# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 18:38:23 by aelaaser          #+#    #+#              #
#    Updated: 2025/01/23 19:29:35 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = philo

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	action.c eat.c eat_ext.c parse.c philo.c philo_init.c philo_utils.c status.c time.c utils.c watch.c

OBJS = $(SRCS:.c=.o)

# Default target
all: $(NAME)

# Rule to create the static library
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# Rule to compile the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re