/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:43:13 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/21 19:08:02 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_digit(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	argument_check(int ac, char **av)
{
	int	i;

	i = 2;
	if (check_digit(av) != 0)
		return (0);
	if (ft_atoi(av[1]) <= 0)
		return (0);
	while (i < ac)
	{
		if (ft_atoi(av[i]) < 0)
			return (0);
		i++;
	}
	return (1);
}
