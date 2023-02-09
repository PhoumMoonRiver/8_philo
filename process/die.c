/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:10:42 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/09 15:17:34 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*check_die(void *p)
{
	t_philo *tmp;

	tmp = (t_philo *)p;
	while (1)
	{
		while (tmp)
		{
			if (tmp->alive == 1)
				break ;
			tmp = tmp->next;
		}
	}
	return (NULL);
}
