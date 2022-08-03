# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 12:49:55 by erickbarros       #+#    #+#              #
#    Updated: 2022/08/03 13:23:43 by erickbarros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror

NAME = minitalk

SRC_CLIENT = client.c		

SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIB_OBJ =	ft_printf/src/*.o \
		 	ft_printf/libft/*.o

all: $(NAME)

$(NAME): $(OBJ_CLIENT) $(OBJ_SERVER)
	@echo "MAKING PRINTF AND LIBFT"
	@$(MAKE) -C ft_printf
	@echo "COMPILING SERVER"
	@$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIB_OBJ) -o server
	@echo "COMPILING CLIENT"
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIB_OBJ) -o client
	@echo "DONE!"

%.o: %.c
	@echo "MAKING OBJECT FILES"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_SERVER) $(OBJ_CLIENT)
	@$(MAKE) -C ft_printf clean
	@echo "OBJS removed"

fclean: clean
	@$(MAKE) -C ft_printf fclean
	@rm -rf client server
	@echo "ALL CLEANED"

re: fclean $(NAME)

.PHONY: all clean fclean re
