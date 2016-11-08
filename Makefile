# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonneca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/03 09:59:58 by abonneca          #+#    #+#              #
#    Updated: 2016/11/08 17:28:19 by gepicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc

FLAGS=-Wall -Wextra -Werror

NAME=fillit

SRC=	main.c\
		ft_check.c\

OBJ=$(SRC:.c=.o)

SRC_PATH = srcs/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

$(NAME):
	gcc -c $(FLAGS) $(SRC_POS) -I includes
	gcc  $(OBJ) -I includes -o $(NAME) libft.a

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean
	clean:
	rm -rf $(OBJ)
