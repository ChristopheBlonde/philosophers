/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:25:30 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/04 15:40:27 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *ptr)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)ptr;
	data = (t_data *)philo->data;
	printf("philo nbr:%d, philo_id: %ld, nbr_eat,%d\n", philo->nbr, philo->id, data->nbr_eat);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	ft_init_data(&data);
	if (ft_check_args(argc, argv, &data))
		return (ft_error_main(0));
	data.philo = (t_philo *)ft_calloc(data.nbr_philo + 1, sizeof(t_philo));
	while (i < data.nbr_philo)
	{
		printf("index:%d\n", i);
		data.philo[i].nbr = i + 1;
		data.philo[i].data = &data;
		pthread_create(&data.philo[i].id, NULL, &ft_routine, &data.philo[i]);
		sleep(2);
		i++;
	}
	return (0);
}
