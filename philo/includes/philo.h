/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:53:29 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/06 11:30:43 by nzharkev         ###   ########.fr       */
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
	pthread_mutex_t	*forks;
	pthread_mutex_t	*locks;
	long			start;
}	t_data;

	/*init.c*/

t_data	*init_data(int num, char **values);

	/*error.c*/

int	informer(void);
#endif
