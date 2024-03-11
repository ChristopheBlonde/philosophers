/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:16:32 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/11 17:03:41 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data)
{
	data->finish = 0;
	data->nbr_philo = -1;
	data->nbr_eat = -1;
	data->time_eat = -1;
	data->time_sleep = -1;
	data->time_die = -1;
	data->philo = NULL;
	data->forks = NULL;
	pthread_mutex_init(&data->meal, NULL);
	pthread_mutex_init(&data->death, NULL);
	pthread_mutex_init(&data->status, NULL);
	pthread_mutex_init(&data->write, NULL);
}

void	ft_free_data(t_data *data)
{
	int	i;

	i = 0;
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
	if (data->forks)
	{
		while (i < data->nbr_philo)
		{
			pthread_mutex_destroy(&data->forks[i]);
			i++;
		}
		free(data->forks);
		data->forks = NULL;
	}
	pthread_mutex_destroy(&data->meal);
	pthread_mutex_destroy(&data->death);
	pthread_mutex_destroy(&data->status);
	pthread_mutex_destroy(&data->write);
}
