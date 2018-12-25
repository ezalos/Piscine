# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brichard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/15 13:33:17 by brichard          #+#    #+#              #
#    Updated: 2018/09/16 23:33:45 by brichard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = colle-2

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INC = includes

SRC_PATH = srcs

OBJ_PATH = obj

SRCS = print_machine.c \
	   ft_brain.c \
	   main.c \
	   read_file.c \
	   ft_check.c \
	   ft_print.c \
	   ft_split.c \
	   ft_split_2.c \
	   rush0x.c

OBJS = $(SRCS:.c=.o)

D_OBJS = $(addprefix $(OBJ_PATH)/, $(OBJS))

all: $(NAME)

$(NAME): $(D_OBJS)
	@echo "Compiling..."
	@$(CC) $(CFLAGS) -o $(NAME) $(D_OBJS)
	@echo "Done"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "Creating obj..."
	@$(CC) $(CFLAGS) -o $@ -c $< -I$(INC)
	@echo "Done"

clean:
	@echo "Cleaning objs"
	@rm -f $(D_OBJS)
	@echo "Done"

fclean: clean
	@echo "Cleaning project"
	@rm -f $(NAME)
	@echo "Done"

re: fclean all
