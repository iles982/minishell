# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tclarita <tclarita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 14:37:11 by tclarita          #+#    #+#              #
#    Updated: 2020/10/22 11:18:26 by tclarita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

LIBFT_PRINTF = printf

INCLUDES = minishell.h

HEADER = minishell.h

SRC =	do_comands.c minishell.c set_env.c comands.c echo.c cd.c \
		unset_env.c ft_strtok.c cd_2.c tools.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I $(HEADER)
LIBA = printf/libftprintf.a
all: $(NAME)

$(NAME): $(OBJ) $(SRC)
		@make -C $(LIBFT_PRINTF)
		@gcc -c $(SRC)
		@gcc -o $(NAME) $(FLAGS) $(OBJ) $(LIBA)

clean:
		@make clean -C $(LIBFT_PRINTF)
		@rm -rf $(OBJ)

fclean: clean
		@make fclean -C $(LIBFT_PRINTF)
		@rm -rf $(NAME)

re: fclean all
