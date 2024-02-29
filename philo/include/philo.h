/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:35 by cblonde           #+#    #+#             */
/*   Updated: 2024/02/29 14:27:25 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>

/* structs */
typedef struct s_data
{
	int nbr_philo;
	int	nbr_eat;
}	t_data;

/*  Parsing */
int			ft_check_args(int argc, char *argv[]);

/* utils */
size_t		ft_strlen(char *str);
long long	ft_atol(char *str);

/* error */
int			ft_error_main(int n);
void		ft_error_parse(int n);

#endif
