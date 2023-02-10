/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:42 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/10 23:28:56 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_check_time(t_philo *tmp)
{
	struct timeval	now;
	long	time_eat_old;
	long	time_now;
	int	i;

	i = 0;
	while (i < tmp->tmp_env->n_philo)
	{
		time_eat_old = (tmp->time_eat.tv_sec * 1000) + (tmp->time_eat.tv_usec / 1000);
		gettimeofday(&now, NULL);
		time_now = (now.tv_sec * 1000) + (now.tv_usec / 1000);
		if (time_now - time_eat_old >= (long)tmp->t_die)
		{
			tmp->alive = 1;
			routine_die(tmp);
			break ;
		}
		tmp = tmp->next;
		i++;
	}
}

void	*check_die(void *p)
{
	t_philo *tmp;

	tmp = (t_philo *)p;
	while (1)
	{
		while (tmp)
		{
			if (tmp->alive == 1)
				break ;
			tmp = tmp->next;
		}
	}
	return (NULL);
}
