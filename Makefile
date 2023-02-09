# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: njerasea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/07 14:09:44 by njerasea          #+#    #+#              #
#    Updated: 2023/02/09 17:18:48 by njerasea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCS = 	philo.c\
		error_check.c\
		process/keep_input.c\
		process/creat.c\
		process/gettime.c\
		process/die.c\
		process/manage_thread_mutex.c\
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

re: fclean all

a: re
	./philo 5 100 50 40

b: re
	./philo 5 100 30 30 20

c: re
	./philo 1 100 50 40

e: re
	./philo 0 100 50 40

v: re
	valgrind --leak-check=full --show-leak-kinds=all ./philo 5 100 50 40

.PHONY: all clean fclean re
