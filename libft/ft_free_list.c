/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 06:11:05 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/08 21:16:34 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_free_list(t_env *env)
{
	t_philo *first;
	int	i;

	i = 1;
	if (env->p)
	{
		while (i <= env->n_philo)
		{
			first = env->p->next;
			free (env->p);
			env->p = first;
			i++;
		}
	}
	return (0);
}
