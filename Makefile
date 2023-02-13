# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 14:09:44 by njerasea          #+#    #+#              #
#    Updated: 2023/02/13 21:59:31 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c\
		error_check.c\
		process/keep_input.c\
		process/create.c\
		process/create_multi_thread.c\
		process/gettime.c\
		process/die.c\
		process/clear.c\
		routine/routine_of_philo.c\
		libft/ft_atoi.c\
		libft/ft_print_philo.c\
		libft/ft_free_list.c\
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
	$(RM) philo.dSYM

re: fclean all

a: re
	./philo 1 800 200 200

b: re
	./philo 5 800 200 200

c: re
	./philo 5 800 200 200 2

d: re
	./philo 4 410 200 200

e: re
	./philo 4 310 200 100

f: re
	./philo 0 100 50 40

g: re
	./philo 4 400 "" 100

h: re
	./philo 50 300 100 100 4

i: re
	valgrind --leak-check=full ./philo 4 310 200 200

j: re
	valgrind --leak-check=full ./philo 5 800 200 200 2

.PHONY: all clean fclean re
