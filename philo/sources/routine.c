/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nzharkev <nzharkev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:01:28 by nzharkev          #+#    #+#             */
/*   Updated: 2025/01/14 10:15:37 by nzharkev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int standby_of_reason(t_philo *philo, size_t ms)
{
	size_t	time;

	time = what_time();
	while ((what_time() - time) < ms)
	{
		usleep(100);
		if (the_end(philo))
			return (1);
	}
	return (0);
}

void	no_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		document_moment(philo, "is thinking", 0);
		standby_of_reason(philo, philo->data->time_eat / 2);
	}
}

void	just_one(t_philo *philo)
{
	size_t time;

	pthread_mutex_lock(philo->l_fork);
	time = philo->data->start;
	printf("%zu %d has taken a fork\n", what_time() - time, 1);
	standby_of_reason(&philo->data->philos[0], philo->data->time_death);
	pthread_mutex_unlock(philo->l_fork);
}

void	*day(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&philo->data->lock);
	pthread_mutex_unlock(&philo->data->lock);
	if (philo->data->num_philo == 1)
	{
		just_one(philo);
		return (philo);
	}
	no_fork(philo);
	while (!the_end(philo))
	{
		if (eat(philo))
			break ;
		if (went_to_bed(philo))
			break ;
		if (!the_end(philo))
			document_moment(philo, "is thinking", 0);
		else
			break ;
	}
	return (philo);
}

void	create_simulation(t_data *data)
{
	int	i;

	pthread_mutex_lock(&data->lock);
	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &day, (void *)&data->philos[i]))
		{
			unite_in_peace(data);
			cleaner(data);
			printf("FAIL\n");
		}
		i++;
	}
	data->start = what_time();
	data->running = 1;
	pthread_mutex_unlock(&data->lock);
}
