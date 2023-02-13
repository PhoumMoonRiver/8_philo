/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:47:51 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 19:39:07 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_destory(t_env *env)
{
	int	i;

	i = 1;
	while (i <= env->n_philo)
	{
		pthread_mutex_destroy(&env->p->mutex_fork);
		env->p = env->p->next;
		i++;
	}
}

void	ft_unlock(t_philo *p)
{
	int	i;

	i = 1;
	while (i <= p->tmp_env->n_philo)
	{
		pthread_mutex_unlock(&p->mutex_fork);
		pthread_mutex_unlock(&p->next->mutex_fork);
		i++;
		p = p->next;
	}
}
