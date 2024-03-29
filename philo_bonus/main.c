/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:13:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/20 10:12:56 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*ft_kill(void *data)
{
	t_data	*d;
	int		i;

	d = (t_data *)data;
	i = 0;
	sem_wait(d->kill);
	while (i < d->nbr_philo)
	{
		if (d->philo[i].id)
			kill(d->philo[i].id, 9);
		i++;
	}
	return (NULL);
}

static void	ft_wait_pid(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nbr_philo)
	{
		wait(&data->philo[i].id);
		i++;
	}
	sem_post(data->kill);
}

int	main(int argc, char *argv[])
{
	t_data		data;
	pthread_t	kill;

	ft_init_data(&data);
	if (ft_check_args(argc, argv, &data))
		return (ft_error_main(0));
	data.philo = ft_calloc(data.nbr_philo + 1, sizeof(t_philo));
	if (!data.philo)
		return (1);
	if (ft_init_sem(&data))
		return (2);
	pthread_create(&kill, NULL, ft_kill, &data);
	if (ft_init_philo(&data))
		return (ft_error_init(&data, 0));
	ft_wait_pid(&data);
	pthread_join(kill, NULL);
	ft_free_struct(&data);
	return (0);
}
