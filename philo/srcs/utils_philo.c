/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:38:58 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/11 16:15:55 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_run_thread(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nbr_philo)
	{
		pthread_create(&data->philo[i].id, NULL,
			&ft_routine, &data->philo[i]);
		usleep(1);
		i++;
	}
}

void	ft_init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nbr_philo)
	{
		data->philo[i].nbr = i + 1;
		data->philo[i].data = data;
		data->philo[i].start = ft_get_current_time();
		data->philo[i].last_meal = data->philo[i].start;
		if ((i + 1) % 2 == 0)
			data->philo[i].status = 0;
		else
			data->philo[i].status = 2;
		pthread_mutex_init(&data->forks[i], NULL);
		i++;
	}
}

void	ft_join_thread(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < (size_t)data->nbr_philo)
	{
		pthread_join(data->philo[i].id, NULL);
		i++;
	}
}
