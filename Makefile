# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmlitvin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/06 22:47:34 by dmlitvin          #+#    #+#              #
#    Updated: 2019/09/13 20:37:24 by dmlitvin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit

LIBFT=libft/libft.a

FLAGS=-Wall -Wextra -Werror

CC=clang $(FLAGS)

SRC=main.c corectness.c parse_file.c t_back.c t_figures.c algoritm.c

SRO=$(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRO) $(LIBFT)
	@$(CC) $(SRO) $(LIBFT) -o $(NAME) && printf "\x1b[32mBinary file compiled \
	succesfully!\nLaunch: $(NAME) \"source_file\"\n\x1b[0m"

$(SRO): $(LIBFT) $(SRC) fillit.h
	@$(CC) -c $(SRC) && printf "\x1b[32mObject files compiled succesfully!\n\x1b[0m"

$(LIBFT):
	@make -C libft/

clean:
	@rm -f $(SRO) && printf "\x1b[31mObject files have been deleted!\n\x1b[0m"
	@make clean -C libft/

fclean: clean
	@rm -f $(NAME) && printf "\x1b[31mBinary file has been deleted!\n\x1b[0m"
	@make fclean -C libft/

re: fclean all

.PHONY: re clean fclean all
