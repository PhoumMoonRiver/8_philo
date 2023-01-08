# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 14:09:44 by njerasea          #+#    #+#              #
#    Updated: 2023/01/07 14:49:33 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c\
		error_check.c\
		libft/ft_atoi.c

CC = gcc -Wall -Wextra -Werror

RM = rm -rf

all: $(NAME)

$(NAME):
	$(CC) $(SRCS) -o $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
