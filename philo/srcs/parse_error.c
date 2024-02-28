/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:10:57 by cblonde           #+#    #+#             */
/*   Updated: 2024/02/28 18:44:46 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_main(int n)
{
	if (n == 0)
	{
		write(2, "\033[1;36mUsage: philo [[number of philosopher] [time to die] \
[time to eat] [time to sleep] [number of times each \
philosopher must eat]]\n", 135);
		return (1);
	}
	return (0);
}

void	ft_error_parse(int n)
{
	if (n == 0)
		write(2, "\033[0;31mError: arguments number\n", 32);
}
