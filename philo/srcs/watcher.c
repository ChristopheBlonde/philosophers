/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   watcher.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 13:38:55 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/11 17:55:54 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_handle_finish(t_data *data)
{
	//size_t	i;

	//i = 0;
	pthread_mutex_lock(&data->death);
	data->finish = 1;
	pthread_mutex_unlock(&data->death);
	/*while (i < (size_t)data->nbr_philo)
	{
		pthread_mutex_lock(&data->status);
		data->philo[i].status = -1;
		pthread_mutex_unlock(&data->status);
		i++;
	}*/
}

void	ft_watch_philo(t_data *data)
{
	size_t	count;
	size_t	i;

	while (1)
	{
		i = -1;
		count = 0;
		while (++i < (size_t)data->nbr_philo)
		{
			printf("lastmeal:%ld, die:%ld\n", ft_get_current_time() - data->philo[i].last_meal, data->time_die);
			pthread_mutex_lock(&data->meal);
			if (data->nbr_eat != -1 && data->philo[i].nbr_meal >= data->nbr_eat)
				count++;
			if (ft_get_current_time() - data->philo[i].last_meal > data->time_die)
			{
				pthread_mutex_unlock(&data->meal);
				ft_print(data, i + 1, "died");
				return (ft_handle_finish(data));
			}
			pthread_mutex_unlock(&data->meal);
		}
		if (count == (size_t)data->nbr_philo)
			return (ft_handle_finish(data));
	}
}
