/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/12 20:34:19 by njerasea         ###   ########.fr       */
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
		tmp = tmp->next;
		i++;
	}
	if (pthread_mutex_init(&env->mutex_door, NULL) != 0)
		return (1);
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
		usleep(5);
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
		usleep(5);
		tmp2 = tmp2->next->next;
		i += 2;
	}
	return (0);
}

int	create_thread(t_env *env)
{
	t_philo *tmp3;
	int	i;

	tmp3 = env->p;
	i = 1;
	if (create_multi_thread(env) == 1)
		return (1);
	pthread_create(&env->checker, NULL, &check_die, env->p);
	while (i <= env->n_philo)
	{
		if (pthread_join((tmp3->thread_philo), NULL) != 0)
			return (1);
		tmp3 = tmp3->next;
		i++;
	}
	pthread_join(env->checker, NULL);
	return (0);
}

int	create_env(t_env *env)
{
	if (env->n_philo == 1)
	{
		ft_print_philo(FORK, ft_gettime(env->p), env->p->id);
		usleep(env->p->t_die * 1000);
		ft_print_philo(DIE, env->p->t_die, env->p->id);
		return (1);
	}
	if (create_mutex(env) == 1)
		return (1);
	if (create_thread(env) == 1)
		return (1);
	ft_destory(env);
	return (0);
}
