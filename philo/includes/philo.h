/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:29 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/08 15:52:41 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_philo
{
	int				id;
	int				meals;
	size_t			last_meal;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	struct s_data	*data;
} t_philo;

typedef struct s_data
{
	int				num_philo;
	size_t			time_death;
	size_t			time_eat;
	size_t			time_sleep;
	int				meals;
	int				running;
	size_t			start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
}	t_data;

	/*actions.c*/

int		eat(t_philo *philo);
int		time_to_sleep(t_philo *philo);

	/*cleaners.c*/

void	cleaner(t_data *data);
void	unite_in_peace(t_data *data);

	/*error.c*/

void	informer(void);
int		the_end(t_philo *philo);

	/*init.c*/

t_data	*init_data(int num, char **values);

	/*routine.c*/

void	cycle_of_extistence(t_data *data);

	/*simulation.c*/

void	create_simulation(t_data *data);
int		standby_of_reason(t_philo *philo, size_t ms);

	/*utils.c*/

int		str_to_int(char *str);
size_t	what_time(void);
void	document_moment(t_philo *philo, char *msg, int flg);

#endif
