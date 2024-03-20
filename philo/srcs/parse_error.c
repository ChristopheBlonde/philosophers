/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:10:57 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/20 10:47:29 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error_main(int n)
{
	if (n == 0)
	{
		ft_putendl_fd("\033[1;36mUsage: philo [[number of philosopher] \
[time to die] [time to eat] [time to sleep] [number of times each \
philosopher must eat]]\033[m", 2);
		return (1);
	}
	if (n == 1)
		ft_putendl_fd("\033[0;31mError: Arguments number can not \
be 0\033[m", 2);
	if (n == 2)
		ft_putendl_fd("\033[0;31mError: Arguments number must greater than \
60ms\033[m", 2);
	if (n == 3)
		ft_putendl_fd("\033[0;31mError: Arguments value must \
be int size\033[m", 2);
	return (0);
}

void	ft_error_parse(int n)
{
	if (n == 0)
		ft_putendl_fd("\033[0;31mError: Arguments number\033[m", 2);
	if (n == 1)
		ft_putendl_fd("\033[0;31mError: Bad character in argument\033[m", 2);
	if (n == 2)
		ft_putendl_fd("\033[0;31mError: Argument too long\033[m", 2);
	if (n == 3)
		ft_putendl_fd("\033[0;31mError: Arguments must be positive\033[m", 2);
}

int	ft_error_init(int n)
{
	ft_putendl_fd("\033[0;31mError \033[m", 2);
	if (n == 1)
	{
		ft_putendl_fd("\033[0;31mNumber of meal must be greater zero\033[m", 2);
	}
	return (0);
}
