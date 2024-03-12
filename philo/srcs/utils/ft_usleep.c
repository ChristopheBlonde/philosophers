/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 09:15:18 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/12 08:53:39 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		ft_putendl_fd("\033[0;31Error: fail get time", 2);
	return (time.tv_sec * 1000LL + time.tv_usec / 1000);
}

int	ft_usleep(size_t time_to_wait)
{
	size_t	start;

	start = ft_get_current_time();
	while ((ft_get_current_time() - start) < time_to_wait)
		usleep(500);
	return (0);
}
