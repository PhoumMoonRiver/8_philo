/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:31:36 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/21 13:29:04 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine()
{
	printf("Test\n");
	return (NULL);
}

void	creat_thread(t_env *env)
{
	t_philo	*tmp_h;

	//env->tmp_head = env->p;
	tmp_h = NULL;
	tmp_h = env->p;
	//while (env->tmp_head)
	while (tmp_h)
	{
		// if (pthread_create((&env->tmp_head->thread), NULL, &routine, NULL) != 0)
		// 	return ;
		// env->tmp_head = env->tmp_head->next;
		if (pthread_create((&tmp_h->thread), NULL, &routine, NULL) != 0)
			return ;
		tmp_h = tmp_h->next;

	}
	// env->p = env->tmp_head;
	// while (env->p)
	// {
	// 	if (pthread_create((&env->p->thread), NULL, &routine, NULL) != 0)
	// 		return ;
	// 	env->p = env->p->next;
	// }
}

void	creat_env(t_env *env)
{
	creat_thread(env);
}
