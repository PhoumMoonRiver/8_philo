/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/25 14:07:28 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *tmp_input)
{
	t_philo *tmp;

	tmp = (t_philo *)tmp_input;
// pthread_mutex_lock(&tmp->mutex_fork);
	printf("This is id => [%d]\n", tmp->id);
	routine_eat(tmp);
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
		if (pthread_mutex_init(&tmp->mutex_door, NULL) != 0)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	create_multi_thread(t_env *env)
{
	t_philo *tmp1;
	t_philo *tmp2;

	tmp1 = env->p;
	tmp2 = env->p;
	while (tmp1)
	{
		if (pthread_create((&tmp1->thread_philo), NULL, &routine, tmp1) != 0)
			return (1);
		usleep(10);
		if (!tmp1->next)
			break ;
		tmp1 = tmp1->next->next;
	}
	usleep(50);
	tmp2 = tmp2->next;
	while (tmp2)
	{
		if (pthread_create((&tmp2->thread_philo), NULL, &routine, tmp2) != 0)
			return (1);
		usleep(10);
		tmp2 = tmp2->next->next;
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
