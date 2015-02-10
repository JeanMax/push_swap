#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/10 07:31:50 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#$@	Le nom de la cible
#$<	Le nom de la première dépendance
#$^	La liste des dépendances
#$?	La liste des dépendances plus récentes que la cible
#$*	Le nom du fichier sans suffixe

SRC = main.c error.c print.c moves.c brute.c
NAME = push_swap
O_DIR = obj
C_DIR = src
SRCC = $(SRC:%.c=$(C_DIR)/%.c)
SRCO = $(SRC:%.c=$(O_DIR)/%.o)
LIB = libft/libft.a
INC = inc/header.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -f

.PHONY: all clean fclean re debug optimize

all:
	@make -C libft
	@$(MAKE) $(NAME)

$(NAME): $(SRCO) $(LIB) $(INC)
	$(CC) $(CFLAGS) $(SRCO) $(LIB) -o $@

$(O_DIR)/%.o: $(C_DIR)/%.c
	@$(RM) $(NAME)
	$(CC) $(CFLAGS) -c $^ -o $@

soft:
	@$(RM) $(NAME)
	@$(CC) $(SRCC) $(LIB) -o $(NAME)
	@./$(NAME)

debug: re
	@$(CC) $(CFLAGS) -ggdb $(SRCO) $(LIB) -o $(NAME)
	@gdb $(NAME)

optimize: re
	@$(CC) $(CFLAGS) -02 $(SRCO) $(LIB) -o $(NAME)

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
