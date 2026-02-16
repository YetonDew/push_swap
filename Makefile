# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 17:57:58 by ajeffers          #+#    #+#              #
#    Updated: 2026/02/16 13:11:18 by ajeffers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

SRC = push_swap.c \
	  stack_utils.c \
	  init.c \
	  init_nodes.c \
	  sort_stack.c \
	  sort_small.c \
	  utils.c \
	  swaps.c \
	  push.c \
	  rotations.c \
	  rrotations.c \
	  ft_split.c \
	  ft_strlen.c \
	  ft_substr.c \
	  ft_strlcpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
