# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajeffers <ajeffers@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 17:57:58 by ajeffers          #+#    #+#              #
#    Updated: 2026/02/09 17:59:23 by ajeffers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -fr

SRC = ft_print_char.c \
ft_print_str.c \
ft_print_nbr.c \
ft_print_ptr.c \
ft_print_unsig.c \
ft_print_hex.c \
ft_itoa.c \
ft_print_percent.c \
ft_printf.c

OSRC = $(SRC:.c=.o)
TARGET = libftprintf.a

all: $(TARGET)

$(TARGET): $(OSRC)
		$(AR) $(TARGET) $(OSRC)

clean:
		rm -f $(OSRC)

fclean: clean
		rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re
