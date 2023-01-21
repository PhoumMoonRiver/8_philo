/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/21 20:40:47 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(void *env_input)
{
	t_env *env;

	env = (t_env *)env_input;
	pthread_mutex_lock(&env->p->my_mutex);
env->i++;
printf("This is ==> [%d]\n", env->i);
	pthread_mutex_unlock(&env->p->my_mutex);
	return (NULL);
} 

void	creat_mutex(t_env *env)
{
	t_philo *tmp;

	tmp = env->p;
	while (tmp)
	{
		pthread_mutex_init(&tmp->my_mutex, NULL);
		tmp = tmp->next;
	}
}

void	creat_thread(t_env *env)
{
	t_philo *tmp1;
	t_philo *tmp2;
env->i = 0;
	tmp1 = env->p;
	tmp2 = env->p;
	creat_mutex(env);
	while (tmp1)
	{
		if (pthread_create((&tmp1->my_thread), NULL, &routine, env) != 0)
			return ;
		tmp1 = tmp1->next;
	}
	while (tmp2)
	{
		if (pthread_join((tmp2->my_thread), NULL) != 0)
			return ;
		tmp2 = tmp2->next;
	}
}

void	creat_env(t_env *env)
{
	creat_thread(env);
}
