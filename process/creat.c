/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/24 19:59:44 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *tmp_input)
{
	t_philo *tmp;

	tmp = (t_philo *)tmp_input;
	printf("HI\n");
// pthread_mutex_lock(&tmp->mutex_fork);
	// while (1)
	// {
	// 	ft_print_philo(FORK, ft_gettime(tmp), tmp->id);
	// 	ft_print_philo(DIE, ft_gettime(tmp), tmp->id);
	// 	ft_print_philo(EAT, ft_gettime(tmp), tmp->id);
	// }
// pthread_mutex_unlock(&tmp->mutex_fork);
	return (NULL);
}

int	create_mutex(t_env *env)
{
	t_philo	*tmp;

	tmp = env->p;
	while (tmp)
	{
		if (pthread_mutex_init(&tmp->mutex_fork, NULL) != 0)
			return (1);
		tmp = tmp->next;
	}
	if (pthread_mutex_init(&env->mutex_door, NULL) != 0)
		return (1);
	return (0);
}

int	create_thread(t_env *env)
{
	t_philo *tmp1;
	t_philo *tmp2;

	tmp1 = env->p;
	tmp2 = env->p;
	while (tmp1)
	{
		if (pthread_create((&tmp1->thread_philo), NULL, &routine, tmp1) != 0)
			return (1);
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		if (pthread_join((tmp2->thread_philo), NULL) != 0)
			return (1);
		tmp2 = tmp2->next;
	}
	return (0);
}

int	create_env(t_env *env)
{
	gettimeofday(&env->p->time, NULL);
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
	return (0);
}
