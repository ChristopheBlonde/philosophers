/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/08 14:49:43 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
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
	while (i < data.nbr_philo)
	{
		ft_init_philo(&data, i);
		i++;
	}
	i = 0;
	while (i < data.nbr_philo)
	{
		pthread_join(data.philo[i].id, NULL);
		i++;
	}
	ft_free_data(&data);
	return (0);
}
