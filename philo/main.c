/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/11 17:33:30 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_init_data(&data);
	if (ft_check_args(argc, argv, &data))
		return (ft_error_main(0));
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
