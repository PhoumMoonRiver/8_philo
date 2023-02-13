/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:13:34 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 21:18:52 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_mutex(t_env *env)
{
	int		i;
	t_philo	*tmp;

	tmp = env->p;
	i = 1;
	while (i <= env->n_philo)
	{
		if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

int	create_thread(t_env *env)
{
	int		i;
	t_philo	*tmp3;

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
	tmp3->tmp_env->unlock = 0;
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
