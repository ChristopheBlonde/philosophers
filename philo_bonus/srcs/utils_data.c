/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:04:45 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/14 17:39:06 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_data(t_data *data)
{
	data->nbr_philo = 0;
	data->nbr_eat = -1;
	data->time_eat = 0;
	data->time_sleep = 0;
	data->time_die = 0;
	data->finish = 0;
	data->philo = NULL;
	data->meal = NULL;
	data->write = NULL;
	data->forks = NULL;
	data->died = NULL;
}

int	ft_init_sem(t_data *data)
{
	sem_unlink("/write");
	sem_unlink("/meal");
	sem_unlink("/forks");
	sem_unlink("/died");
	data->write = sem_open("/write", O_CREAT, S_IRWXU, 1);
	data->meal = sem_open("/meal", O_CREAT, S_IRWXU, 1);
	data->forks = sem_open("/forks", O_CREAT, S_IRWXU, data->nbr_philo);
	data->died = sem_open("/died", O_CREAT, S_IRWXU, 1);
	if (!data->write || !data->meal || !data->forks || !data->died)
		return (1);
	return (0);
}

static void	ft_kill_pid(t_data *data)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->nbr_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = 0;
			while (i < data->nbr_philo)
			{
				if (data->philo[i].id)
					kill(data->philo[i].id, 15);
				i++;
			}
			break ;
		}
		i++;
	}
}

void	ft_sem_close(t_data *data)
{
	if (data->meal)
		sem_close(data->meal);
	if (data->write)
		sem_close(data->write);
	if (data->forks)
		sem_close(data->forks);
	if (data->died)
		sem_close(data->died);
	sem_unlink("/meal");
	sem_unlink("/write");
	sem_unlink("/forks");
	sem_unlink("/died");
}

void	ft_free_struct(t_data *data)
{
	ft_sem_close(data);
	ft_kill_pid(data);
	if (data->philo)
	{
		free(data->philo);
		data->philo = NULL;
	}
}
