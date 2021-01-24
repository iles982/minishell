# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 14:37:11 by tclarita          #+#    #+#              #
#    Updated: 2021/01/24 18:32:20 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CYAN     = \033[36m
RED      = \033[31m
RESET    = \033[0m

NAME = minishell

LIBFT_PRINTF = printf

INCLUDES = minishell.h

HEADER = minishell.h

SRC =	do_comands.c minishell.c set_env.c comands.c echo.c \
		unset_env.c ft_strtok.c tools.c bonuses.c new_cd.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I $(HEADER)
LIBA = printf/libftprintf.a
all: $(NAME)

$(NAME): $(OBJ) $(SRC)
		@make -C $(LIBFT_PRINTF)
		@gcc -c $(SRC)
		@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBA)

norm:
	@echo "$(RED)Checking project files by norminette ...$(RESET)"
	@norminette *.c *.h printf/libft/*.c printf/libft/*.h printf/*.c printf/*.h
	@echo "$(RED)Norm check complitted!$(RESET)"

clean:
		@make clean -C $(LIBFT_PRINTF)
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT_PRINTF)
		@rm -rf $(NAME)

re: fclean all
