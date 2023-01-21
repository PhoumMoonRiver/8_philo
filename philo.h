/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:32 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/21 12:34:08 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>

typedef struct t_philosopher_data
{
	int	id;
	int	t_die;
	int	t_eat;
	int	t_sleep;
	int	r_eat;
	int	fork_left;
	int	fork_right;
	pthread_t	thread;
	struct t_philosopher_data *next;
}	t_philo;

typedef struct t_enviroment
{
	t_philo	*p;
	t_philo *tmp_head;
	int	i;
	int	n_philo;
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
void	init_list_of_philo(int ac, char **av, t_env *env);
void	keep_input_to_list(int ac, char **av, t_env *env);
void	creat_env(t_env *env);
void	creat_thread(t_env *env);

/*libf*/
int	ft_atoi(const char *str);

/*debug*/
void	show_philo(t_env *env, t_philo *h);

# endif
