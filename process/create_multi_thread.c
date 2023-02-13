/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_multi_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:09:47 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 21:17:14 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	create_ood(t_env *env)
{
	t_philo	*tmp1;

	tmp1 = env->p;
	env->i = 1;
	while (env->i <= env->n_philo)
	{
		if (pthread_create((&tmp1->thread_philo), NULL, &routine, tmp1) != 0)
			return (1);
		usleep(5);
		tmp1 = tmp1->next->next;
		env->i += 2;
	}
	return (0);
}

int	create_even(t_env *env)
{
	t_philo	*tmp2;

	tmp2 = env->p;
	tmp2 = tmp2->next;
	while (env->i <= env->n_philo)
	{
		if (pthread_create((&tmp2->thread_philo), NULL, &routine, tmp2) != 0)
			return (1);
		usleep(5);
		tmp2 = tmp2->next->next;
		env->i += 2;
	}
	return (0);
}

int	create_multi_thread(t_env *env)
{
	if (create_ood(env) == 1)
		return (1);
	env->i = 2;
	usleep(50);
	if (create_even(env) == 1)
		return (1);
	return (0);
}
