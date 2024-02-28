/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:35 by cblonde           #+#    #+#             */
/*   Updated: 2024/02/28 18:41:37 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>

/*  Parsing */
int		ft_check_args(int argc, char *argv[]);

/* error */
int		ft_error_main(int n);
void	ft_error_parse(int n);

#endif
