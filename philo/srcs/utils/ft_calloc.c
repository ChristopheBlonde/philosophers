/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:51:44 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/04 14:32:07 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	total;

	if (!count || !size)
	{
		result = (void *)malloc(1);
		if (!result)
			return (NULL);
		*((unsigned char *)result) = '\0';
		return (result);
	}
	total = count * size;
	if (total / count != size)
		return (NULL);
	result = (void *)malloc(total);
	if (!result)
		return (NULL);
	memset(result, '\0', total);
	return (result);
}
