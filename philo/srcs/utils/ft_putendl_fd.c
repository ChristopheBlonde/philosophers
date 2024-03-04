/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:57:27 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/04 10:01:42 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_putendl_fd(char *str, int fd)
{
	int	len;

	if (!str || !fd)
		return ;
	len = ft_strlen(str);
	write(fd, str, len);
	write(fd, "\n", 1);
}
