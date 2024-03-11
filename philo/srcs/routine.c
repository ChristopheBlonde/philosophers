/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:18:44 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/11 17:58:01 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(t_data *data, int nbr, char *str)
{
	pthread_mutex_lock(&data->death);
	if (!data->finish)
	{
		pthread_mutex_lock(&data->write);
		printf("%ld %d %s\n", ft_get_current_time()
			- data->philo[nbr - 1].start, nbr, str);
		pthread_mutex_unlock(&data->write);
	}
	pthread_mutex_unlock(&data->death);
}

static void	ft_start_eat(t_data *data, t_philo *philo)
{
	int	nbr;

	if (philo->nbr != 1)
		nbr = philo->nbr - 2;
	else
		nbr = data->nbr_philo - 1;
	pthread_mutex_lock(&data->forks[philo->nbr - 1]);
	ft_print(data, philo->nbr, "has taken a fork");
	pthread_mutex_lock(&data->forks[nbr]);
	ft_print(data, philo->nbr, "has taken a fork");
	pthread_mutex_lock(&data->meal);
	philo->last_meal = ft_get_current_time();
	philo->nbr_meal += 1;
	pthread_mutex_unlock(&data->meal);
	ft_print(data, philo->nbr, "is eating");
	ft_usleep(data->time_eat);
	pthread_mutex_unlock(&data->forks[nbr]);
	pthread_mutex_unlock(&data->forks[philo->nbr - 1]);
	pthread_mutex_lock(&data->status);
	philo->status = 1;
	pthread_mutex_unlock(&data->status);
}

static void	ft_start_sleep(t_data *data, t_philo *philo)
{
	ft_print(data, philo->nbr, "is sleeping");
	ft_usleep(data->time_sleep);
	pthread_mutex_lock(&data->status);
	philo->status = 2;
	pthread_mutex_unlock(&data->status);
}

static void	ft_start_think(t_data *data, t_philo *philo)
{
	int	nbr;

	if (philo->nbr != 1)
		nbr = philo->nbr - 2;
	else
		nbr = data->nbr_philo - 1;
	ft_print(data, philo->nbr, "is thinking");
	//usleep(500);
	while (1)
	{
		pthread_mutex_lock(&data->status);
		if (data->philo[nbr].status == 0)
		{
			pthread_mutex_unlock(&data->status);
			break ;
		}
		pthread_mutex_unlock(&data->status);
		usleep(250);
	}
	pthread_mutex_lock(&data->status);
	philo->status = 0;
	pthread_mutex_unlock(&data->status);
}

void	*ft_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	data = (t_data *)philo->data;
	while (1)
	{
		pthread_mutex_lock(&data->death);
		if (data->finish)
		{
			pthread_mutex_unlock(&data->death);
			break ;
		}
		pthread_mutex_unlock(&data->death);
		if (philo->status == 0)
			ft_start_eat(data, philo);
		if (philo->status == 1)
			ft_start_sleep(data, philo);
		if (philo->status == 2)
			ft_start_think(data, philo);
	}
	return (NULL);
}
