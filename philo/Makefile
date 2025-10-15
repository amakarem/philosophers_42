# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelaaser <aelaaser@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/15 20:54:50 by aelaaser          #+#    #+#              #
#    Updated: 2025/10/15 20:54:56 by aelaaser         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Library name
NAME = philo

# Compiler and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Source files
SRCS = 	eat.c init_data.c int_reader.c mutex.c philo.c routine.c service.c time.c utils.c validation.c

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