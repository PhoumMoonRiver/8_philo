/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 20:59:48 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 22:01:42 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_env	env;

	if ((ac == 5 || ac == 6) && argument_check(ac, av) == 0)
	{
		keep_input_to_list(ac, av, &env);
		if (create_env(&env) == 1)
			ft_free_list(&env);
		else
			ft_free_list(&env);
	}
	else
		printf("input not correct\n");
	return (0);
}
