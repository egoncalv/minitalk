# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erickbarros <erickbarros@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 01:22:21 by egoncalv          #+#    #+#              #
#    Updated: 2022/08/03 13:24:22 by erickbarros      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FLAG = -Wall -Wextra -Werror

NAME = libftprintf.a

SRC =	src/ft_printf.c \
		src/ft_treat_hex.c \
		src/ft_printf_utils.c \
		src/ft_uitoa.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft/ bonus
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	@ar rcs $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c 
	@gcc $(FLAG) -c $< -o $@

clean:
	@$(MAKE) -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@$(MAKE) -C libft/ clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean $(NAME)

test:
	@gcc main.c libftprintf.a libft/libft.a

retest: re test
	@echo "\n\n\n"
	@./a.out

.PHONY: all clean fclean re bonus 
