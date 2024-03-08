/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:18:44 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/08 19:00:10 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_data *data, int nbr, char *str)
{
	pthread_mutex_lock(&data->write);
	printf("%ld %d %s\n", ft_get_current_time(), nbr, str);
	pthread_mutex_unlock(&data->write);
}

void	*ft_routine_part_one(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	data = (t_data *)philo->data;
//	while (philo->nbr_meal != data->nbr_eat)
//	{
		if (philo->nbr % 2 == 0)
			ft_print(data, philo->nbr, "is even");
//	}
	return (NULL);
}
