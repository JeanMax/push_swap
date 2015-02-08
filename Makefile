#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/29 13:16:03 by mcanal            #+#    #+#              #
#    Updated: 2015/02/08 20:27:20 by mcanal           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

#$@	Le nom de la cible
#$<	Le nom de la première dépendance
#$^	La liste des dépendances
#$?	La liste des dépendances plus récentes que la cible
#$*	Le nom du fichier sans suffixe

SRCC = 	main.c test.c
NAME = push_swap
SRCZ = $(SRCC:%.c=src/%.c)
SRCO = $(SRCC:%.c=obj/%.o)
LIB = libft/libft.a
INC = inc/header.h
CFLAGS = -Wall -Werror -Wextra
CC = gcc
RM = rm -f

.PHONY: all lib brute clean fclean white_storm re

all: $(NAME)

$(NAME): $(SRCO) $(LIB)
	make -C libft
	$(CC) $(CFLAGS) $(SRCO) $(LIB) -o $(NAME) || $(RM) $(NAME)

obj/main.o: src/main.c $(INC)
	$(CC) $(CFLAGS) -c src/main.c -o obj/main.o || $(RM) $(NAME)
obj/test.o: src/test.c $(INC)
	$(CC) $(CFLAGS) -c src/test.c -o obj/test.o || $(RM) $(NAME)

lib:
	@make re -C libft

soft:
	@$(RM) $(NAME)
	@$(CC) $(SRCZ) -o $@ -I ./libft/inc/ -I ./ libft/libft.a

clean:
	@$(RM) $(SRCO)

fclean: clean
	@$(RM) $(NAME)

white_storm: fclean
	@$(RM) $(LIB)

brute: white_storm all

re: fclean all
