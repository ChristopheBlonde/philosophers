/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:16:32 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/04 11:23:03 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_data(t_data *data)
{
	data->nbr_philo = -1;
	data->nbr_eat = -1;
	data->time_eat = -1;
	data->time_sleep = -1;
	data->time_die = -1;
}
