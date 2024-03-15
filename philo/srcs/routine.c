/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:18:44 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/15 12:41:36 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_data *data, int nbr, char *str, char *color)
{
	pthread_mutex_lock(&data->death);
	if (!data->finish)
	{
		pthread_mutex_lock(&data->write);
		printf("%s%ld %d %s\n", color, ft_get_current_time()
			- data->philo[nbr - 1].start, nbr, str);
		pthread_mutex_unlock(&data->write);
	}
	pthread_mutex_unlock(&data->death);
}

static void	ft_start_eat(t_data *data, t_philo *philo)
{
	int	nbr;

	if (philo->nbr != data->nbr_philo)
		nbr = philo->nbr;
	else
		nbr = 0;
	pthread_mutex_lock(&data->forks[philo->nbr - 1]);
	ft_print(data, philo->nbr, "has taken a fork", "\033[0;35m");
	if (data->nbr_philo == 1)
	{
		pthread_mutex_unlock(&data->forks[philo->nbr - 1]);
		return ;
	}
	pthread_mutex_lock(&data->forks[nbr]);
	ft_print(data, philo->nbr, "has taken a fork", "\033[0;35m");
	pthread_mutex_lock(&data->meal);
	philo->last_meal = ft_get_current_time();
	philo->nbr_meal += 1;
	pthread_mutex_unlock(&data->meal);
	ft_print(data, philo->nbr, "is eating", "\033[0;34m");
	ft_usleep(data->time_eat);
	pthread_mutex_unlock(&data->forks[nbr]);
	pthread_mutex_unlock(&data->forks[philo->nbr - 1]);
}

static void	ft_start_sleep(t_data *data, t_philo *philo)
{
	ft_print(data, philo->nbr, "is sleeping", "\033[1;36m");
	ft_usleep(data->time_sleep);
}

void	*ft_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	data = (t_data *)philo->data;
	if (philo->nbr % 2)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(&data->death);
		if (data->finish)
		{
			pthread_mutex_unlock(&data->death);
			return (NULL);
		}
		pthread_mutex_unlock(&data->death);
		ft_start_eat(data, philo);
		if (data->nbr_philo == 1)
			break ;
		ft_start_sleep(data, philo);
		ft_print(data, philo->nbr, "is thinking", "\033[0;33m");
	}
	return (NULL);
}
