/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/12 12:55:15 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static	int	ft_one_philo(t_data *data)
{
	printf("0 1 has taken a fork\n");
	ft_usleep(data->time_die);
	printf("%ld 1 died\n", data->time_die);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (ft_check_args(argc, argv, &data))
		return (ft_error_main(0));
	if (data.nbr_philo == 1)
		return (ft_one_philo(&data));
	data.philo = ft_calloc(data.nbr_philo + 1, sizeof(t_philo));
	if (!data.philo)
		return (1);
	data.forks = ft_calloc(data.nbr_philo + 1, sizeof(pthread_mutex_t));
	if (!data.forks)
	{
		free(data.philo);
		return (1);
	}
	ft_init_philo(&data);
	ft_run_thread(&data);
	ft_watch_philo(&data);
	ft_join_thread(&data);
	ft_free_data(&data);
	return (0);
}
