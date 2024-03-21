/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cblonde <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:00:48 by cblonde           #+#    #+#             */
/*   Updated: 2024/03/21 10:12:54 by cblonde          ###   ########.fr       */
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
# include <fcntl.h>
# include <semaphore.h>
# include <signal.h>
# include <sys/wait.h>

/* struct */
struct	s_data;
typedef struct s_philo
{
	struct s_data	*data;
	pid_t			id;
	int				nbr;
	size_t			last_meal;
	int				nbr_meal;
	pthread_t		check_death;
}	t_philo;

typedef struct s_data
{
	int		nbr_philo;
	int		nbr_eat;
	size_t	time_eat;
	size_t	time_sleep;
	size_t	time_die;
	size_t	start;
	int		finish;
	t_philo	*philo;
	sem_t	*meal;
	sem_t	*write;
	sem_t	*forks;
	sem_t	*died;
	sem_t	*kill;
}	t_data;

/* utils */
size_t		ft_strlen(char *str);
long long	ft_atol(char *str);
void		ft_putendl_fd(char *str, int fd);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_get_current_time(void);
int			ft_usleep(size_t time_to_wait);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);

/* data */
int			ft_check_args(int argc, char *argv[], t_data *data);
void		ft_init_data(t_data *data);
int			ft_init_philo(t_data *data);
int			ft_init_sem(t_data *data);
void		ft_sem_close(t_data *data);

/* Error */
int			ft_error_main(int n);
void		ft_error_parse(int n);
int			ft_error_init(t_data *data, int n);

/* free */
void		ft_free_struct(t_data *data);

#endif
