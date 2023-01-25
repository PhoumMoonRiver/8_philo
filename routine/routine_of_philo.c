/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_of_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/25 14:09:07 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	routine_eat(t_philo *p)
{
	pthread_mutex_lock(&p->mutex_door); //ล็อกห้อง
	pthread_mutex_lock(&p->mutex_fork); //เก็บ fork ตนเอง
	ft_print_philo(FORK, 0, p->id);
	pthread_mutex_lock(&p->next->mutex_fork); // เก็บ fork philo ด้านข้าง
	ft_print_philo(FORK, 0, p->id);
	pthread_mutex_unlock(&p->mutex_door); //เปิดห้อง
	return (0);
}
