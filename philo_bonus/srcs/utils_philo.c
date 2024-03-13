/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 13:18:53 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/13 20:13:44 by cblonde          ###   ########.fr       */
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
	ft_print(philo, "is eating", "\033[0;35m");
}

static void	*ft_death_checker(void *philo)
{
	(void)philo;
	printf("checker\n");
	return (NULL);
}

static void	ft_routine(t_philo *philo)
{
	t_philo p = *philo;
	if (philo->data->philo)
		free(philo->data->philo);
	while (1)
	{
		if (p.data->finish)
			exit(0);
		ft_is_eating(&p);
		ft_print(&p, "is sleeping", "\033[1;36m");
		ft_usleep(p.data->time_sleep);
		ft_print(&p, "is thinking", "\033[0;33m");
		//ft_free_struct(philo->data);
		ft_free_struct(p.data);
		exit(0);
	}
	exit(1);
}

int	ft_init_philo(t_data *data)
{
	size_t i;

	i = 0;
	if(ft_init_sem(data))
		return (1);
	while (i < (size_t)data->nbr_philo)
	{
		data->philo[i].data = data;
		data->philo[i].nbr = i + 1;
		data->philo[i].start = ft_get_current_time();
		data->philo[i].last_meal = 0;
		data->philo[i].nbr_meal = 0;
		pthread_create(&data->philo[i].check_death,
			NULL, ft_death_checker, &data->philo[i]);
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
