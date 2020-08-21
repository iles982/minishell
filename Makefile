# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 14:37:11 by tclarita          #+#    #+#              #
#    Updated: 2020/08/18 15:05:17 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_PRINTF = printf

INCLUDES = includes

HEADER = minishell.h

SRC = do_comands.c minishell.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror
LIBA = printf/libftprintf.a
all: $(NAME)

$(NAME): $(OBJ) $(SRC)
		@make -C $(LIBFT_PRINTF)
		@clang $(FLAGS) -c $(SRC) $(LIBA)

clean:
		@make clean -C $(LIBFT_PRINTF)
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT_PRINTF)
		@rm -rf $(NAME)

re: fclean all
