# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 14:09:44 by njerasea          #+#    #+#              #
#    Updated: 2023/01/15 10:11:37 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c\
		error_check.c\
		creat_philo.c\
		libft/ft_atoi.c\
		debug/link_list1.c

CC = gcc -Wall -Wextra -Werror
RM = rm -rf
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

a: re
	./philo 5 100 20 20

b: re
	./philo 5 100 20 20 20

.PHONY: all clean fclean re
