/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 15:32:21 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/11 16:15:45 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	creat_philo(int ac, char **av, t_env *env)
{
(void)ac;
	env->p = (t_philo *)malloc(sizeof(t_philo));
	if (!env->p)
		return ;
	env->n_philo = atoi(av[1]);
	env->i = 1;
exit(0);
/*
	while (env->i <= env->n_philo)
	{
		env->
		env->i++;
	}
*/
}
