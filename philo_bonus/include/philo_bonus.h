/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:00:48 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/12 18:27:03 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

/* struct */
typedef struct s_philo
{
	struct s_data	*data;
	pthread_t		id;
	int				nbr;
	size_t			start;
	size_t			last_meal;
	int				nbr_meal;
}	t_philo;

typedef struct s_data
{
	int				nbr_philo;
	int				nbr_eat;
	size_t			time_eat;
	size_t			time_sleep;
	size_t			time_die;
	int				finish;
	t_philo			*philo;
}	t_data;

/* utils */
size_t		ft_strlen(char *str);
long long	ft_atol(char *str);
void		ft_putendl_fd(char *str, int fd);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_get_current_time(void);
int			ft_usleep(size_t time_to_wait);

/* Error */
int			ft_error_main(int n);
void		ft_error_parse(int n);
#endif
