/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:32:47 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/12 18:12:14 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static char	*ft_strtrim(char *str)
{
	char	*result;
	int		i;
	int		j;

	j = 0;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '+')
		str++;
	while (*str == '0')
		str++;
	i = ft_strlen(str) - 1;
	while (str[i] == ' ' || (9 <= str[i] && str[i] <= 13))
		i--;
	result = (char *)ft_calloc(i + 2, sizeof(char));
	if (!result)
		return (NULL);
	while (j <= i)
	{
		result[j] = str[j];
		j++;
	}
	return (result);
}

static int	ft_check_character(char *str)
{
	int	len;
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		ft_error_parse(3);
		return (0);
	}
	while (str[i])
	{
		if (!('0' <= str[i] && str[i] <= '9'))
		{
			ft_error_parse(1);
			return (0);
		}
		i++;
	}
	len = ft_strlen(str);
	if (len > 10)
	{
		ft_error_parse(2);
		return (0);
	}
	return (1);
}

static int	ft_check_value(t_data *data, char *value, int index)
{
	long long	nbr;

	nbr = ft_atol(value);
	if (nbr == 0 && index != 5)
		return (ft_error_main(1));
	if (nbr < 60 && index > 1 && index != 5)
		return (ft_error_main(2));
	if (nbr > 2147483647)
		return (ft_error_main(3));
	if (index == 1)
		data->nbr_philo = nbr;
	if (index == 2)
		data->time_die = nbr;
	if (index == 3)
		data->time_eat = nbr;
	if (index == 4)
		data->time_sleep = nbr;
	if (index == 5)
		data->nbr_eat = nbr;
	return (1);
}

int	ft_check_args(int argc, char *argv[], t_data *data)
{
	int		i;
	char	*tmp;

	i = 1;
	if (argc != 6 && argc != 5)
	{
		ft_error_parse(0);
		return (1);
	}
	while (i < argc)
	{
		tmp = ft_strtrim(argv[i]);
		if (!tmp)
			return (1);
		if (!ft_check_character(tmp) || !ft_check_value(data, tmp, i))
		{
			free(tmp);
			return (1);
		}
		free(tmp);
		i++;
	}
	return (0);
}
