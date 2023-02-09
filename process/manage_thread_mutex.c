/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_thread_mutex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 17:18:07 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 18:51:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	lock_door(t_philo *p)
{
	t_philo *first;

	first = p;
	pthread_mutex_lock(&first->mutex_door);
	// pthread_mutex_lock(&first->next->mutex_door);
	// pthread_mutex_lock(&first->next->next->mutex_door);
	// pthread_mutex_lock(&first->next->next->next->mutex_door);
	// pthread_mutex_lock(&first->next->next->next->next->mutex_door);
}

void	unlock_door(t_philo *p)
{
	t_philo	*first;

	first = p;
	// pthread_mutex_unlock(&first->mutex_door);
	// pthread_mutex_unlock(&first->next->mutex_door);
	pthread_mutex_unlock(&first->next->next->mutex_door);
	// pthread_mutex_unlock(&first->next->next->next->mutex_door);
	// pthread_mutex_unlock(&first->next->next->next->next->mutex_door);
}
