/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 11:27:35 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/12 12:21:13 by cblonde          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

/* structs */
struct	s_data;
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	death;
	pthread_mutex_t	write;
}	t_data;

/*  Parsing */
void		ft_init_data(t_data *data);
void		ft_init_philo(t_data *data);
int			ft_check_args(int argc, char *argv[], t_data *data);
void		ft_join_thread(t_data *data);
void		ft_run_thread(t_data *data);

/* utils */
size_t		ft_strlen(char *str);
long long	ft_atol(char *str);
void		ft_putendl_fd(char *str, int fd);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_get_current_time(void);
int			ft_usleep(size_t time_to_wait);

/* routine */
void		*ft_routine(void *ptr);
void		ft_watch_philo(t_data *data);
void		ft_print(t_data *data, int nbr, char *str);

/* error */
int			ft_error_main(int n);
void		ft_error_parse(int n);

/* free struct */
void		ft_free_data(t_data *data);

#endif
