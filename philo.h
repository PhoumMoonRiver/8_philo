/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:32 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/08 13:33:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>

typedef struct t_enviroment
{
	int	n_philo; //จำนวน philo
	int	t_die; // เวลาตาย
	int	t_eat; // เวลากิน
	int t_sleep; // เวลานอน
	int t_begin; // เวลาเริ่ม
	int r_eat; // จำนวนครั้งที่กิน
	int t_present; // เวลาปัจจุบัน
	int ur_eat; // เวลาอัพเดททุกครั้งที่กิน
	int flag_die; // ธงสัญญาณบอกว่าตายแย้วววว
}	t_env;

/*philo*/
int	argument_check(int ac, char **av);

/*libf*/
int	ft_atoi(const char *str);

# endif
