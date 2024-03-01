/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:32:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/01 11:32:37 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_character(char *str)
{
	int	len;
	int	i;

	i = 0;
	while (str[i] == '0' || (9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+')
		i++;
	if (!('0' <= str[i] && str[i] <= '9'))
		return (0);
	len = ft_strlen(&str[i]);
	if (len > 11)
		return (0);
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 6 && argc != 5)
	{
		ft_error_parse(0);
		return (1);
	}
	while (i < argc)
	{
		if (!ft_check_character(argv[i]))
			return (1);
		i++;
	}
	return (0);
}
