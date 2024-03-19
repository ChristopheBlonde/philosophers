/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:13:21 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/18 15:03:49 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	ft_init_data(&data);
	if (ft_check_args(argc, argv, &data))
		return (ft_error_main(0));
	data.philo = ft_calloc(data.nbr_philo + 1, sizeof(t_philo));
	if (!data.philo)
		return (1);
	if (ft_init_philo(&data))
		return (ft_error_init(&data, 0));
	ft_free_struct(&data);
	return (0);
}
