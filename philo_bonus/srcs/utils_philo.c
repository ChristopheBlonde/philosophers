/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:18:53 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/15 12:36:31 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(t_philo *philo, char *str, char *color)
{
	sem_wait(philo->data->write);
	printf("%s%ld %d %s\033[m\n", color, ft_get_current_time()
		- philo->start, philo->nbr, str);
	sem_post(philo->data->write);
}

static void	ft_is_eating(t_philo *philo)
{
	sem_wait(philo->data->forks);
	ft_print(philo, "has taken a fork", "\033[1;35m");
	sem_wait(philo->data->forks);
	ft_print(philo, "has taken a fork", "\033[1;35m");
	ft_print(philo, "is eating", "\033[0;35m");
	sem_wait(philo->data->meal);
	philo->last_meal = ft_get_current_time();
	philo->nbr_meal += 1;
	sem_post(philo->data->meal);
	ft_usleep(philo->data->time_eat);
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

static void	*ft_death_checker(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		sem_wait(p->data->meal);
		if (ft_get_current_time() - p->last_meal
			> p->data->time_die)
		{
			sem_wait(p->data->died);
			p->data->finish = 1;
			sem_post(p->data->died);
			ft_print(philo, "died", "\033[0;31m");
			sem_wait(p->data->write);
			exit (1);
		}
		if (p->nbr_meal == p->data->nbr_eat)
		{
			sem_post(p->data->meal);
			break ;
		}
		sem_post(p->data->meal);
		usleep(1000);
	}
	return (NULL);
}

static void	ft_routine(t_philo *philo)
{
	philo->last_meal = ft_get_current_time();
	pthread_create(&philo->check_death,
		NULL, ft_death_checker, philo);
	if (philo->nbr % 2)
		usleep(100);
	while (1)
	{
		if (philo->nbr_meal > 0 && philo->nbr == 1)
			usleep(100);
		sem_wait(philo->data->died);
		if (philo->data->finish)
			break ;
		sem_post(philo->data->died);
		ft_is_eating(philo);
		if (philo->nbr_meal == philo->data->nbr_eat)
			break ;
		ft_print(philo, "is sleeping", "\033[1;36m");
		ft_usleep(philo->data->time_sleep);
		ft_print(philo, "is thinking", "\033[0;33m");
	}
	pthread_join(philo->check_death, NULL);
	exit(0);
}

int	ft_init_philo(t_data *data)
{
	size_t	i;

	i = 0;
	if (ft_init_sem(data))
		return (1);
	while (i < (size_t)data->nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].nbr = i + 1;
		data->philo[i].start = ft_get_current_time();
		data->philo[i].last_meal = 0;
		data->philo[i].nbr_meal = 0;
		data->philo[i].id = fork();
		if (data->philo[i].id < 0)
			return (1);
		if (data->philo[i].id == 0)
			ft_routine(&(data->philo[i]));
		usleep(1);
		i++;
	}
	return (0);
}
