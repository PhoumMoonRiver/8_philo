/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:21 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/12 07:57:15 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_philo(int ac, char **av, t_env *env)
{
	t_philo *h;

	h = NULL;
	env->p = (t_philo *)malloc(sizeof(t_philo));
	if (!env->p)
		return ;
	env->n_philo = atoi(av[1]);
	env->i = 1;
	while (env->i <= env->n_philo)
	{
		env->p->next = h;
		init_philo(ac, av, env);
		h = env->p;
printf("===> |%d|\n", h->id);
		env->i++;
	}
	show_philo(env, h);
}

void	init_philo(int ac, char **av, t_env *env)
{
	env->p->id = env->i;
	env->p->t_die = atoi(av[2]);
	env->p->t_eat = atoi(av[3]);
	env->p->t_sleep = atoi(av[4]);
	if (ac == 6)
		env->p->r_eat = atoi(av[5]);
	else
		env->p->r_eat = -1;
	env->p->fork_left = env->p->id - 1;
	if (env->p->id == atoi(av[1]))
		env->p->fork_right = 0;
	else
		env->p->fork_right = env->p->id;
}
