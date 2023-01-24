/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:32 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/24 19:58:51 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

# define FORK "\033[1;36m%d ms %d has taken Fork\033[0m\n"
# define EAT "\033[1;33m%d ms %d is Eating\033[0m\n"
# define SLEEP "\033[1;34m%d ms %d is Sleeping\033[0m\n"
# define THINK "\033[1;32m%d ms %d is Thinking\033[0m\n"
# define DIE "\033[1;31m%d ms %d is Died\033[0m\n"

typedef struct t_philosopher_data
{
	int	i;
	int	id;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	r_eat;
	int	fork_left;
	int	fork_right;
	long long	current_time1;
	long long	current_time2;
	pthread_t	thread_philo;
	pthread_mutex_t mutex_fork;
	struct timeval time;
	struct t_philosopher_data *next;
}	t_philo;

typedef struct t_enviroment
{
	t_philo	*p;
	pthread_mutex_t mutex_door;
	int	n_philo;
	int	i;
	/*
	int t_begin; // เวลาเริ่ม
	int r_eat; // จำนวนครั้งที่กิน
	int t_present; // เวลาปัจจุบัน
	int ur_eat; // เวลาอัพเดททุกครั้งที่กิน
	int flag_die; // ธงสัญญาณบอกว่าตายแย้วววว
	*/
}	t_env;

/*philo*/
int	argument_check(int ac, char **av);
int	check_digit(char **av);
int	create_thread(t_env *env);
int	create_mutex(t_env *env);
int	create_env(t_env *env);
long long	ft_gettime(t_philo *p);
void	init_list_of_philo(int ac, char **av, t_env *env);
void	keep_input_to_list(int ac, char **av, t_env *env);
void	*routine(void *env_input);
void	ft_print_philo(char *str, long long time, int id);

/*libf*/
int	ft_atoi(const char *str);

/*debug*/
void	show_philo(t_env *env, t_philo *h);

# endif
