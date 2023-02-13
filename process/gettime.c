/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:36:10 by njerasea          #+#    #+#             */
/*   Updated: 2023/02/13 21:25:43 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long	ft_gettime_in_time(void)
{
	struct timeval	gettime;

	gettimeofday(&gettime, NULL);
	return ((gettime.tv_sec * 1000) + (gettime.tv_usec / 1000));
}

void	ft_usleep_get_die(int time)
{
	long	get_time;

	get_time = ft_gettime_in_time();
	while (ft_gettime_in_time() - get_time < (long)time)
		usleep(500);
}

long	ft_gettime(t_philo *p)
{
	long	time;

	time = ft_gettime_in_time();
	return (time - ((p->time.tv_sec * 1000) + (p->time.tv_usec / 1000)));
}
