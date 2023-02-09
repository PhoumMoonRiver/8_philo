/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_of_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 15:04:15 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *tmp_input)
{
	t_philo *tmp;

	tmp = (t_philo *)tmp_input;
	routine_eat(tmp);
	return (NULL);
}


int	routine_eat(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_door); //ล็อกห้อง
	pthread_mutex_lock(&p->mutex_fork); //เก็บ fork ตนเอง
	ft_print_philo(FORK, 0, p->id);
	pthread_mutex_lock(&p->next->mutex_fork); // เก็บ fork philo ด้านข้าง
	ft_print_philo(FORK, 0, p->id);
	pthread_mutex_unlock(&p->mutex_door); //เปิดห้อง
	ft_print_philo(EAT, 0, p->id);
	pthread_mutex_unlock(&p->mutex_fork);
	pthread_mutex_unlock(&p->next->mutex_fork);
	return (0);
}
