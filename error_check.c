/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:43:13 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/07 14:57:08 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	argument_check(int ac, char **av)
{
	int	i;

	i = 2;
	if (ft_atoi(av[1]) <= 0)
		return(0);
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
			return(0);
		i++;
	}
	return(1);
}
