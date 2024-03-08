/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:38:58 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/08 19:04:36 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_philo(t_data *data, int index)
{
	data->philo[index].nbr = index + 1;
	data->philo[index].data = data;
	data->philo[index].start = ft_get_current_time();
	data->philo[index].status = 0;
	pthread_mutex_init(&data->forks[index], NULL);
	pthread_create(&data->philo[index].id, NULL,
		&ft_routine_part_one, &data->philo[index]);
	usleep(1);
}
