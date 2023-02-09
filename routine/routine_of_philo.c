/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_of_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 18:52:03 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *tmp_input)
{
	t_philo *tmp;

	tmp = (t_philo *)tmp_input;
	while (1)
		if (routine_eat(tmp) == 1)
			break ;
	return (NULL);
}


int	routine_eat(t_philo *p)
{
lock_door(p);
	pthread_mutex_lock(&p->mutex_fork);
	ft_print_philo(FORK, ft_gettime(p), p->id);
	pthread_mutex_lock(&p->next->mutex_fork);
	ft_print_philo(FORK, ft_gettime(p), p->id);

	// gettimeofday(&p->time_eat, NULL);
	ft_print_philo(EAT, ft_gettime(p), p->id);
	ft_usleep_get_die(p->t_eat, p->t_die, &p->alive);
	pthread_mutex_unlock(&p->mutex_fork);
	pthread_mutex_unlock(&p->next->mutex_fork);
unlock_door(p);
	return (0);
}
