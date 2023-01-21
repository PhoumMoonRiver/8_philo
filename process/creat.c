/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/20 16:41:35 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.c"

void	creat_thread(t_env *env)
{
	env->i = 0;
	while (env->i < env->n_philo)
	{
		env->thread = (pthread_t *)malloc(sizeof(t_philo));
		if (!env->thread)
			return ;
		
	}
}

void	creat_env(t_env *env)
{
	creat_thread(env);
}
