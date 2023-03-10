/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_of_philo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 15:34:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 21:28:21 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *tmp_input)
{
	t_philo	*tmp;

	tmp = (t_philo *)tmp_input;
	while (tmp->tmp_env->sign_die == 0)
	{
		if (routine_eat(tmp) == 1)
			break ;
		if (tmp->r_eat == 0)
			tmp->tmp_env->eat_full++;
		if (tmp->tmp_env->eat_full >= tmp->tmp_env->n_philo)
			break ;
		if (routine_sleep_think(tmp) == 1)
			break ;
	}
	return (NULL);
}

int	routine_eat(t_philo *p)
{
	if (p->tmp_env->sign_die == 1)
		return (1);
	pthread_mutex_lock(&p->next->mutex_fork);
	if (p->tmp_env->sign_die == 1)
		return (1);
	ft_print_philo(FORK, ft_gettime(p), p->id);
	pthread_mutex_lock(&p->mutex_fork);
	if (p->tmp_env->sign_die == 1)
		return (1);
	ft_print_philo(FORK, ft_gettime(p), p->id);
	gettimeofday(&p->time_eat, NULL);
	p->r_eat--;
	ft_print_philo(EAT, ft_gettime(p), p->id);
	ft_usleep_get_die(p->t_eat);
	if (p->tmp_env->sign_die == 1)
		return (1);
	pthread_mutex_unlock(&p->mutex_fork);
	pthread_mutex_unlock(&p->next->mutex_fork);
	return (0);
}

int	routine_sleep_think(t_philo *p)
{
	if (p->tmp_env->sign_die == 1)
		return (1);
	ft_print_philo(SLEEP, ft_gettime(p), p->id);
	if (p->tmp_env->sign_die == 1)
		return (1);
	ft_usleep_get_die(p->t_sleep);
	if (p->tmp_env->sign_die == 1)
		return (1);
	ft_print_philo(THINK, ft_gettime(p), p->id);
	return (0);
}

void	routine_die(t_philo *p)
{
	ft_print_philo(DIE, ft_gettime(p), p->id);
}
