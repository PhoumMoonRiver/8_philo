/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:06:14 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/21 12:58:49 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_env	env;

	if ((ac == 5 || ac == 6) && argument_check(ac, av) != 0)
	{
		keep_input_to_list(ac, av, &env);
		creat_env(&env);
	}
	else
		printf("input not correct\n");
	return (0);
}
