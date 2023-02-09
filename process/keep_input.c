/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:17:26 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 15:07:47 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_list_of_philo(int ac, char **av, t_env *env)
{
	env->p->id = env->i;
	env->p->alive = 0;
	env->p->t_die = atoi(av[2]);
	env->p->t_eat = atoi(av[3]);
	env->p->t_sleep = atoi(av[4]);
	if (ac == 6)
		env->p->r_eat = atoi(av[5]);
	else
		env->p->r_eat = -1;
	env->p->fork_right = env->p->id;
	if (env->p->id == atoi(av[1]))
		env->p->fork_left = 1;
	else
		env->p->fork_left = env->p->id + 1;
}

void	keep_input_to_list(int ac, char **av, t_env *env)
{
	t_philo *first;
	t_philo *past;

	env->n_philo = ft_atoi(av[1]);
	env->i = 1;
	while (env->i <= env->n_philo)
	{
		env->p = (t_philo *)malloc(sizeof(t_philo));
		if (!env->p)
			return ;
		init_list_of_philo(ac, av, env);
		if (env->i == 1)
		{
			env->p->head = 1;
			first = env->p;
			past = env->p;
		}
		env->p->head = 0;
		past->next = env->p;
		env->p->next = first;
		past = env->p;
		env->i++;
	}
	env->p = first;
}
