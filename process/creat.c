/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 15:17:26 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_mutex(t_env *env)
{
	t_philo	*tmp;
	int	i;

	tmp = env->p;
	i = 1;
	while (i <= env->n_philo)
	{
		if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
			return (1);
		if (pthread_mutex_init(&tmp->mutex_door, NULL) != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	create_multi_thread(t_env *env)
{
	t_philo *tmp1;
	t_philo *tmp2;
	int	i;

	tmp1 = env->p;
	tmp2 = env->p;
	i = 1;
	while (i <= env->n_philo)
	{
		if (pthread_create((&tmp1->thread_philo), NULL, &routine, tmp1) != 0)
			return (1);
		usleep(10);
		if (!tmp1->next)
			break ;
		tmp1 = tmp1->next->next;
		i += 2;
	}
	i = 2;
	usleep(50);
	tmp2 = tmp2->next;
	while (i <= env->n_philo)
	{
		if (pthread_create((&tmp2->thread_philo), NULL, &routine, tmp2) != 0)
			return (1);
		usleep(10);
		tmp2 = tmp2->next->next;
		i += 2;
	}
	return (0);
}

int	create_thread(t_env *env)
{
	t_philo *tmp3;

	tmp3 = env->p;
	if (create_multi_thread(env) == 1)
		return (1);
	while (tmp3)
	{
		if (pthread_join((tmp3->thread_philo), NULL) != 0)
			return (1);
		tmp3 = tmp3->next;
	}
	return (0);
}

int	create_env(t_env *env)
{
	if (env->n_philo == 1)
	{
		gettimeofday(&env->p->time_eat, NULL);
		ft_print_philo(FORK, ft_gettime(env->p), env->p->id);
		usleep(env->p->t_die * 1000);
		ft_print_philo(DIE, env->p->t_die, env->p->id);
		return (1);
	}
	if (create_mutex(env) == 1)
		return (1);
	if (create_thread(env) == 1)
		return (1);
	pthread_create(&env->checker, NULL, &check_die, env->p);
	pthread_join(env->checker, NULL);
	return (0);
}
