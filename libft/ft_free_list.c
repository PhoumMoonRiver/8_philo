/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 06:11:05 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 20:58:58 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_free_list(t_env *env)
{
	int		i;
	t_philo	*first;

	i = 1;
	if (env->p)
	{
		while (i <= env->n_philo)
		{
			first = env->p->next;
			free (env->p);
			if (!env->p)
				break ;
			env->p = first;
			i++;
		}
	}
	return (0);
}
