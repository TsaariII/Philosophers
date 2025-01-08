/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:29 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/07 16:15:07 by nzharkev         ###   ########.fr       */
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
	int		id;
	int		meals;
	long	last_meal;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	struct s_data	*data;

} t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_death;
	int				time_eat;
	int				time_sleep;
	int 			meals;
	int				running;
	int				start;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
}	t_data;

	/*error.c*/

int	informer(void);

	/*init.c*/

t_data	*init_data(int num, char **values);

	/*simulation.c*/

int	to_simulation(t_data *data);

	/*utils.c*/
int	str_to_int(char *str);
int	is_this_sign(char *str);
int	only_digit(char c);

#endif
