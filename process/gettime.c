/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: njerasea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 20:36:10 by njerasea          #+#    #+#             */
/*   Updated: 2023/01/24 17:19:09 by njerasea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

long long	ft_gettime(t_philo *p)
{
	struct timeval gettime;
	long long time;

	gettimeofday(&gettime, NULL);
	time = (gettime.tv_sec * 1000) + (gettime.tv_usec / 1000);
	return (time - ((p->time.tv_sec * 1000) + (p->time.tv_usec / 1000)));
}
